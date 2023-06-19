#include<iostream>
#include<vector>
#include<list>
#include<memory>
using namespace std;

class base {
public:
    virtual void func() {
        cout << "base" << endl;
    }
    virtual void plus () {
        cout << "base another" << endl;
    }
};

class derived1 : public base {
public:
    void func() {
        cout << "derived1" << endl;
    }
};

class derived2 : public base {
public:
    void func() {
        cout << "derived2" << endl;
    }
};

int main() {
    base *b = new derived1();
    b->func();
    derived1* ptr = dynamic_cast<derived1*>(b);
    ptr->func();
    b = new derived2();
    b->func();
    // b->plus();
    // derived1 *d = new derived1();
    // d->func();
    // d->plus();
    // derived1* ptr = dynamic_cast<derived1*>(b);
    // ptr->func();
}