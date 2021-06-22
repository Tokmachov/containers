#ifndef VECTORITERATORBASE_HPP
# define VECTORITERATORBASE_HPP
# include <iostream>

template <typename Value>
class VectorIteratorBase
{
    public:
        VectorIteratorBase(Value *storagePtr)
            : _storagePtr(storagePtr) {}
        friend bool operator==(const VectorIteratorBase<Value> &lhs, const VectorIteratorBase<Value> &rhs)
        {
            return lhs._storagePtr == rhs._storagePtr;
        }
        friend bool operator!=(const VectorIteratorBase<Value> &lhs, const VectorIteratorBase<Value> &rhs)
        {
            return lhs._storagePtr != rhs._storagePtr;
        }
    protected:
        Value *_storagePtr;
};

#endif