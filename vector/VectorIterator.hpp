#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include "VectorIteratorBase.hpp"

template <typename Value>
class VectorIterator : public VectorIteratorBase<Value>
{
    public:
        typedef Value value_type;
        typedef ptrdiff_t difference_type;
        typedef Value* pointer;
        typedef Value& reference;
        typedef std::random_access_iterator_tag iterator_category;
        friend VectorIterator<Value> &operator+(const VectorIterator & it, difference_type offset);
        friend VectorIterator<Value> &operator+(difference_type offset, const VectorIterator & it);
        friend VectorIterator<Value> &operator-(const VectorIterator & it, difference_type offset);
        friend VectorIterator<Value> &operator-(difference_type offset, const VectorIterator & it);
        VectorIterator<Value>() {}
        VectorIterator<Value>(const VectorIterator &src) 
            : VectorIteratorBase<Value>(src._storagePtr) {}
        VectorIterator &operator=(const VectorIterator &rhs)
        {
            this->_storagePtr = rhs._storagePtr;
        }
        Value &operator*() { return *this->_storagePtr; };
        Value *operator->() { return &(*this->_storagePtr); };
        VectorIterator &operator++()
        {
            this->_storagePtr++;
            return this;
        }
        VectorIterator operator++(int)
        {
            VectorIterator tmp = *this;
            this->_storagePtr++;
            return tmp;
        }
        VectorIterator &operator--()
        {
            this->_storagePtr--;
            return this;
        }
        VectorIterator operator--(int)
        {
            VectorIterator tmp = *this;
            this->_storagePtr--;
            return tmp;
        }
        VectorIterator<Value> &operator+=(VectorIterator<Value>::difference_type offset)
        {
            this->_storagePtr += offset;
            return this;
        }
        VectorIterator<Value> &operator-=(typename VectorIterator<Value>::difference_type offset)
        {
            this->_storagePtr -= offset;
            return this;
        }
        value_type &operator[] (difference_type idx)
        {
            return this->_storagePtr[idx];
        }
};

template <typename Value>
VectorIterator<Value> &operator+(const VectorIterator<Value> & it, typename VectorIterator<Value>::difference_type offset)
{
    it._storagePtr += offset;
}

template <typename Value>
VectorIterator<Value> &operator+(typename VectorIterator<Value>::difference_type offset, const VectorIterator<Value> & it)
{
    it._storagePtr += offset;
}

template <typename Value>
VectorIterator<Value> &operator-(const VectorIterator<Value> & it, typename VectorIterator<Value>::difference_type offset)
{
    it._storagePtr -= offset;
}

template <typename Value>
VectorIterator<Value> &operator-(typename VectorIterator<Value>::difference_type offset, const VectorIterator<Value> & it)
{
    it._storagePtr -= offset;
}

#endif
