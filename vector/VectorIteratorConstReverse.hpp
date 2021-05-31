#ifndef VECTORITERATORCONSTREVERSE_HPP
# define VECTORITERATORCONSTREVERSE_HPP

namespace ft
{
    template <typename Value>
    class VectorIteratorConstReverse : public VectorIteratorBase<Value>
    {
        public:
            typedef Value value_type;
            typedef ptrdiff_t difference_type;
            typedef Value* pointer;
            typedef Value& reference;
            typedef std::random_access_iterator_tag iterator_category;
            friend VectorIteratorConstReverse<Value> &operator+(const VectorIteratorConstReverse & it, difference_type offset);
            friend VectorIteratorConstReverse<Value> &operator+(difference_type offset, const VectorIteratorConstReverse & it);
            friend VectorIteratorConstReverse<Value> &operator-(const VectorIteratorConstReverse & it, difference_type offset);
            friend VectorIteratorConstReverse<Value> &operator-(difference_type offset, const VectorIteratorConstReverse & it);
            VectorIteratorConstReverse<Value>() {}
            VectorIteratorConstReverse<Value>(const VectorIteratorConstReverse &src) 
                : VectorIteratorBase<Value>(src._storagePtr) {}
            VectorIteratorConstReverse &operator=(const VectorIteratorConstReverse &rhs)
            {
                this->_storagePtr = rhs._storagePtr;
            }
            VectorIteratorConstReverse &operator++()
            {
                this->_storage--;
                return this;
            }
            VectorIteratorConstReverse operator++(int)
            {
                VectorIteratorConstReverse tmp = *this;
                this->_storagePtr--;
                return tmp;
            }
            VectorIteratorConstReverse &operator--()
            {
                this->_storage++;
                return this;
            }
            VectorIteratorConstReverse operator--(int)
            {
                VectorIteratorConstReverse tmp = *this;
                this->_storagePtr++;
                return tmp;
            }
            VectorIteratorConstReverse<Value> &operator+=(difference_type offset)
            {
                this->_storagePtr -= offset;
                return this;
            }
            VectorIteratorConstReverse<Value> &operator-=(difference_type offset)
            {
                this->_storagePtr += offset;
                return this;
            }
    };
}

template <typename Value>
ft::VectorIteratorConstReverse<Value> &operator+(const ft::VectorIteratorConstReverse<Value> & it, typename ft::VectorIteratorConstReverse<Value>::difference_type offset)
{
    it._storagePtr -= offset;
    return it;
}

template <typename Value>
ft::VectorIteratorConstReverse<Value> &operator+(typename ft::VectorIteratorConstReverse<Value>::difference_type offset, const ft::VectorIteratorConstReverse<Value> & it)
{
    it._storagePtr -= offset;
    return it;
}

template <typename Value>
ft::VectorIteratorConstReverse<Value> &operator-(const ft::VectorIteratorConstReverse<Value> & it, typename ft::VectorIteratorConstReverse<Value>::difference_type offset)
{
    it._storagePtr += offset;
    return it;
}

template <typename Value>
ft::VectorIteratorConstReverse<Value> &operator-(typename ft::VectorIteratorConstReverse<Value>::difference_type offset, const ft::VectorIteratorConstReverse<Value> & it)
{
    it._storagePtr += offset;
    return it;
}

#endif