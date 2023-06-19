#pragma once
#include"operation.h"
class operatorAdd : public OperationNodeTwo {
public:
    operatorAdd(const string& node_name, Node *x1, Node *x2) : OperationNodeTwo(node_name, x1, x2){}
    virtual void UpdateValue() override;
};
class operatorSub : public OperationNodeTwo {
public: 
    operatorSub(const string& node_name, Node* x1, Node* x2) : OperationNodeTwo(node_name, x1, x2){}
    virtual void UpdateValue() override;
};
