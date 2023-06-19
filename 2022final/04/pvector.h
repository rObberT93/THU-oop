#pragma once
#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include "stdlib.h"
#include "point.h"
using namespace std;
template<class T>
class Data
{
public:
    int length;
    Data<T>(int _length) : length(_length) {}
    virtual const T& get(int index) = 0;
    virtual ~Data<T>(){};
    virtual shared_ptr<Data<T>>getlastdata(){};
    virtual bool kong(){};
};

template<class T>
class DataEmpty : public Data<T>
{
public:
    DataEmpty<T>(): Data<T>(0) {};
    const T& get(int index) {
        assert(0); // No data in DataEmpty
    }
    bool kong() {
        return true;
    }
};

template<class T>
class DataPushBackDecorator : public Data<T>
{// Implement a Decorator for push_back operation
public:
    shared_ptr<Data<T>> data;
    T value;
    DataPushBackDecorator<T>(shared_ptr<Data<T>>_data, const T& _value) : Data<T>(0), data(_data), value(_value){
        Data<T>::length = data->length + 1;
    }
    const T& get(int index){
        if(index == data->length)
            return value;
        else 
            return data->get(index);
    }
    bool kong() {
        return false;
    }
    shared_ptr<Data<T>>getlastdata(){
        return data;
    }
};

template<class T>
class DataSetDecorator : public Data<T>
{// Implement a Decorator for set operation
public:
    shared_ptr<Data<T>> data;
    T value;
    int dex;

    DataSetDecorator<T>(shared_ptr<Data<T>>_data, int _index, const T& _value) : Data<T>(0), data(_data), dex(_index), value(_value){
        Data<T>::length = data->length;
    }
    const T& get(int index){
        if(dex == index)
            return value;
        else
            return data->get(index);
    }
    bool kong() {
        return false;
    }
    shared_ptr<Data<T>>getlastdata() {
        return data;
    }
};


template<class T>
class PVector
{
public:
    shared_ptr<Data<T>> data;
    PVector<T>() : data(new DataEmpty<T>()){
        //data = new DataEmpty<T>();
        // when to delete??
    }
    PVector<T>(shared_ptr<Data<T>> _data): data(_data) { }
    PVector<T> push_back(const T &value) const{
        return PVector<T>(make_shared<DataPushBackDecorator<T>>(data, value));
    }
    PVector<T> set(int index, const T &value) const{
        return PVector<T>(make_shared<DataSetDecorator<T>>(data, index, value));
    }

    const T& operator[](int index){
        return data->get(index);
    }

    PVector<T> undo() {
        if(!data->kong())
            return PVector<T>(data->getlastdata());
        else{
            cout << "cannot undo" << endl;
            return PVector<T>();
        }
    } 

    friend ostream& operator<< (ostream& out, PVector& m) {
        out << "[";
        for(int i = 0; i < m.data->length; i++) {
            out << m[i];
            if(i != m.data->length - 1) 
                out << ", ";
        }
        out << "]";
        return out;
    }
};
