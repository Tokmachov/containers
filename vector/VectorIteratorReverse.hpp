#ifndef VECTORITERATORREVERSE_HPP
# define VECTORITERATORREVERSE_HPP

#include "VectorIteratorBase.hpp"

namespace ft
{
    template <typename Value>
    class VectorIteratorReverse : public VectorIteratorBase<Value>
    {
        public:
            typedef Value value_type;
            typedef ptrdiff_t difference_type;
            typedef Value* pointer;
            typedef Value& reference;
            typedef std::random_access_iterator_tag iterator_category;
            friend VectorIteratorReverse<Value> &operator+(difference_type offset, const VectorIteratorReverse & it);
            friend VectorIteratorReverse<Value> &operator-(const VectorIteratorReverse & it, difference_type offset);
            VectorIteratorReverse<Value>() {}
            VectorIteratorReverse<Value>(Value *storagePtr)
                : VectorIteratorBase<Value>(storagePtr) {}
            VectorIteratorReverse<Value>(const VectorIteratorReverse &src) 
                : VectorIteratorBase<Value>(src._storagePtr) {}
            VectorIteratorReverse &operator=(const VectorIteratorReverse &rhs)
            {
                this->_storagePtr = rhs._storagePtr;
                return *this;
            }
            Value &operator*() { return *this->_storagePtr; };
            Value *operator->() { return &(*this->_storagePtr); };
            VectorIteratorReverse &operator++()
            {
                this->_storagePtr--;
                return *this;
            }
            VectorIteratorReverse operator++(int)
            {
                VectorIteratorReverse tmp = *this;
                this->_storagePtr--;
                return tmp;
            }
            VectorIteratorReverse &operator--()
            {
                this->_storagePtr++;
                return *this;
            }
            VectorIteratorReverse operator--(int)
            {
                VectorIteratorReverse tmp = *this;
                this->_storagePtr++;
                return tmp;
            }
            VectorIteratorReverse<Value> &operator+=(VectorIteratorReverse<Value>::difference_type offset)
            {
                this->_storagePtr -= offset;
                return *this;
            }
            VectorIteratorReverse<Value> &operator-=(typename VectorIteratorReverse<Value>::difference_type offset)
            {
                this->_storagePtr += offset;
                return *this;
            }
            difference_type operator-(const ft::VectorIteratorReverse<Value> & itRhs)
            {
                return this->_storagePtr - itRhs._storagePtr;
            }
            ft::VectorIteratorReverse<Value> operator+(difference_type offset)
            {
                return this->_storagePtr - offset;
            }
            value_type &operator[] (difference_type idx)
            {
                return this->_storagePtr[idx];
            }
    };
}

template <typename Value>
ft::VectorIteratorReverse<Value> operator+(typename ft::VectorIteratorReverse<Value>::difference_type offset, const ft::VectorIteratorReverse<Value> & it)
{
    return it._storagePtr - offset;
}

template <typename Value>
ft::VectorIteratorReverse<Value> operator-(const ft::VectorIteratorReverse<Value> & it, typename ft::VectorIteratorReverse<Value>::difference_type offset)
{
    return it._storagePtr + offset;
}

#endif