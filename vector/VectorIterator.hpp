#ifndif VECTORITERATOR_HPP
# define VECTORITERATOR_HPP
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
        friend VectorIterator<Value> &operator+=(difference_type offset);
        friend VectorIterator<Value> &operator-=(difference_type offset);
        VectorIterator<Value>() {}
        VectorIterator<Value>(const VectorIterator &src) 
            : VectorIteratorBase(src._storagePtr) {}
        VectorIterator &operator=(const VectorIterator &rhs)
        {
            _storagePtr = src._storagePtr;
        }
        Value &operator*() const { return *_storagePtr; };
        Value *operator->() const { return &(*_storagePtr); };
        VectorIterator &operator++()
        {
            _storage++;
            return this;
        }
        VectorIterator operator++(int)
        {
            VectorIterator tmp = *this;
            _storagePtr++;
            return tmp;
        }
        VectorIterator &operator--()
        {
            _storage--;
            return this;
        }
        VectorIterator operator--(int)
        {
            VectorIterator tmp = *this;
            _storagePtr--;
            return tmp;
        }
    private:
        //pointer value_addr;

};

template <typename Value>
VectorIterator<Value> &operator+(const VectorIterator<Value> & it, ptrdiff_t offset)
{
    it._storagePtr += offset;
}

VectorIterator<Value> &operator+(ptrdiff_t offset, const VectorIterator & it)
{
    it._storagePtr += offset;
}

VectorIterator<Value> &operator-(const VectorIterator & it, difference_type offset)
{
    it._storagePtr -= offset;
}
VectorIterator<Value> &operator-(difference_type offset, const VectorIterator & it)
{
    it._storagePtr -= offset;
}

VectorIterator<Value> &operator+=(difference_type offset)
{
    _storagePtr += offst;
    return this;
}
VectorIterator<Value> &operator-=(difference_type offset)
{
    _storagePtr -= offst;
    return this;
}

#endif