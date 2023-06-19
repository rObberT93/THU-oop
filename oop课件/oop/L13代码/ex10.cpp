#include <memory>
#include <iostream>
using namespace std;

int main()
{
	shared_ptr<int> p1(new int(4));
	cout << p1.use_count() << ' ';
	{
		shared_ptr<int> p2 = p1;
		cout << p1.use_count() << ' ';
		cout << p2.use_count() << ' ';
	}	//p2出作用域
	cout << p1.use_count() << ' ';
}
