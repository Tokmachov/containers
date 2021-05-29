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
        bool operator<(const VectorIteratorBase &rhs)
        {
            return _storagePtr < rhs._storagePtr;
        } 
        bool operator>(const VectorIteratorBase &rhs)
        {
            return _storagePtr > rhs._storagePtr;
        }
        bool operator<=(const VectorIteratorBase &rhs)
        {
            return _storagePtr <= rhs._storagePtr;
        }
        bool operator>=(const VectorIteratorBase &rhs)
        {
            return _storagePtr >= rhs._storagePtr;
        }
    protected:
        Value *_storagePtr;
};
