#ifndef VECTOR_HPP
# define VECTOR_HPP 

# include "VectorIterator.hpp"
# include "VectorIteratorReverse.hpp"
# include "../utils.hpp"
# include <memory>
# include <stdexcept>
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
                size_t dist = ft::distance(first, last);
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
                if (n > max_size())
                    throw std::length_error(std::string("vector"));
                if (n < _elementsCount)
                {
                    for (size_type i = n; i < _elementsCount; i++)
                        _alloc.destroy(_storage + i);
                    _elementsCount = n;
                }
                else if (n > _elementsCount)
                {
                    if (n >= _capacity)
                        _reallocStorage(_elementsCount, _capacity, n);
                    for (size_type i = _elementsCount; i < n; i++)
                        _alloc.construct(_storage + i, val);
                    _elementsCount = n;
                    _capacity = n;
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
                        "allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size"
                    );
                }
                if (n > _capacity)
                {
                    _reallocStorage(_elementsCount, _capacity, n);
                    _capacity = n;
                }
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
                        "vector"
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
                if (last < first)
                {
                    _destroyCurrentElements();
                    _alloc.deallocate(_storage, _capacity);
                    _storage = 0;
                    _capacity = 0;
                    throw std::length_error(std::string("vector"));
                }
                ft::vector<value_type> srcCopy(first, last);
                first = srcCopy.begin();
                last = srcCopy.end();
                _destroyCurrentElements();
                size_type sourceSize = ft::distance(first, last);
                if (sourceSize > _capacity)
                {
                    _reallocStorage(_elementsCount, _capacity, sourceSize);
                    _capacity = sourceSize;
                }
                for (size_type targetPos = 0; first != last; first++, targetPos++)
                    _alloc.construct(_storage + targetPos, *first);
                _elementsCount = sourceSize;
            }
            void assign (size_type n, const value_type& val)
            {
                _destroyCurrentElements();
                if (n > _capacity)
                {
                    _reallocStorage(_elementsCount, _capacity, n);
                    _capacity = n;
                }
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
            iterator insert (iterator position, const value_type& val)
            {
                value_type val_cpy = val;
                if (_elementsCount + 1 > _capacity)
                {
                    size_type newCapacity = (_capacity + 1) * 2;
                    size_type positionOffset = &(*position) - _storage;
                    _reallocStorage(_elementsCount, _capacity, newCapacity);
                    _capacity = newCapacity;
                    position = iterator(_storage + positionOffset);
                }
                size_type memMoveSize = _elementsCount - (&(*position) - _storage);
                _memMoveRight(&(*position), memMoveSize, 1);
                _alloc.construct(&(*position), val_cpy);
                _elementsCount++;
                return position;
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                value_type val_cpy = val;
                size_type newElementsCount = _elementsCount + n;
                if (newElementsCount > _capacity)
                {
                    size_type positionOffset = &(*position) - _storage;
                    _reallocStorage(_elementsCount, _capacity, newElementsCount);
                    _capacity = newElementsCount;
                    position = iterator(_storage + positionOffset);
                }
                size_type memMoveSize = _elementsCount - ((&(*position) - _storage));
                _memMoveRight(&(*position), memMoveSize, n);
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(&(*position) + i, val_cpy);
                _elementsCount = newElementsCount;
            }
            template <class InputIterator>
            void insert 
            (
                iterator position, 
                InputIterator first, 
                typename ft::enable_if<is_suitable_as_input_iterator<InputIterator>::value, InputIterator>::type last
            )
            {
                if (last < first)
                    return ;
                ft::vector<value_type> insertRangeCopy(first, last);
                first = insertRangeCopy.begin();
                last = insertRangeCopy.end();
                size_type nElementsToInsert = ft::distance(first, last);
                size_type newElementsCount = _elementsCount + nElementsToInsert;
                if (newElementsCount > _capacity)
                {
                    size_type positionOffset = &(*position) - _storage;
                    _reallocStorage(_elementsCount, _capacity, newElementsCount);
                    _capacity = newElementsCount;
                    position = iterator(_storage + positionOffset);
                }
                size_type memSize = _elementsCount - (&(*position) - _storage);
                _memMoveRight(&(*position), memSize, nElementsToInsert);
                for (size_type i = 0; i < nElementsToInsert; i++, first++)
                    _alloc.construct(&(*position) + i, *first);
                _elementsCount = newElementsCount;
            }
            iterator erase (iterator position)
            {
                _alloc.destroy(&(*position));
                size_type numberOfElementsToMoveLeft = _storage + _elementsCount - &(*position) - 1;
                _memMoveLeft(&(*position), &(*position) + 1, numberOfElementsToMoveLeft);
                _elementsCount--;
                return position;
            }
            iterator erase (iterator first, iterator last)
            {
                size_type elementsToMoveLeftCount = _storage + _elementsCount - &(*last);
                pointer dst = &(*first);
                pointer src = &(*last);
                _elementsCount -= last - first;
                iterator returnIterator = first;
                for (; first < last; first++)
                    _alloc.destroy(&(*first));
                _memMoveLeft(dst, src, elementsToMoveLeftCount);
                return returnIterator;
            }
            void swap (vector& x)
            {
                std::swap(_storage, x._storage);
                std::swap(_elementsCount, x._elementsCount);
                std::swap(_capacity, x._capacity);
            }
            void clear()
            {
               _destroyCurrentElements();
            }
            allocator_type get_allocator() const
            {
                return _alloc;
            }

        private:
            pointer _storage;
            allocator_type _alloc;
            size_type _elementsCount;
            size_type _capacity;
            //methods
            void _pushBack(value_type val)
            {
                if (_elementsCount == _capacity)
                {
                    size_type newCapacity = (_capacity + 1) * 2;
                    _reallocStorage(_elementsCount, _capacity, newCapacity);
                    _capacity = newCapacity;
                }
                _alloc.construct(_storage + _elementsCount, val);
                _elementsCount++;
            }
            void _reallocStorage(size_type _elementsCount, size_type currentCapacity, size_type newCapacity)
            {
                if (newCapacity <= currentCapacity)
                    throw std::invalid_argument("new capacity is invalid");
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
            }
            void _destroyCurrentElements()
            {
                for (size_t i = 0; i < _elementsCount; i++)
                    _alloc.destroy(_storage + i);
                _elementsCount = 0;
            }
            void _memMoveRight(pointer ptr, size_type memSize, size_type dst)
            {
                pointer newMemStart = ptr + dst;
                pointer newMemEnd = newMemStart + memSize;
                while (newMemEnd > newMemStart)
                {
                    _alloc.construct(newMemEnd - 1, *(newMemEnd - dst - 1));
                    _alloc.destroy(newMemEnd - dst - 1);
                    newMemEnd--;
                }
            }
            void _memMoveLeft(pointer dest, pointer src, size_type srcSize)
            {
                while (srcSize--)
                    _alloc.construct(dest++, *(src++));
            }
    };
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;        
        for (size_t i = 0; i < lhs.size(); i++)
        {
            if (lhs[i] != rhs[i])
                return false;
        }
        return true;
    }
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }
    template <class T, class Alloc>
    bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        size_t minLen = lhs.size() < rhs.size() ? lhs.size() : rhs.size();
        for (size_t i = 0; i < minLen; i++)
        {
            if (lhs[i] != rhs[i])
                return lhs[i] < rhs[i];
        }
        return lhs.size() < rhs.size();
    }
    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lhs < rhs) || (lhs == rhs);
    }
    template <class T, class Alloc>
    bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs <= rhs);
    }
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }
}

#endif