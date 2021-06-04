#ifndef VECTOR_HPP
# define VECTOR_HPP 

# include <stdexcept>
# include "VectorIterator.hpp"
# include "VectorIteratorReverse.hpp"
# include "../utils.hpp"
# include <memory>
# include <unistd.h>
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
            vector& operator= (const vector& x)
            {
                _destroyCurrentElements();
                _alloc.deallocate(_storage, _capacity);
                _storage = _alloc.allocate(x._capacity);
                _elementsCount = x._elementsCount;
                _capacity = x._capacity;
                for (size_type i = 0; i < _elementsCount; i++)
                {
                    _alloc.construct(_storage + i, x[i]);
                }
                return *this;
            }
            ~vector()
            {
                _destroyCurrentElements();
                _alloc.deallocate(_storage, _capacity);
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
            //Capacity:
            size_type size() const
            {
                return _elementsCount;
            }
            size_type max_size() const
            {
                return _alloc.max_size();
            }
            void resize (size_type n, value_type val = value_type())
            {
                if (n < _elementsCount)
                {
                    _destroyCurrentElements();
                    _elementsCount = n;
                }
                else if (n > _elementsCount)
                {
                    if (n >= _capacity)
                        _reallocStorage(n);
                    for (size_type i = _elementsCount; i < n; i++)
                        _alloc.construct(_storage + i, val);
                    _elementsCount = n;
                }
                else
                    return ;
            }
            size_type capacity() const
            {
                return _capacity;
            }
            bool empty() const
            {
                return (_elementsCount == 0);
            }
            void reserve (size_type n)
            {
                if (n > _alloc.max_size())
                {
                    throw std::length_error
                    (
                        "Exception in reserve method. N is greater than max_size."
                    );
                }
                if (n > _capacity)
                    _reallocStorage(n);
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
            reference at (size_type n)
            {
                if (n >= _elementsCount)
                {
                    std::string whatArg
                    (
                        "Exception in \"at\" method. N is out of range."
                    );
                    throw std::out_of_range(whatArg);
                }
                return _storage[n];
            }
            const_reference at (size_type n) const
            {
                if (n >= _elementsCount)
                {
                    std::string whatArg
                    (
                        "Exception in \"at\" method. N is out of range."
                    );
                    throw std::out_of_range(whatArg);
                }
                return _storage[n];
            }
            reference front()
            {
                return *_storage;
            }
            const_reference front() const
            {
                return *_storage;
            }
            reference back()
            {
                return *(_storage + _elementsCount - 1);
            }
            const_reference back() const
            {
                return *(_storage + _elementsCount - 1);
            }
            //Modifiers
            template <class InputIterator>
            void assign 
            (
                InputIterator first, 
                typename enable_if<is_suitable_as_input_iterator<InputIterator>::value, InputIterator>::type last
            )
            {
                _destroyCurrentElements();
                size_type sourceSize = ft::distance(first, last);
                if (sourceSize > _capacity)
                    _reallocStorage(sourceSize);
                for (size_type targetPos = 0; first != last; first++, targetPos++)
                    _alloc.construct(_storage + targetPos, *first);
                _elementsCount = sourceSize;
            }
            void assign (size_type n, const value_type& val)
            {
                _destroyCurrentElements();
                if (n > _capacity)
                    _reallocStorage(n);
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_storage + i, val);
                _elementsCount = n;
            }
            void push_back (const value_type& val)
            {
                _pushBack(val);
            }
            void pop_back()
            {
                if (_elementsCount == 0)
                    return ;
                _alloc.destroy(_storage + _elementsCount - 1);
                _elementsCount--;
            }
        private:
            pointer _storage;
            allocator_type _alloc;
            size_type _elementsCount;
            size_type _capacity;
            //methods
            void _pushBack(const value_type& val)
            {
                if (_elementsCount == _capacity)
                {
                    _reallocStorage();
                }
                _alloc.construct(_storage + _elementsCount, val);
                _elementsCount++;
            }
            void _reallocStorage(size_type newCapacity = 0)
            {
                if (newCapacity == 0 || newCapacity <= _capacity)
                    newCapacity = (_capacity + 1) * 2;
                pointer newStorage = _alloc.allocate(newCapacity);
                for (size_t i = 0; i < _elementsCount; i++)
                {
                    _alloc.construct(newStorage + i, *(_storage + i));
                    _alloc.destroy(_storage + i);
                }
                if (_storage != 0)
                {
                    _alloc.deallocate(_storage, _capacity);
                }
                _storage = newStorage;
                _capacity = newCapacity;
            }
            void _destroyCurrentElements()
            {
                for (size_t i = 0; i < _elementsCount; i++)
                    _alloc.destroy(_storage + i);
                _elementsCount = 0;
            }
    };
}

#endif