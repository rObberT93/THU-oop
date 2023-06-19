#pragma once
#include <string>
using namespace std;

class User{
public:
	virtual void sendMessage(string mes) = 0;
};

class RealUser{
private:
	std::string username;
public:
	RealUser(std::string un): username(un){}
	void sendMessage(std::string mes) {
		std::cout << username << std::endl;
		std::cout << mes << std::endl;
	}
};