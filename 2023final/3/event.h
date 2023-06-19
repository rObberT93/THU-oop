#pragma once
#include <functional>
#include "window.h"

using namespace std;

class Click {
private:
    // TODO
    // function<void()>clickcommand;
    // Window* w;
public:
    function<void()>clickcommand;
    //Window w;
    // TODO
    Click(){}
    // TODO
    void setClickCommand(const function<void()>& command) {
        clickcommand = command;
    }
    virtual void click() {
        if(clickcommand) {
            clickcommand();
            //w.commandHistory.push_back(clickcommand);
        }
    }
    
};


class DoubleClick {
private:
    // TODO

public:
    function<void()> doubleClickCommand;
    //Window w;
    // TODO
    DoubleClick(){}
    // TODO
    void setDoubleClickCommand(const function<void()>& command){
        doubleClickCommand = command;
    }
    // TODO
    virtual void doubleClick(){
        if(doubleClickCommand) 
            doubleClickCommand();
            //w.commandHistory.push_back(doubleClickCommand);
    }
};