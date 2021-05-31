#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

#include "VectorIteratorBase.hpp"

namespace ft
{
    template <typename Value>
    class VectorIterator : public VectorIteratorBase<Value>
    {
        public:
            typedef Value value_type;
            typedef ptrdiff_t difference_type;
            typedef Value* pointer;
            typedef Value& reference;
            typedef std::random_access_iterator_tag iterator_category;
            friend VectorIterator<Value> &operator+(difference_type offset, const VectorIterator & it);
            friend VectorIterator<Value> &operator-(const VectorIterator & it, difference_type offset);
            VectorIterator<Value>() {}
            VectorIterator<Value>(Value *storagePtr)
                : VectorIteratorBase<Value>(storagePtr) {}
            VectorIterator<Value>(const VectorIterator &src) 
                : VectorIteratorBase<Value>(src._storagePtr) {}
            VectorIterator &operator=(const VectorIterator &rhs)
            {
                this->_storagePtr = rhs._storagePtr;
                return *this;
            }
            Value &operator*() { return *this->_storagePtr; };
            Value *operator->() { return &(*this->_storagePtr); };
            VectorIterator &operator++()
            {
                this->_storagePtr++;
                return *this;
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
                return *this;
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
                return *this;
            }
            VectorIterator<Value> &operator-=(typename VectorIterator<Value>::difference_type offset)
            {
                this->_storagePtr -= offset;
                return *this;
            }
            difference_type operator-(const ft::VectorIterator<Value> & itRhs)
            {
                return this->_storagePtr - itRhs._storagePtr;
            }
            ft::VectorIterator<Value> operator+(difference_type offset)
            {
                return this->_storagePtr + offset;
            }
            value_type &operator[] (difference_type idx)
            {
                return this->_storagePtr[idx];
            }
    };
}

template <typename Value>
ft::VectorIterator<Value> operator+(typename ft::VectorIterator<Value>::difference_type offset, const ft::VectorIterator<Value> & it)
{
    return it._storagePtr + offset;
}

template <typename Value>
ft::VectorIterator<Value> operator-(const ft::VectorIterator<Value> & it, typename ft::VectorIterator<Value>::difference_type offset)
{
    return it._storagePtr - offset;
}

#endif