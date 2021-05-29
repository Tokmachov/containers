namespace ft
{
    template < class T, class Alloc = std::allocator<T> > 
    class vector
    {
        public:
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            //typedef iterator	a random access iterator to value_type
            //const_iterator	a random access iterator to const value_type
            //reverse_iterator	reverse_iterator<iterator>
            //const_reverse_iterator	reverse_iterator<const_iterator>
            //difference_type
            typedef size_t size_type;

            //Constructors, destructors, assignment op
            explicit vector (const allocator_type& alloc = allocator_type())
                : _storage(0), _alloc(alloc), _elementsCount(0), _capacity(0) {}
            ~vector()
            {
                _deleteStorageFromMemory();
            }
            //Modifiers
            void push_back (const value_type& val)
            {
                _pushBack();
            }
            //Capacity:
            size_type size() const
            {
                return _elementsCount;
            }
            size_type capacity() const
            {
                return _capacity;
            }
        private:
            pointer _storage;
            allocator_type _alloc;
            size_type _elementsCount;
            size_type _capacity;
            //methods
            void _deleteStorageFromMemory()
            {
                for (size_t i = 0; i < _elementsCount; i++)
                    _alloc.destroy(_storage + i);
                _alloc.deallocate(_storage, _capacity);
            }
            void _pushBack(const value_type& val)
            {
                if (_isOutOfCapacity())
                    _reallocStorage();
                _storage[_elementsCount++] = val;
            }
            bool _isOutOfCapacity()
            {
                return _elementsCount == _capacity;
            }
            void _reallocStorage()
            {
                if (_capacity == 0)
                {
                    _capacity = 1;
                    _storage = _alloc.alloc(_capacity);
                    return ;
                }
                size_t prevCapacity = _capacity;
                _capacity *= 2;
                pointer newStorage = _alloc.alloc(_capacity);
                for (size_t i = 0; i < _elementsCount; i++)
                    _alloc.construct(newStorage[i], _storage[i]);
                for (size_t i = 0; i < _elementsCount; i++)
                    _alloc.destroy(_storage[i]);
                _alloc.deallocate(_storage[prevCapacity]);
                _storage = newStorage;
            }
    };
}