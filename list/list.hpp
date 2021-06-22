#ifndef LIST_HPP
# define LIST_HPP

#include <memory>
#include <iostream>
#include "../utils.hpp"
#include <limits>

namespace ft
{
    template < class T, class Alloc = std::allocator<T> > 
    class list
    {
        #include "Node.hpp"
        #include "ListIteratorConst.hpp"
        #include "ListIterator.hpp"
        #include "ListIteratorConstReverse.hpp"
        #include "ListIteratorReverse.hpp"
        public:
            typedef T value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type:: template rebind< Node<value_type> >::other node_allocator;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef ListIterator<T> iterator;
            typedef ListIteratorConst<T> const_iterator;
            typedef ListIteratorReverse<T> reverse_iterator;
            typedef ListIteratorConstReverse<T> const_reverse_iterator;
            typedef typename std::iterator_traits<const_iterator>::difference_type difference_type;
            typedef size_t size_type;
            typedef Node<T> *node_ptr;
//----------------------------CONSTRUCTOR---------------------------------------
            explicit list(const allocator_type& alloc = allocator_type()) 
                : _allocator(alloc), _node_allocator() 
            {
                _past_the_end_node = _createNewNode();
                _link(_past_the_end_node, _past_the_end_node);
            }
            explicit list(size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type())
                : _allocator(alloc), _node_allocator()
            {
                _past_the_end_node = _createNewNode();
                _link(_past_the_end_node, _past_the_end_node);
                for (size_type i = 0; i < n; i++)
                {
                    Node<value_type> *newNode = _createNewNode(val);
                    _insertBefore(_past_the_end_node, newNode);
                }
             }
            template <class InputIterator>
            list 
            (
                InputIterator first,
                typename ft::enable_if<ft::is_suitable_as_input_iterator<InputIterator>::value, InputIterator>::type last,
                const allocator_type& alloc = allocator_type()
            )
                : _allocator(alloc), _node_allocator()
            {
                _past_the_end_node = _createNewNode();
                _link(_past_the_end_node, _past_the_end_node);
                for (; first != last; first++)
                {
                    Node<value_type> *newNode = _createNewNode(*first);
                    _insertBefore(_past_the_end_node, newNode);
                }
            }
            list (const list& x)
                : _allocator(x._allocator)
            {
                _past_the_end_node = _createNewNode();
                _link(_past_the_end_node, _past_the_end_node);
                const_iterator it_begin = x.begin();
                const_iterator it_end = x.end();
                for (;it_begin != it_end; it_begin++)
                    _insertBefore(_past_the_end_node, _createNewNode(*it_begin));
            };
            ~list()
            {
                _remove(_past_the_end_node->next, _past_the_end_node);
                _destroyAndDeallocate(_past_the_end_node);
            }
            list& operator= (const list& x)
            {
                _remove(_past_the_end_node->next, _past_the_end_node);
                _link(_past_the_end_node, _past_the_end_node);
                const_iterator it_begin = x.begin();
                const_iterator it_end = x.end();
                for (;it_begin != it_end; it_begin++)
                    _insertBefore(_past_the_end_node, _createNewNode(*it_begin));
                return *this;
            }
//----------------------------ITERATORS-----------------------------------------
            iterator begin()
            {
                return iterator(_past_the_end_node->next);
            }
            const_iterator begin() const
            {
                return const_iterator(_past_the_end_node->next);
            }
            iterator end()
            {
                return iterator(_past_the_end_node);
            }
            const_iterator end() const
            {
                return const_iterator(_past_the_end_node);
            }
            reverse_iterator rbegin()
            {
                return reverse_iterator(_past_the_end_node->prev);
            }
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(_past_the_end_node->prev);
            }
            reverse_iterator rend()
            {
                return reverse_iterator(_past_the_end_node);
            }
            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(_past_the_end_node);
            }
//----------------------------CAPACITY------------------------------------------
            size_type size() const
            {
                Node<value_type> *current = _past_the_end_node->next;
                size_type size = 0;
                while(current != _past_the_end_node)
                {
                    size++;
                    current = current->next;
                }
                return size;
            };
            bool empty() const
            {
                if (_past_the_end_node->next == _past_the_end_node)
                    return true;
                return false;
            }
            size_type max_size() const
            {
                return _node_allocator.max_size();
            }
//----------------------------OBSERVERS-----------------------------------------
            allocator_type get_allocator() const
            {
                return allocator_type(_allocator);
            };
//----------------------------ELEMENT_ACCESS:-----------------------------------
            reference front()
            {
                if (_past_the_end_node->next != _past_the_end_node)
                    return _past_the_end_node->next->data;
                return _past_the_end_node->data;
            };
            const_reference front() const
            {
                if (_past_the_end_node->next != _past_the_end_node)
                    return _past_the_end_node->next->data;
                return _past_the_end_node->data;
            };
            reference back()
            {
                if (_past_the_end_node->next != _past_the_end_node)
                    return _past_the_end_node->prev->data;
                return _past_the_end_node->data;
            }
            const_reference back() const
            {
                if (_past_the_end_node->next != _past_the_end_node)
                    return _past_the_end_node->prev->data;
                return _past_the_end_node->data;
            }
//-------------------------------MODIFIERS--------------------------------------
            template <class InputIterator>
            void assign 
            (
                InputIterator first, 
                typename ft::enable_if<ft::is_suitable_as_input_iterator<InputIterator>::value,InputIterator>::type last
            )
            {
                _remove(_past_the_end_node->next, _past_the_end_node);
                for (;first != last; first++)
                    _insertBefore(_past_the_end_node, _createNewNode(*first));
            }
            void assign (size_type n, const value_type& val)
            {
                _remove(_past_the_end_node->next, _past_the_end_node);
                for (size_t i = 0;i < n; i++)
                    _insertBefore(_past_the_end_node, _createNewNode(val));
            }
            void push_front (const value_type& val)
            {
                _insertBefore(_past_the_end_node->next, _createNewNode(val));
            }
            void pop_front() { _remove(_past_the_end_node->next); }
            void push_back(const value_type& val)
            {
                Node<value_type> *node = _createNewNode(val);
                _insertBefore(_past_the_end_node, node);
            }
            void pop_back() { _remove(_past_the_end_node->prev); }
            iterator insert (iterator position, const value_type& val)
            {
                Node<value_type> *newNode = _createNewNode(val);
                _insertBefore(position._currentElement, newNode);
                return iterator(newNode);
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                Node<value_type> *newNode;
                for (size_type i = 0; i < n; i++)
                {
                    newNode = _createNewNode(val);
                    _insertBefore(position._currentElement, newNode);
                }
            }
            template <class InputIterator>
            void insert 
            (
                iterator position, 
                InputIterator first, 
                typename ft::enable_if<is_suitable_as_input_iterator<InputIterator>::value, InputIterator>::type last
            )
            {
                for(;first != last; first++)
                {
                    Node<value_type> *newNode = _createNewNode(*first);
                    _insertBefore(position._currentElement, newNode);
                }
            }
            iterator erase (iterator position)
            {
                iterator toReturn = iterator(position._currentElement->next);
                _remove(position._currentElement);
                return toReturn;
            }
            iterator erase (iterator first, iterator last)
            {
                _remove(first._currentElement, last._currentElement);
                return last;
            }
            void swap (list& x)
            {
                std::swap(_past_the_end_node, x._past_the_end_node);
            }
            void resize (size_type n, value_type val = value_type())
            {
                Node<value_type> *current = _past_the_end_node->next;
                size_t size = 0;
                for (; size != n && current != _past_the_end_node; size++, current = current->next) {}
                if (size == n)
                    _remove(current, _past_the_end_node);
                else if (current == _past_the_end_node)
                {
                    for (; size < n; size++)
                    {
                        Node<value_type> *newNode = _createNewNode(val);
                        _insertBefore(_past_the_end_node, newNode);
                    }
                }
            }
            void clear()
            {
                _remove(_past_the_end_node->next, _past_the_end_node);
            }
            
//-------------------------------OPERATIONS-------------------------------------
        void splice (iterator position, list& x)
        {
            if (x.empty())
                return ;
            Node<value_type> *firstXNode = x._past_the_end_node->next;
            Node<value_type> *lastXNode = x._past_the_end_node->prev;
            _link(position._currentElement->prev, firstXNode);
            _link(lastXNode, position._currentElement);
            _link(x._past_the_end_node, x._past_the_end_node);
        }
        void splice (iterator position, list& x, iterator i)
        {
            if (x.empty())
                return ;
            _link(i._currentElement->prev, i._currentElement->next);
            _insertBefore(position._currentElement, i._currentElement);
        }
        void splice (iterator position, list& x, iterator first, iterator last)
        {
            if (x.empty())
                return ;
            Node<value_type> *targetStart = position._currentElement->prev;
            Node<value_type> *targetEnd = position._currentElement;
            Node<value_type> *rangeStart = first._currentElement;
            Node<value_type> *rangeEnd = last._currentElement->prev;
            Node<value_type> *sourceStartLoseEnd = first._currentElement->prev;
            Node<value_type> *sourceEndLoseEnd = last._currentElement;
            _link(sourceStartLoseEnd, sourceEndLoseEnd);
            _link(targetStart, rangeStart);
            _link(rangeEnd, targetEnd);
        }
        void remove (const value_type& val)
        {
            node_ptr current = _past_the_end_node->next;
            while (current != _past_the_end_node)
            {
                node_ptr prev = current;
                current = current->next;
                if (prev->data == val)
                    _remove(prev);
            }
        }
        template <class Predicate>
        void remove_if (Predicate pred)
        {
            node_ptr current = _past_the_end_node->next;
            while (current != _past_the_end_node)
            {
                node_ptr prev = current;
                current = current->next;
                if (pred(prev->data))
                    _remove(prev);
            }
        }
        void unique()
        {
            node_ptr current = _past_the_end_node->next;
            pointer el = 0;
            while (current != _past_the_end_node)
            {
                node_ptr prev = current;
                current = current->next;
                if (el != 0 && *el == prev->data)
                    _remove(prev);
                else
                    el = &prev->data;
            }
        }
        template <class BinaryPredicate>
        void unique (BinaryPredicate binary_pred)
        {
            node_ptr current = _past_the_end_node->next;
            pointer el = 0;
            while (current != _past_the_end_node)
            {
                node_ptr prev = current;
                current = current->next;
                if (el != 0 && binary_pred(*el, prev->data))
                    _remove(prev);
                else
                    el = &prev->data;
            }   
        }
        void merge (list& x)
        {
            if (&x == this)
                return ;
            node_ptr targetFirst = _past_the_end_node->next;
            node_ptr targetLast = _past_the_end_node;
            node_ptr srcFirst = x._past_the_end_node->next;
            node_ptr srcLast = x._past_the_end_node;
            _merge(targetFirst, targetLast, srcFirst, srcLast, isLeftStrictlyLessThenRight);
        }
        template <class Compare>
        void merge (list& x, Compare comp)
        {
            if (&x == this)
                return ;
            node_ptr targetFirst = _past_the_end_node->next;
            node_ptr targetLast = _past_the_end_node;
            node_ptr srcFirst = x._past_the_end_node->next;
            node_ptr srcLast = x._past_the_end_node;
            _merge(targetFirst, targetLast, srcFirst, srcLast, comp);
        }
        void sort()
        {
            _sort(isLeftStrictlyLessThenRight);
        }
        template <class Compare>
        void sort (Compare comp)
        {
            _sort(comp);
        }
        void reverse()
        {
            node_ptr current = _past_the_end_node->next;
            node_ptr newNext;
            node_ptr newPrev;
            while (current != _past_the_end_node)
            {
                newNext = current->prev;
                newPrev = current->next;
                node_ptr nodeToReverse = current;
                current = current->next;
                nodeToReverse->next = newNext;
                nodeToReverse->prev = newPrev;
            }
            newNext = current->prev;
            newPrev = current->next;
            current->next = newNext;
            current->prev = newPrev;
        }
        private:
            allocator_type _allocator;
            node_allocator _node_allocator;
            Node<T> *_past_the_end_node;

            //methods
            Node<value_type> *_createNewNode(const value_type &data = value_type())
            {
                Node<value_type> *node = _node_allocator.allocate(1);
                _node_allocator.construct(node, Node<value_type>(data));
                return node;
            }
            void _insertBefore(Node<value_type> *nextNode, Node<value_type> *nodeToInsert)
            {
                Node<value_type> *prev = nextNode->prev;
                _link(prev, nodeToInsert);
                _link(nodeToInsert, nextNode);
            }
            void _remove(Node<value_type> *node)
            {
                _link(node->prev, node->next); 
                _allocator.destroy(&node->data);
                _destroyAndDeallocate(node);
            } 
            void _remove(Node<value_type> *first, Node<value_type> *last)
            {
                _link(first->prev, last);
                while (first != last)
                {
                    node_ptr toDelete = first;
                    first = first->next;
                    _destroyAndDeallocate(toDelete);
                }
            }
            static bool isLeftStrictlyLessThenRight(value_type left, value_type right)
            {
                return (left < right);
            }
            template <typename CompareFunc>
            void _merge
            (
                node_ptr targetFirst, 
                node_ptr targetLast, 
                node_ptr srcFirst,
                node_ptr srcLast,
                CompareFunc comp
            )
            {
                node_ptr resultStart = _past_the_end_node;
                node_ptr nodeToMove;
                while ((targetFirst != targetLast) || (srcFirst != srcLast))
                {
                    //source goes to result list
                    if ((srcFirst != srcLast) && ((targetFirst == targetLast) || comp(srcFirst->data, targetFirst->data)))
                    {
                        nodeToMove = srcFirst;
                        srcFirst = srcFirst->next;
                        _link(resultStart, nodeToMove);
                        resultStart = nodeToMove;
                        continue ;   
                    }
                    //target goes to result list
                    if (((targetFirst != targetLast) && (srcFirst == srcLast)) || !(comp(srcFirst->data, targetFirst->data)))
                    {
                        nodeToMove = targetFirst;
                        targetFirst = targetFirst->next;
                        _link(resultStart, nodeToMove);
                        resultStart = nodeToMove;
                        continue ;
                    }
                }
                _link(resultStart, _past_the_end_node);
                _link(srcLast, srcLast);
            }
            template <typename CompareFunc>
            void _insertInOrder(node_ptr start, node_ptr *last, node_ptr el, CompareFunc comp)
            {
                if (start == *last)
                {
                    _link(start, el);
                    *last = el;
                    return ;
                }
                node_ptr lastTmp = *last;
                while (lastTmp != start)
                {
                    if (comp(lastTmp->data, el->data))
                    {
                        if (lastTmp == *last)
                        {
                            _link(lastTmp, el);
                            *last = el;
                        }
                        else
                        {
                            _link(el, lastTmp->next);
                            _link(lastTmp, el);
                        }
                        return ;
                    }
                    lastTmp = lastTmp->prev;
                }
                _link(el, lastTmp->next);
                _link(lastTmp, el);
            }
            template <typename CompareFunc>
            void _sort(CompareFunc comp)
            {
                node_ptr start = _past_the_end_node->next;
                node_ptr last = _past_the_end_node;
                if (start == last)
                    return ;
                node_ptr resultStart =  _past_the_end_node;
                node_ptr resultLast = resultStart;
                while (start != last)
                {
                    node_ptr elToInsert = start;
                    start = start->next;
                    _insertInOrder(resultStart, &resultLast, elToInsert, comp);
                }
                _link(resultLast, _past_the_end_node);
            }
            
            void _destroyAndDeallocate(Node<value_type> *n)
            {
                _node_allocator.destroy(n);
                _node_allocator.deallocate(n, 1);
            }
            void _link(Node<value_type> *prev, Node<value_type> *next)
            {
                prev->next = next;
                next->prev = prev;
            }
    };

    template <class T, class Alloc>
    bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        typename list<T>::const_iterator itLeftBegin = lhs.begin();
        typename list<T>::const_iterator itLeftEnd = lhs.end();
        typename list<T>::const_iterator itRightBegin = rhs.begin();
        for (;itLeftBegin != itLeftEnd; itLeftBegin++, itRightBegin++)
        {
            if (*itLeftBegin != *itRightBegin)
                return false;
        }
        return true;
    }

    template <class T, class Alloc>
    bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }
    template <class T, class Alloc>
    bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        typename list<T>::const_iterator itLeftBegin = lhs.begin();
        typename list<T>::const_iterator itLeftEnd = lhs.end();
        typename list<T>::const_iterator itRightBegin = rhs.begin();
        typename list<T>::const_iterator itRightEnd = rhs.end();
        for (;(itLeftBegin != itLeftEnd) && (itRightBegin != itRightEnd); itLeftBegin++, itRightBegin++)
        {
            if (*itLeftBegin != *itRightBegin)
                return *itLeftBegin < *itRightBegin;
        }
        if ((itLeftBegin == itLeftEnd) && (itRightBegin != itRightEnd))
            return true;
        return false;
    }

    template <class T, class Alloc>
    bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return (lhs < rhs) || (lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(lhs < rhs) && !(lhs == rhs);
    }

    template <class T, class Alloc>
    bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }

    template <class T, class Alloc>
    void swap (list<T,Alloc>& x, list<T,Alloc>& y)
    {
        x.swap(y);
    }
}

#endif

