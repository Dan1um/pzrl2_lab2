#include <list>
#include "StackImplementation.h"

using ValueType = double;

class ListStack : public IStackImplementation{
public:
    ListStack() = default;
    ListStack(const ValueType* valueArray, const int arraySize);
    explicit ListStack(const ListStack& other) = default;
    ListStack& operator=(const ListStack& other) = default;

    void push(const ValueType& value) override;
    void pop() override;
    const ValueType& top() const override;
    bool isEmpty() const override;
    size_t size() const override;
    virtual ~ListStack() = default;
private:
    std::list<ValueType> lst;
};
