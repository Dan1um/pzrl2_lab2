#include "Stack.h"
#include "StackImplementation.h"
#include "VectorStack.h"
#include "ListStack.h"
#include <stdexcept>
#include <vector>
#include <algorithm>

Stack::Stack(StackContainer container) : _containerType(container)
{
    switch (_containerType)
    {
        case StackContainer::List:
        {
            _pimpl = new ListStack();
            break;
        }
        case StackContainer::Vector:
        {
            _pimpl = new VectorStack();
            break;
        }
        default:
        {
            throw std::runtime_error("Invalid container type");
        }
    }
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container)
    : _containerType(container)
{
    switch (_containerType)
    {
        case StackContainer::List:
        {
            _pimpl = new ListStack();
            break;
        }
        case StackContainer::Vector:
        {
            _pimpl = new VectorStack();
            break;
        }
        default:
            throw std::runtime_error("Invalid container type");
    }

    for (size_t i = 0; i < arraySize; ++i){
        _pimpl->push(valueArray[i]);
    }
}

Stack::Stack(const Stack& other)
{
    _containerType = other._containerType;
    switch (_containerType)
    {
        case StackContainer::List:
        {
            _pimpl = new ListStack(*dynamic_cast<ListStack*>(other._pimpl));
            break;
        }
        case StackContainer::Vector:
        {
            _pimpl = new VectorStack(*dynamic_cast<VectorStack*>(other._pimpl));
            break;
        }
        default:
        {
            throw std::runtime_error("Invalid container type");
        }
    }
}

Stack& Stack::operator=(const Stack& other)
{
    if (this != &other)
    {
        delete _pimpl;

        _containerType = other._containerType;
        switch (_containerType)
        {
            case StackContainer::List:
            {
                _pimpl = new ListStack(*dynamic_cast<ListStack*>(other._pimpl));
                break;
            }
            case StackContainer::Vector:
            {
                _pimpl = new VectorStack(*dynamic_cast<VectorStack*>(other._pimpl));
                break;
            }
            default:
            {
                throw std::runtime_error("Invalid container type");
            }
        }
    }
    return *this;
}

Stack::Stack(Stack&& other) noexcept
    : _pimpl(other._pimpl), _containerType(other._containerType)
{
    other._pimpl = nullptr;
}

Stack& Stack::operator=(Stack&& other) noexcept
{
    if (this != &other)
    {
        delete _pimpl;
        _pimpl = other._pimpl;
        _containerType = other._containerType;
        other._pimpl = nullptr;
    }
    return *this;
}

Stack::~Stack()
{
    delete _pimpl;
}

void Stack::push(const ValueType& value) {
    _pimpl->push(value);
}

void Stack::pop() {
    _pimpl->pop();
}

const ValueType& Stack::top() const {
    return _pimpl->top();
}

bool Stack::isEmpty() const {
    return _pimpl->isEmpty();
}

size_t Stack::size() const {
    return _pimpl->size();
}