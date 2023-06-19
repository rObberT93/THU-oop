#include <memory>
#include <list>
#include <functional>
#include "event.h"
#include "window.h"
#include<iostream>
using namespace std;
list<function<void()>> Window::commandHistory;