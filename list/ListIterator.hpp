#ifndef LISTITERATOR_HPP
#define LISTITERATOR_HPP

#include "ListIteratorBase.hpp"
#include "ListIteratorConst.hpp"

template <typename Value>
class ListIterator : public ListIteratorBase<Value>
{
    public:
        typedef Value value_type;
        typedef ptrdiff_t difference_type;
        typedef Value* pointer;
        typedef Value& reference;
        typedef std::bidirectional_iterator_tag iterator_category;
        
        //bidirectional iterator requirements
        //Default constructible
        ListIterator(Node<Value> *node) : ListIteratorBase<Value>(node) {}
        ListIterator() {}
        //Copy-constructible
        ListIterator(const ListIterator<Value> &src)
            : ListIteratorBase<Value>(src._currentElement) {}
        //Copy-assignable
        ListIterator<Value> &operator=(const ListIterator<Value> &rhs)
        {
            this->_currentElement = rhs._currentElement;
            return *this;
        }
        //can be dereferenced as an rvalue (if in a dereferenceable state). *a a->m
        //Can be dereferenced as an lvalue (if in a dereferenceable state).
        Value &operator*() { return this->_currentElement->data; };
        Value *operator->() { return &(this->_currentElement->data); };
        //++a
        ListIterator &operator++() 
        { 
            this->_currentElement = this->_currentElement->next;
            return *this;
        };
        //a++
        ListIterator operator++(int) 
        { 

            ListIterator<value_type> tmp = *this;
            this->_currentElement = this->_currentElement->next;
            return tmp;
        }
        //--a
        ListIterator &operator--() 
        {
            this->_currentElement = this->_currentElement->prev;
            return *this;
        }
        //a--
        ListIterator operator--(int)
        {
            ListIterator<Value> tmp = *this;
            this->_currentElement = this->_currentElement->prev;
            return tmp;
        }
        //convertible to const_iterator
        operator ListIteratorConst<Value>() 
        {
            return ListIteratorConst<Value>(this->_currentElement);
        }
};

#endif