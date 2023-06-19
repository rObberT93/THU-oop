#include<iostream>
#include<vector>
#include<memory>
using namespace std;
int main() {
    auto p = new char('a');
    shared_ptr<char>p1 (p);
    weak_ptr<char>p2(p1);
    cout << *p1 << endl;
    cout << p2.use_count() << endl;
    auto p3 = p2.lock();
    cout << p2.use_count() << endl;

}