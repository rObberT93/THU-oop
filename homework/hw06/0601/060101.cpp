#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
    string s1("abc");
    vector<char> s2 = {'a', 'b', 'c'};
    s1.push_back('d');
    cout << s1 << endl;
    s2.push_back('d');
    // cout << s2 << endl;
}