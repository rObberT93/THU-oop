#pragma once
#include<iostream>
# include <string>
using namespace std;

class VerificationStrategy{ // 验证
public:
	virtual string verify(std::string mes) = 0;
};


class PrefixStrategy : public VerificationStrategy{ // 前缀
public:
	string verify(string mes) {
		string pre_mes = mes.substr(0, 3);
		return pre_mes;
	}
};

class IntervalStrategy : public VerificationStrategy{ // 间隔
public:
	string verify(string mes) {
		string interval_mes = "";
		int len = mes.length();
		for(int i = 0; i < len; i +=2) {
			interval_mes += mes[i];
		}
		return interval_mes;
	}
};