#include "derivedOperation.h"

void operatorAdd::UpdateValue() {
    value_ = input1->value() + input2->value();
}

void operatorSub::UpdateValue() {
    value_ = input1->value() - input2->value();
}