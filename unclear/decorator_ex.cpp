#include <iostream>
using namespace std;

//所有View的基类
class Component {
public:
	virtual ~Component() { }
	virtual void draw() = 0;
};

//一个基本的TextView类
class TextView : public Component {
public:
	void draw() {
		cout << "TextView." << endl;
	}
};

//装饰器的核心内涵在于用装饰器类整体包裹改动之前的类，以保留原来的全部接口
//在原来接口保留的基础上进行新功能扩充

class Decorator : public Component {
	//这里一个基类指针可以让Decorator能够以递归的形式不断增加新功能
	Component* _component; 
public:
	Decorator(Component* component) : _component(component) { }
	virtual void addon() = 0;
	void draw() {
		addon();
		_component -> draw();
	}
};

//包裹原Component并扩充边框
class Border : public Decorator {
public:
	Border(Component* component) : Decorator(component) { }
	void addon() { cout << "Bordered "; } 
};

//包裹原Component并扩充水平滚动条
class HScroll : public Decorator {
public:
	HScroll(Component* component): Decorator(component) { }
	void addon() { cout << "HScrolled "; }
};

//包裹原Component并扩充垂直滚动条
class VScroll : public Decorator {
public:
	VScroll(Component* component): Decorator(component) { }
	void addon() { cout << "VScrolled "; } 
};

int main(int argc, char** argv) {
	//基础的textView
	TextView textView;
	//在基础textView上增加滚动条
	VScroll vs_TextView(&textView);
	//在增加垂直滚动条的基础上增加滚动横条
	HScroll hs_vs_TextView(&vs_TextView);
	//在增加水平与垂直滚动条之后增加边框
	Border b_hs_vs_TextView(&hs_vs_TextView);
	b_hs_vs_TextView.draw();
	return 0;
}