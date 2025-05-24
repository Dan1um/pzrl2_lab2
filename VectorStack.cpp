#include "VectorStack.h"

VectorStack::VectorStack(const ValueType* valueArray, const int arraySize)
    : vec(std::vector<ValueType>(valueArray, valueArray + arraySize))
{}
void VectorStack::push(const ValueType& value) { vec.push_back(value); }
void VectorStack::pop() { vec.erase(vec.begin()); }
const ValueType& VectorStack::top() const { return vec.front(); }
bool VectorStack::isEmpty() const { return vec.empty(); }
size_t VectorStack::size() const { return vec.size(); }