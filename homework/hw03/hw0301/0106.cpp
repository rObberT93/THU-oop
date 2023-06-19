#include<iostream>
using namespace std;


class Appearance {
    int weight = 0;
public:
    Appearance(){cout << "apperance1 being constructed" << endl;}
    Appearance(int _w):weight(_w){cout << "apperance2 being constructed" << endl;}
    ~Appearance(){}
};

class Small{
protected:
    Appearance A;
};

class Animal {
protected:
    Appearance A;
public:
    Animal(){cout << "animal1 being constructed" << endl;} // (1)
    Animal(int _w){A = Appearance(_w);cout << "animal2 being constructed" << endl;} // (2)
    ~Animal(){}
};

class Rabbit: public Animal { // (3)
//class Rabbit: public Animal, public Small {
    Animal N{1};
public:
    Rabbit(){cout << "rabbit being constructed" << endl;}
    Appearance getA() {return A;}
    ~Rabbit(){}
};

int main() {
    Rabbit R;
    return 0;
}
