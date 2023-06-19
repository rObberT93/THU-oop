#include <iostream>
using namespace std;

class A {
public:
    const char* s;
    A(const char* str) : s(str) { cout << " A: " << str << " is constructing" << endl;}
    ~A() { cout << " A is destructing" << endl; }
};

class B {
public:
    static A a1;
    const A a2;
    B(const char* str) : a2(str) { }
    ~B() { cout << " B is destructing" << endl;  }
};

void foo() {
    static A obj("static obj");
}

A B::a1("static B::a1");  // (1)

int main() {
    // (2)
    //A B::a1("static B::a1");  // (1)
    cout << "main starts" << endl;
    static B b("static b");
    for (int i = 0; i < 4; i++) {
        foo();
    }
    cout << B::a1.s << endl; // (3)
    //cout << b.a1.s << endl;
    cout << "main ends" << endl;
    return 0; // (4)
}
