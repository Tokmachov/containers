#ifndef VECTOR_HPP
# define VECTOR_HPP 

# include "VectorIterator.hpp"
# include "VectorIteratorConst.hpp"
# include "VectorIteratorReversed.hpp"
# include "VectorIteratorConstReverse.hpp"

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
            typedef ft::VectorIterator<T> iterator;
            typedef ft::VectorIteratorConst<T> const_iterator;
            typedef ft::VectorIteratorReversed<T> reverse_iterator;
            typedef ft::VectorIteratorConstReverse<T> const_reverse_iterator;
            typedef typename allocator_type::difference_type difference_type;
            typedef size_t size_type;

            //Constructors, destructors, assignment op
            explicit vector (const allocator_type& alloc = allocator_type())
                : _storage(0), _alloc(alloc), _elementsCount(0), _capacity(0) {}
            ~vector()
            {
                _deleteStorageFromMemory();
            }
            //Iterators
            // iterator begin()
            // {
                
            // }
            // const_iterator begin() const
            // {

            // }
            //Modifiers
            void push_back (const value_type& val)
            {
                _pushBack(val);
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
            //Element access:
            reference operator[] (size_type n)
            {
                return _storage[n];
            }
            const_reference operator[] (size_type n) const
            {
                return _storage[n];
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
                    _storage = _alloc.allocate(_capacity);
                    return ;
                }
                size_t prevCapacity = _capacity;
                _capacity *= 2;
                pointer newStorage = _alloc.allocate(_capacity);
                for (size_t i = 0; i < _elementsCount; i++)
                    _alloc.construct(newStorage + i, _storage[i]);
                for (size_t i = 0; i < _elementsCount; i++)
                    _alloc.destroy(_storage + i);
                _alloc.deallocate(_storage, prevCapacity);
                _storage = newStorage;
            }
    };
}

#endif