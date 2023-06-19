#include <iostream>
using namespace std;
int arr[5] = { 5, 2, 3, 1, 7 };
void increase(int &x){x++;}
void decrease(int &x){x--;}
int main()
{
	int flag; std::cin >> flag;
	void (*func)(int&); //声明函数指针
	if(flag==1) {func=increase;} else {func=decrease;}
	//auto func = flag==1?increase:decrease; //和上两行效果相同
	for (int &x : arr) { 	func(x); cout << x;}
	return 0;
}
