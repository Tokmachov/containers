#ifndef VECTOR_HPP
# define VECTOR_HPP 

# include "VectorIterator.hpp"
# include "VectorIteratorReverse.hpp"
# include "../utils.hpp"
# include <sys/time.h>

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
            typedef VectorIterator<T> iterator;
            typedef VectorIterator<const T> const_iterator;
            typedef VectorIteratorReverse<T> reverse_iterator;
            typedef VectorIteratorReverse<const T> const_reverse_iterator;
            typedef typename allocator_type::difference_type difference_type;
            typedef size_t size_type;

            //Constructors, destructors, assignment op
            explicit vector (const allocator_type& alloc = allocator_type())
                : _storage(0), _alloc(alloc), _elementsCount(0), _capacity(0) {}
            explicit vector 
            (
                size_type n, 
                const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()
            )
                : _storage(0), _alloc(alloc), _elementsCount(0), _capacity(0)
            {
                _storage = _alloc.allocate(n);
                _elementsCount = n;
                _capacity = n;
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_storage + i, val);
            }
            template <class InputIterator>
            vector 
            (
                InputIterator first, 
                typename enable_if<is_suitable_as_input_iterator<InputIterator>::value, InputIterator>::type last,
                const allocator_type& alloc = allocator_type()
            )
                : _storage(0), _alloc(alloc), _elementsCount(0), _capacity(0)
            {
                size_t dist = distance(first, last);
                _storage = _alloc.allocate(dist);
                _elementsCount = dist;
                _capacity = dist;
                dist = 0;
                for (;first != last; first++)
                {
                    _alloc.construct(_storage + dist, *first);
                    dist++;
                }
            }
            vector (const vector& x)
                : _storage(0), 
                _alloc(x._alloc), 
                _elementsCount(x._elementsCount), 
                _capacity(x._capacity)
            {
                _storage = _alloc.allocate(_capacity);
                int i = 0;
                typename ft::vector<value_type>::const_iterator it = x.begin();
                for (; it < x.end(); it++, i++)
                    _alloc.construct(_storage + i, *it);
            }
            ~vector()
            {
                _deleteStorageFromMemory();
            }
            //Iterators
            iterator begin()
            {
                return iterator(_storage);    
            }
            const_iterator begin() const
            {
                return const_iterator(_storage);
            }
            iterator end()
            {
                return iterator(_storage + _elementsCount);
            }
            const_iterator end() const
            {
                return const_iterator(_storage + _elementsCount);
            }
            reverse_iterator rbegin()
            {
                return reverse_iterator(_storage + _elementsCount - 1);
            }
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(_storage + _elementsCount - 1);
            }
            reverse_iterator rend()
            {
                return reverse_iterator(_storage - 1);
            }
            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(_storage - 1);
            }
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
            int _memAllocCount;
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