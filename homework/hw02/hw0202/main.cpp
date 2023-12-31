#include <iostream>
#include "Example.h"

using namespace std;

void create_example(int n) {
	
	cout << "--------create_example is ready--------\n";
	
	Example* e[10];
	
	for (int i = 0; i < n; i++)
		e[i] = new Example(i);
			
	// (6)
	static Example ex6(2333);
    for (int i = 0; i < n; i++) {
        e[i]->getData();
    }
    for (int i = 0; i<= n-1; i++) {
        delete e[i];
    }
	ex6.getData();

	
	cout << "--------create_example is over--------\n";
}

// (7)
Example ex1(23);


int main() {

	cout << "--------main_function is ready--------\n";

	// (8)
	Example ex2(233);

		
	create_example(3);
	
	// (9)
    Example ex7(23333);
	ex1.getData();
	ex2.getData();
	ex7.getData();


	cout << "--------main_function is over---------\n";

	return 0;
}
