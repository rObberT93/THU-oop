#include<iostream>
#include"chef.h"
#include"manager.h"
using namespace std;

Chef::Chef(string _name, string _signatureDish) 
    : name(_name), signatureDish(_signatureDish){};

bool Chef::isSignatureDish(string dish) {
    return dish == signatureDish;
}
void Chef::cook(string dish) {
    cout << name;
}