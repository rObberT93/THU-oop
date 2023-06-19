#pragma once
#include "window.h"
#include <iostream>
#include <memory>
#include <list>
using namespace std;

class ClearAll {
public:
    // TODO
    list<shared_ptr<Checkbox>> checkboxes;
    ClearAll(list<shared_ptr<Checkbox>> checkbox):checkboxes(checkbox){};
    void operator()(){
        for (auto checkbox : checkboxes) {
            checkbox->clear();
        }
    }
};
class SelectAll {
    // ...
public:
    list<shared_ptr<Checkbox>> checkboxes;
    SelectAll(list<shared_ptr<Checkbox>> checkbox) : checkboxes(checkbox) {}
    void operator()() {
        for (auto checkbox : checkboxes) {
            checkbox->select();
        }
    }
};

class Submit {
    list<shared_ptr<Checkbox>> checkboxes;
public:
    Submit(list<shared_ptr<Checkbox>> checkbox) : checkboxes(checkbox) {}
    void operator()() {
        for (auto checkbox : checkboxes) {
            if (checkbox->isSelected())
                cout << checkbox->getName() << " is selected" << endl;
            else
                cout << checkbox->getName() << " is not selected" << endl;
        }
    }
};
