#include <iostream>
using namespace std;
class A {
public:
    A() { fun(); }
    virtual void fun() {}
    ~A() {}
};

class B : A {
public:
    B() { fun(); }
    void fun() {}
    ~B() {}
};

class C : public B {
public:
    C() { fun(); }
    virtual void fun() {cout << " c fun" << endl;}
    ~C() {cout << "delete c";}
};

int main() {
    B *pb = new C();
    pb->fun();
    delete pb;
    cout << "All done!" << endl;
    return 0;
}
