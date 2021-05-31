#ifndef VECTORITERATORCONST_HPP
# define VECTORITERATORCONST_HPP

namespace ft
{
    template <typename Value>
    class VectorIteratorConst : public VectorIteratorBase<Value>
    {
        public:
            typedef Value value_type;
            typedef ptrdiff_t difference_type;
            typedef Value* pointer;
            typedef Value& reference;
            typedef std::random_access_iterator_tag iterator_category;
            friend VectorIteratorConst<Value> &operator+(difference_type offset, const VectorIteratorConst<Value> & it);
            friend VectorIteratorConst<Value> &operator-(const VectorIteratorConst<Value> & it, difference_type offset);
            VectorIteratorConst<Value>() {}
            VectorIteratorConst<Value>(const VectorIteratorConst &src) 
                : VectorIteratorBase<Value>(src._storagePtr) {}
            VectorIteratorConst &operator=(const VectorIteratorConst &rhs)
            {
                this->_storagePtr = rhs._storagePtr;
                return *this;
            }
            const Value &operator*() const { return *this->_storagePtr; };
            const Value *operator->() const { return &(*this->_storagePtr); };
            VectorIteratorConst &operator++()
            {
                this->_storage++;
                return this;
            }
            VectorIteratorConst operator++(int)
            {
                VectorIteratorConst tmp = *this;
                this->_storagePtr++;
                return tmp;
            }
            VectorIteratorConst &operator--()
            {
                this->_storage--;
                return this;
            }
            VectorIteratorConst operator--(int)
            {
                VectorIteratorConst tmp = *this;
                this->_storagePtr--;
                return tmp;
            }
            VectorIteratorConst<Value> &operator+=(difference_type offset)
            {
                this->_storagePtr += offset;
                return *this;
            }
            VectorIteratorConst<Value> &operator-=(difference_type offset)
            {
                this->_storagePtr -= offset;
                return *this;
            }
            difference_type operator-(const ft::VectorIteratorConst<Value> & itRhs)
            {
                return this->_storagePtr - itRhs._storagePtr;
            }
            ft::VectorIteratorConst<Value> operator+(difference_type offset)
            {
                return this->_storagePtr + offset;
            }
            const value_type &operator[] (difference_type idx) const
            {
                return this->_storagePtr[idx];
            }
    };
}

template <typename Value>
ft::VectorIteratorConst<Value> operator+(typename ft::VectorIteratorConst<Value>::difference_type offset, const ft::VectorIteratorConst<Value> & it)
{    
    return it._storagePtr + offset;
}

template <typename Value>
ft::VectorIteratorConst<Value> &operator-(const ft::VectorIteratorConst<Value> & it, typename ft::VectorIteratorConst<Value>::difference_type offset)
{
    it._storagePtr -= offset;
    return it;
}

#endif