#ifndef VECTORITERATORREVERSED_HPP
# define VECTORITERATORREVERSED_HPP

#include "VectorIteratorBase.hpp"

template <typename Value>
class VectorIteratorReversed : public VectorIteratorBase<Value>
{
    public:
        typedef Value value_type;
        typedef ptrdiff_t difference_type;
        typedef Value* pointer;
        typedef Value& reference;
        typedef std::random_access_iterator_tag iterator_category;
        friend VectorIteratorReversed<Value> &operator+(const VectorIteratorReversed & it, difference_type offset);
        friend VectorIteratorReversed<Value> &operator+(difference_type offset, const VectorIteratorReversed & it);
        friend VectorIteratorReversed<Value> &operator-(const VectorIteratorReversed & it, difference_type offset);
        friend VectorIteratorReversed<Value> &operator-(difference_type offset, const VectorIteratorReversed & it);
        VectorIteratorReversed<Value>() {}
        VectorIteratorReversed<Value>(const VectorIteratorReversed &src) 
            : VectorIteratorBase<Value>(src._storagePtr) {}
        VectorIteratorReversed &operator=(const VectorIteratorReversed &rhs)
        {
            this->_storagePtr = rhs._storagePtr;
        }
        VectorIteratorReversed &operator++()
        {
            this->_storagePtr--;
            return this;
        }
        VectorIteratorReversed operator++(int)
        {
            VectorIteratorReversed tmp = *this;
            this->_storagePtr--;
            return tmp;
        }
        VectorIteratorReversed &operator--()
        {
            this->_storagePtr++;
            return this;
        }
        VectorIteratorReversed operator--(int)
        {
            VectorIteratorReversed tmp = *this;
            this->_storagePtr++;
            return tmp;
        }
        VectorIteratorReversed<Value> &operator+=(VectorIteratorReversed<Value>::difference_type offset)
        {
            this->_storagePtr -= offset;
            return this;
        }
        VectorIteratorReversed<Value> &operator-=(typename VectorIteratorReversed<Value>::difference_type offset)
        {
            this->_storagePtr += offset;
            return this;
        }
};

template <typename Value>
VectorIteratorReversed<Value> &operator+(const VectorIteratorReversed<Value> & it, typename VectorIteratorReversed<Value>::difference_type offset)
{
    it._storagePtr -= offset;
    return it;
}

template <typename Value>
VectorIteratorReversed<Value> &operator+(typename VectorIteratorReversed<Value>::difference_type offset, const VectorIteratorReversed<Value> & it)
{
    it._storagePtr -= offset;
    return it;
}

template <typename Value>
VectorIteratorReversed<Value> &operator-(const VectorIteratorReversed<Value> & it, typename VectorIteratorReversed<Value>::difference_type offset)
{
    it._storagePtr += offset;
    return it;
}

template <typename Value>
VectorIteratorReversed<Value> &operator-(typename VectorIteratorReversed<Value>::difference_type offset, const VectorIteratorReversed<Value> & it)
{
    it._storagePtr += offset;
    return it;
}

#endif
