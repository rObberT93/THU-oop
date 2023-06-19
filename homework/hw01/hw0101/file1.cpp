#include<iostream>
using namespace std;
class A {
    private:
        int data = 1;
        friend void foo(A &a);
};
void foo(A &a) {
    cout << a.data;
}
int main() {
    A a;
    foo(a);
    return 0;
}