#ifndef VECTORITERATORBASE_HPP
# define VECTORITERATORBASE_HPP
template <typename Value>
class VectorIteratorBase
{
    public:
        VectorIteratorBase(Value *storagePtr)
            : _storagePtr(storagePtr) {}
        bool operator==(const VectorIteratorBase<Value> &rhs)
        {
            return _storagePtr == rhs._storagePtr;
        }
        bool operator!=(const VectorIteratorBase<Value> &rhs)
        {
            return _storagePtr != rhs._storagePtr;
        }
    protected:
        Value *_storagePtr;
};

#endif