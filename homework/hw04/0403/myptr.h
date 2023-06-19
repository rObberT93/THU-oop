#pragma once
using namespace std;

template<typename T>
class my_ptr {
private:
    T* ptr;
    static T* temp;
public:
    my_ptr() : ptr(nullptr) {
        cout << "my_ptr constructed." << endl;
    };

    my_ptr(T* p) : ptr(p) {
        cout << "my_ptr constructed." << endl;
    };

    ~my_ptr(){
        if(ptr != nullptr) {
            delete ptr;
            ptr = nullptr;
        }
        if(temp != nullptr) {
            delete temp;
            temp = nullptr;
        }
        cout << "my_ptr destructed." << endl;
    }

    // 禁用拷贝构造函数
    my_ptr(const my_ptr& p) noexcept {
        cout << "Copying of my_ptr is forbidden!" << endl;
        cout << "my_ptr constructed." << endl;
        ptr = nullptr;
    };

    // 禁用拷贝赋值
    my_ptr& operator = (const my_ptr& p) {
        cout << "Copying of my_ptr is forbidden!" << endl;
        // delete ptr;
        // ptr = nullptr;
        cout << "my_ptr updated." << endl;
        return *this;
    };

    // 移动构造函数
    my_ptr(my_ptr&& p) noexcept : ptr(p.ptr){
        p.ptr = nullptr; 
        cout << "my_ptr constructed." << endl;
    }

    // 移动赋值函数
    my_ptr& operator=(my_ptr&& p) noexcept {
        if(this != &p) {
            delete ptr;
            ptr = p.ptr;
            p.ptr = nullptr;
            cout << "my_ptr updated." << endl;
        }
        return *this;
    } 

    T& operator* () const {
        if(ptr == nullptr) {
            if(temp == nullptr) 
                my_ptr<T>::temp = new T();
            cout << "Do not attempt to read a nullptr!" << endl;
            return *temp;
        }
        return *ptr;
    }
    
    T* operator->() const {
        if(ptr == nullptr) {
            cout << "Do not attempt to read a nullptr!" << endl;
            return temp;
        }
        return ptr;
    }
};

template<typename T>
T* my_ptr<T>::temp = nullptr;