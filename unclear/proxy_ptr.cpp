#include <iostream>
using namespace std;

template <typename T> 
class SmartPtr; //提前声明智能指针模板类

//辅助指针，用于存储指针计数以及封装实际指针地址
template <typename T>
class U_Ptr {
private:
	friend class SmartPtr<T>;
	U_Ptr(T *ptr) : p(ptr), count(1) { }
	~U_Ptr() { delete p; }
  
	int count;   
	T *p; //数据存放地址
};

template <typename T>
class SmartPtr { //智能指针
private:
	U_Ptr<T> *rp;	//进行实际指针操作的辅助指针
public:
	SmartPtr(T *ptr) : rp(new U_Ptr<T>(ptr)) { }
	//调动拷贝构造即增加引用计数
	SmartPtr(const SmartPtr<T> &sp) : rp(sp.rp) { ++rp->count; }
	SmartPtr& operator=(const SmartPtr<T>& rhs) {
		++rhs.rp->count; //赋值号后的指针引用加1
		if (--rp->count == 0) delete rp;	//原内部指针引用减1
		rp = rhs.rp;		//代理新的指针
		return *this;
	}
	~SmartPtr() { //只有引用次数为0才会释放
		if (--rp->count == 0) delete rp;
	}
	//对智能指针操作等同于对内部辅助指针操作
	T& operator *() { return *(rp->p); }
	T* operator ->() { return rp->p; }
};

int main(int argc, char *argv[]) {
	//声明指针
	int *i = new int(2);
	//使用代理来包裹指针
	SmartPtr<int> ptr1(i);
	SmartPtr<int> ptr2(ptr1);
	SmartPtr<int> ptr3 = ptr2;
	//之后的操作均通过代理进行
	cout << *ptr1 << endl;
	*ptr1 = 20;
	cout << *ptr2 << endl;
	return 0;
}