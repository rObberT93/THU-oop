#include <iostream>
using namespace std;

class MyInt{
public:
    MyInt(int i = 0) : val(i)  // (a)
    {    
        //cout << "in constructor: " ; cout << i; cout << val << endl;
    }
    MyInt(const MyInt& src) : val(src.val)  // (b)
    {  cout << "copy "<< src.val << endl;  }
    MyInt(MyInt&& src) : val(src.val)  // (c)
    {    }
    operator int() const  // (d)
    { 
        return val; 
    }
    MyInt& operator=(MyInt&& rhs)  // (e)
    {
        val = rhs.val;
        return *this;
    }
    MyInt& operator=(const MyInt& rhs)  // (f)
    {
        val = rhs.val;
        return *this;
    }
    int get_value() const
    {
        return val;
    }
private:
    int val;
};

void print(MyInt obj)
{
    cout << obj.get_value() << endl;
}

void print(int value)
{
    cout << value << endl;
}

int main()
{
    MyInt a;
    a = -3.8;  // (1)
    auto b = a + 1;  // (2)
    cout << "3" ;auto c = a;  // (3)
    print(a); print(b); print(c);  // (4)
    return 0;
}
