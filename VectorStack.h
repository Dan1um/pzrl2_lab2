#include <vector>
#include "StackImplementation.h"

using ValueType = double;

class VectorStack : public IStackImplementation{
public:
    VectorStack() = default;
    VectorStack(const ValueType* valueArray, const int arraySize);
    explicit VectorStack(const VectorStack& other) = default;
    VectorStack& operator=(const VectorStack& other) = default;

    void push(const ValueType& value) override;
    void pop() override;
    const ValueType& top() const override;
    bool isEmpty() const override;
    size_t size() const override;
    virtual ~VectorStack() = default;
private:
    std::vector<ValueType> vec;
};
