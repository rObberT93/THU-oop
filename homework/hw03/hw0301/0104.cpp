#include <iostream>
using namespace std;

class Identity {
    int number = 1;
    int type = 0;
public:
    Identity(){cout << "Identity::Identity()" << endl;}
    Identity(int _t):type(_t){cout << "Identity::Identity(" << type << ")" << endl;}
    Identity(const Identity &other) {
        number = other.number + 1;
        type = other.type;
    }
};

class Appearance {
    double weight = 0;
public:
    Appearance(){cout << "Appearance::Appearance()" << endl;}
    Appearance(double _w):weight(_w){cout << "Appearance::Appearance(" << weight << ")" << endl;}
};

class Animal {
    Identity I;
    Appearance A;
public:
    Animal(int _t, double _w){
        I = Identity(_t);
        A = Appearance(_w);
    }
};

int main(){
    Animal a1(2, 7.5);
    Animal a2(a1);
    return 0;
}
