#include <iostream>
#include <functional>
#include <fstream>
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

template<class ReadFunc, class CalFunc, class WriteFunc>
void process(ReadFunc read, CalFunc calculate, WriteFunc write)
{
	string data = read();
	string output = calculate(data);
	write(output);
}

int main()
{
	function<string()> readArr[] = {readFromScreen, ReadFromFile()};
	function<string()> readFunc;
	readFunc = readFromScreen; //允许函数的赋值
	readFunc = ReadFromFile();
	string (*readFunc2)();
	readFunc2 = readFromScreen;
	//readFunc2 = ReadFromFile(); //错误，类型不一致
	process(readFromScreen, calculateAdd, writeToScreen);
	process(ReadFromFile(), calculateAdd, writeToScreen);
	return 0;
}
