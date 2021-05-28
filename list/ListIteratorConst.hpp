#ifndef CONSTLISTITERATOR_HPP
#define CONSTLISTITERATOR_HPP

#include "ListIteratorBase.hpp"

template <typename Value>
class ListIteratorConst : public ListIteratorBase<Value>
{
    public:
        typedef Value value_type;
        typedef ptrdiff_t difference_type;
        typedef Value* pointer;
        typedef Value& reference;
        typedef std::bidirectional_iterator_tag iterator_category;
        
        //bidirectional iterator requirements
        //Default constructible
        ListIteratorConst(Node<Value> *node) : ListIteratorBase<Value>(node) {}
        ListIteratorConst() {}
        //Copy-constructible
        ListIteratorConst(const ListIteratorConst<Value> &src)
            : ListIteratorBase<Value>(src._currentElement) {}
        //Copy-assignable
        ListIteratorConst<Value> &operator=(const ListIteratorConst<Value> &rhs)
        {
            this->_currentElement = rhs._currentElement;
            return *this;
        }
        //can be dereferenced as an rvalue (if in a dereferenceable state). *a a->m
        const Value &operator*() const { return this->_currentElement->data; };
        const Value *operator->() const { return &(this->_currentElement->data); };
        //++a
        ListIteratorConst &operator++()
        { 
            this->_currentElement = this->_currentElement->next;
            return *this; 
        };
        //a++
        ListIteratorConst operator++(int) 
        { 

            ListIteratorConst<value_type> tmp = *this;
            this->_currentElement = this->_currentElement->next;
            return tmp;
        }
        //--a
        ListIteratorConst &operator--() 
        {
            this->_currentElement = this->_currentElement->prev;
            return *this;
        }
        //a--
        ListIteratorConst operator--(int)
        {
            ListIteratorConst<Value> tmp = *this;
            this->_currentElement = this->_currentElement->prev;
            return tmp;
        }
        
};

#endif