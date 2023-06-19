#include<iostream>
 using namespace std;

 void f(int& x) {
     x += 1;
     cout << "f(int& x)" << endl;
 }

 void f(int&& x) {
     int& y = x;             // (1)
     const int& z = y + 1;   // (2)
     cout << "3:";f(y);                   // (3)
     cout << "f(int&& x)" << endl;
 }

 int main() {
     int a = 1;
      cout << "4: ";f(a);       // (4)
     cout << "5: ";f(1);       // (5)

     return 0;}
