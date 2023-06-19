#include <iostream>
#include "Example.h"

using namespace std;

	// (2)
    int Example::count = 0;

Example::Example(int data) {
	// (3)
    DATA = data;
    count ++;
    ID = count;
    cout << "Example #" << ID << " is created" << endl;
}

void Example::getData() {
	// (4)
    cout << "The data of Example #" << ID <<" is " << DATA << endl;
    
}

Example::~Example() {
	// (5)
    cout << "Example #"<< ID <<" is destroyed" << endl;
    
}