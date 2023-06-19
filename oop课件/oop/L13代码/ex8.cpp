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

int main()
{
	function<string()> readArr[] = 
			{readFromScreen, ReadFromFile()};
	function<string()> readFunc;
	readFunc = readFromScreen;
	readFunc = ReadFromFile();
	string (*readFunc2)();
	readFunc2 = readFromScreen;
	//readFunc2 = ReadFromFile(); //错误，类型不一致
	return 0;
}
