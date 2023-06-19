#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class EncryptStrategy{ // 加密
public:
	virtual string encode(string mes) = 0;
};

class InsertStrategy : public EncryptStrategy{  // 插入加密
public:
	string encode(string mes){
		int m_len = mes.length();
		string insert_mes = "";
		for(int i = 0; i < m_len; i++){
			insert_mes = insert_mes + mes[i] + '#'; 
		}
		return insert_mes;
	}
};

class InvertStrategy : public EncryptStrategy{
public:
	string encode(string mes){
		string invert_mes = mes;
		reverse(invert_mes.begin(), invert_mes.end());
		return invert_mes;
	}
};