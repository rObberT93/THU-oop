#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
    string str1 = "abc";
    string str2 = str1;
    // cout << &str1 << endl;
    // cout << &str2 << endl;
    // str1 = "111";
    // cout << str2 << endl;
    const char * str1_copy = str1.c_str();
    char str3[] = "def";
    char* str4 = str3;
    cout << &str3 << endl;
    cout << &str4 << endl;
    str3[0] = 'x';
    // cout << str3 << endl;
    cout << str4 << endl;
}
