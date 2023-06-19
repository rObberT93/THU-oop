#include <iostream>
#include <memory>
using namespace std;

// 抽象组件接口
class Component {
public:
    virtual void operation() = 0;
};

// 具体组件类
class ConcreteComponent : public Component {
public:
    void operation() override {
        cout << "ConcreteComponent: 基本操作" << endl;
    }
};

// 装饰器基类
class Decorator : public Component {
protected:
    shared_ptr<Component> component;

public:
    Decorator(std::shared_ptr<Component> comp) : component(comp) {}

    void operation() override {
        if (component) {
            component->operation();
        }
    }
};

// 具体装饰器类
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(shared_ptr<Component> comp) : Decorator(comp) {}

    void operation() override {
        Decorator::operation();
        std::cout << "ConcreteDecoratorA: 添加额外操作A" << endl;
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(shared_ptr<Component> comp) : Decorator(comp) {}

    void operation() override {
        Decorator::operation();
        cout << "ConcreteDecoratorB: 添加额外操作B" << endl;
    }
};

int main() {
    // 创建具体组件对象
    shared_ptr<Component> component = make_shared<ConcreteComponent>();

    // 创建装饰器对象，并传入具体组件对象
    shared_ptr<Decorator> decoratorA = make_shared<ConcreteDecoratorA>(component);
    shared_ptr<Decorator> decoratorB = make_shared<ConcreteDecoratorB>(decoratorA);

    // 调用装饰器对象的操作，实际上会依次调用组件和装饰器的操作
    decoratorB->operation();

    return 0;
}
