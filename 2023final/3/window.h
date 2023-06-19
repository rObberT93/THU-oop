#pragma once
#include <memory>
#include <list>
#include<functional>
#include "event.h"

using namespace std;

class Window;

class Widget {
    string _name;
    Window* _parent;
public:
    Widget(string name) :_name(name), _parent(nullptr) {}
    string getName() const { return _name; }
    Window* getParent() const { return _parent; }
    void setParent(Window * parent) {_parent = parent;}
    virtual ~Widget() {}
};



class Button :public Widget, public Click, public DoubleClick {
public:
    Button(string name) :Widget(name) {}
};


class Checkbox :public Widget, public Click {
    // TODO
public:
    bool selected;
    Checkbox(const string& name) : Widget(name), selected(false){};
    void click() {
        selected = !selected;
    }
    void select() {
        selected = true;
    }
    void clear(){
        selected = false;
    }
    bool isSelected() const {
        return selected;
    }
};

class Window {
public:
    // TODO
    list<shared_ptr<Widget>> Widgets;
    list<function<void()>> commandHistory;
    shared_ptr<Widget> getPointerByName(string name){
        for (auto widget : Widgets) {
            if (widget->getName() == name)
                return widget;
        }
        return nullptr;
    }
    // TODO
    Widget& getElementByName(string name){
        for (auto& widget : Widgets) {
            if (widget->getName() == name)
                return *widget;
            }
    }
    // TODO
    bool addElement(shared_ptr<Widget> w){
        for(auto widget : Widgets) {
            if(widget->getName() == w->getName()) {
                return false;
            }
        }
        w->setParent(this);
        Widgets.push_back(w);
        return true;
    }
    // TODO
    bool undo(){
        if(commandHistory.empty()) {
            return false;
        }else {
            auto lastCommand = commandHistory.back();
            lastCommand();
            commandHistory.pop_back();
            return true;
        }
    }
};

