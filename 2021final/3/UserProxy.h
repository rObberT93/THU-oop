#pragma once
#include <iostream>
#include "User.h"
#include "EncryptStrategy.h"
#include "VerificationStrategy.h"

using namespace std;

class UserProxy : public User{
    RealUser* ruser;
    EncryptStrategy* encStr;
    VerificationStrategy* verStr;
public:
    UserProxy(RealUser* _r, EncryptStrategy* _e, VerificationStrategy* _v) 
    : ruser(_r), encStr(_e), verStr(_v){} 

    void sendMessage(string mes){
        string jiami = encStr->encode(mes);
        string yanzheng = verStr->verify(mes);
        string res = jiami + '\n' + yanzheng;
        ruser->sendMessage(res);
    }
};