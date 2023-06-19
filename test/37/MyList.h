#pragma once
#include <list>
#include <memory>
#include <iostream>
using namespace std;
class MyList
{
public:
	static list<int> container; // a pointer to the real container
	list<int>::iterator left, right; // the position of slice is [left, right). 'left' is included, 'right' is excluded.

	list<int>::iterator forward(int pos){
		auto now = left;
		while(pos--) now++;
		return now;
	}

	MyList(){
		left = container.end();
		right = container.end();
	}
    MyList(list<int>::iterator _left, list<int>::iterator _right)
		:left(_left), right(_right) {};

    MyList(const MyList& src) {
        left = src.left;
        right = src.right;
    }

	void append(int i){
		container.insert(right, i); //insert i just before 'right'. 'right' and 'left' will be still valid (because we use list, not vector).
		if(left == right)
			left = container.begin();
	}

	int& operator[](int pos){
		return *forward(pos); // access the element at the 'pos'
	}

	friend ostream& operator<<(ostream& out, const MyList& ml) {
		out << "[";
		if (ml.left != ml.right){
			auto now = ml.left;
			out << *now;
			now ++;
			for(; now != ml.right; now++){
				out << "," << *now;
			}
		}
		out << "]";
		return out;
	}
	MyList operator()(int left_pos, int right_pos) {
		return MyList(forward(left_pos), forward(right_pos));
	}

};
list<int> MyList::container;