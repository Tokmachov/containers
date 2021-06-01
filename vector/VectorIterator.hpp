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
            
            //(random_access_iterator requirement) X a
            VectorIterator()
                : VectorIteratorBase<Value>(0) {}
            VectorIterator(Value *storagePtr)
                : VectorIteratorBase<Value>(storagePtr) {}
            //(random_access_iterator requirement) X b(a)
            VectorIterator<Value>(const VectorIterator<Value> &src)
                : VectorIteratorBase<Value>(src._storagePtr) {}
            
            // VectorIterator(const VectorIterator &src)
            //     : VectorIteratorBase<const Value>(src._storagePtr) {}
            
            //(random_access_iterator requirement) it = it1
            VectorIterator &operator=(const VectorIterator &rhs)
            {
                this->_storagePtr = rhs._storagePtr;
                return *this;
            }
            
            //(random_access_iterator requirement) *it or *it = t where reference is const Value&
            reference operator*() { return *this->_storagePtr; };
            
            //(random_access_iterator requirement) it->m
            pointer operator->() { return &(*this->_storagePtr); };
            
            //(random_access_iterator requirement) ++it
            VectorIterator &operator++()
            {
                this->_storagePtr++;
                return *this;
            }
            
            //(random_access_iterator requirement) a++
            VectorIterator operator++(int)
            {
                VectorIterator tmp = *this;
                this->_storagePtr++;
                return tmp;
            }
            
            //(random_access_iterator requirement) --it
            VectorIterator &operator--()
            {
                this->_storagePtr--;
                return *this;
            }
            
            //(random_access_iterator requirement) it--
            VectorIterator operator--(int)
            {
                VectorIterator tmp = *this;
                this->_storagePtr--;
                return tmp;
            }
            
            //(random_access_iterator requirement) it + n
            ft::VectorIterator<Value> operator+(difference_type offset)
            {
                return this->_storagePtr + offset;
            }
            
            //(random_access_iterator requirement) n + it is defined globally
            
            //(random_access_iterator requirement) it - n
            VectorIterator<Value> operator-(difference_type offset)
            {
                return this->_storagePtr - offset;
            }
            
            //(random_access_iterator requirement) it1 - it2
            difference_type operator-(const ft::VectorIterator<Value> & itRhs)
            {
                return this->_storagePtr - itRhs._storagePtr;
            }
            
            //(random_access_iterator requirement) a < b, a > b, a <= b, a >= b
            bool operator<(const VectorIterator &rhs)
            {
                return this->_storagePtr < rhs._storagePtr;
            }
            bool operator>(const VectorIterator &rhs)
            {
                return this->_storagePtr > rhs._storagePtr;
            }
            bool operator<=(const VectorIterator &rhs)
            {
                return this->_storagePtr <= rhs._storagePtr;
            }
            bool operator>=(const VectorIterator &rhs)
            {
                return this->_storagePtr >= rhs._storagePtr;
            }
            
            //(random_access_iterator requirement) it == it1 it != it1 defined in VectorIteratorBase

            //(random_access_iterator requirement) a += n
            VectorIterator<Value> &operator+=(VectorIterator<Value>::difference_type offset)
            {
                this->_storagePtr += offset;
                return *this;
            }
            
            //(random_access_iterator requirement) a -= n
            VectorIterator<Value> &operator-=(typename VectorIterator<Value>::difference_type offset)
            {
                this->_storagePtr -= offset;
                return *this;
            }
            
            //(random_access_iterator requirement) a[n]
            reference operator[] (difference_type idx)
            {
                return this->_storagePtr[idx];
            }
            
            //(random_access_iterator requirement) convertible to const_iterator
            operator VectorIterator<const value_type>()
            {
                const value_type *constStoragePtr = this->_storagePtr;
                return VectorIterator<const value_type>(constStoragePtr);
            }
    };
    //(random_access_iterator requirement) n + it
    template <typename Value>
    ft::VectorIterator<Value> operator+
    (
        typename ft::VectorIterator<Value>::difference_type offset, 
        ft::VectorIterator<Value> & it
    )
    {
        return ft::VectorIterator<Value>(&(*it) + offset);
    }
}

#endif