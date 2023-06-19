#include <iostream>
#include <fstream>
#include <functional>
using namespace std;

class ReadFromFile {
public:
	string operator()(){
       string input;
       getline(ifstream("input.txt"), input);
       return input;
	}
};

string readFromScreen(){
    string input;
    getline(cin, input);
    return input;
}

string calculateAdd(string str) {return str;}
void writeToScreen(string str) { cout << str << endl;}

void process(
		function<string()> read, 
		function<string(string)> calculate,
		function<void(string)>	write)
{
	string data = read();
	string output = calculate(data);
	write(output);
}

int main()
{
	process(readFromScreen, calculateAdd, writeToScreen);
	process(ReadFromFile(), calculateAdd, writeToScreen);
	return 0;
}
