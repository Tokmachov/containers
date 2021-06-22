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
            
            //(random_access_iterator requirement) X a
            VectorIteratorReverse()
                : VectorIteratorBase<Value>(0) {}
            VectorIteratorReverse(Value *storagePtr)
                : VectorIteratorBase<Value>(storagePtr) {}
            //(random_access_iterator requirement) X b(a)
            VectorIteratorReverse<Value>(const VectorIteratorReverse<Value> &src)
                : VectorIteratorBase<Value>(src._storagePtr) {}
            //(random_access_iterator requirement) b = a
            VectorIteratorReverse<Value>(const VectorIteratorBase<Value> &src)
                : VectorIteratorBase<Value>(src) {}
            VectorIteratorReverse &operator=(const VectorIteratorReverse &rhs)
            {
                this->_storagePtr = rhs._storagePtr;
                return *this;
            }
            
            //(random_access_iterator requirement) *a or *a = t where reference is const Value&
            reference operator*() { return *this->_storagePtr; };
            
            //(random_access_iterator requirement) a->m
            pointer operator->() { return &(*this->_storagePtr); };
            
            //(random_access_iterator requirement) ++a
            VectorIteratorReverse &operator++()
            {
                this->_storagePtr--;
                return *this;
            }
            
            //(random_access_iterator requirement) a++
            VectorIteratorReverse operator++(int)
            {
                VectorIteratorReverse tmp = *this;
                this->_storagePtr--;
                return tmp;
            }
            
            //(random_access_iterator requirement) --it
            VectorIteratorReverse &operator--()
            {
                this->_storagePtr++;
                return *this;
            }
            
            //(random_access_iterator requirement) it--
            VectorIteratorReverse operator--(int)
            {
                VectorIteratorReverse tmp = *this;
                this->_storagePtr++;
                return tmp;
            }
            
            //(random_access_iterator requirement) it + n
            ft::VectorIteratorReverse<Value> operator+(difference_type offset)
            {
                return this->_storagePtr - offset;
            }
            
            //(random_access_iterator requirement) n + it is defined globally
            
            //(random_access_iterator requirement) it - n
            VectorIteratorReverse<Value> operator-(difference_type offset)
            {
                return this->_storagePtr + offset;
            }
            
            //(random_access_iterator requirement) it1 - it2
            difference_type operator-(const ft::VectorIteratorReverse<Value> & itRhs)
            {
                
                return -(this->_storagePtr - itRhs._storagePtr);
            }
            
            //(random_access_iterator requirement) a < b, a > b, a <= b, a >= b
            friend bool operator<(const VectorIteratorReverse &lhs, const VectorIteratorReverse &rhs)
            {
                return lhs._storagePtr > rhs._storagePtr;
            }
            friend bool operator>(const VectorIteratorReverse &lhs, const VectorIteratorReverse &rhs)
            {
                return lhs._storagePtr < rhs._storagePtr;
            }
            friend bool operator<=(const VectorIteratorReverse &lhs, const VectorIteratorReverse &rhs)
            {
                return lhs._storagePtr >= rhs._storagePtr;
            }
            friend bool operator>=(const VectorIteratorReverse &lhs, const VectorIteratorReverse &rhs)
            {
                return lhs._storagePtr <= rhs._storagePtr;
            }
            
            //(random_access_iterator requirement) it == it1 it != it1 
            
            //(random_access_iterator requirement) it += n
            VectorIteratorReverse<Value> &operator+=(VectorIteratorReverse<Value>::difference_type offset)
            {
                this->_storagePtr -= offset;
                return *this;
            }
            
            //(random_access_iterator requirement) it -= n
            VectorIteratorReverse<Value> &operator-=(typename VectorIteratorReverse<Value>::difference_type offset)
            {
                this->_storagePtr += offset;
                return *this;
            }
            
            //(random_access_iterator requirement) a[n]
            reference operator[] (difference_type idx)
            {
                return this->_storagePtr[idx];
            }
            
            //(random_access_iterator requirement) convertible to const_iterator
            operator VectorIteratorReverse<const value_type>()
            {
                const value_type *constStoragePtr = this->_storagePtr;
                return VectorIteratorReverse<const value_type>(constStoragePtr);
            }
    };
    //(random_access_iterator requirement) n + it
    template <typename Value>
    ft::VectorIteratorReverse<Value> operator+
    (
        typename ft::VectorIteratorReverse<Value>::difference_type offset, 
        ft::VectorIteratorReverse<Value> & it
    )
    {
        return ft::VectorIteratorReverse<Value>(&(*it) - offset);
    }
}

#endif