#include <iostream>

// 抽象主题接口
class Subject {
public:
    virtual void request() = 0;
};

// 具体主题类
class RealSubject : public Subject {
public:
    void request() override {
        std::cout << "RealSubject: 处理请求" << std::endl;
    }
};

// 代理类
class Proxy : public Subject {
private:
    RealSubject* realSubject;

public:
    Proxy() : realSubject(nullptr) {}

    void request() override {
        if (!realSubject) {
            realSubject = new RealSubject();
        }

        std::cout << "Proxy: 转发请求给RealSubject" << std::endl;
        realSubject->request();
    }
};

int main() {
    Proxy proxy;
    proxy.request();

    return 0;
}
