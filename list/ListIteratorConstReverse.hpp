#ifndef LISTITERATORCONSTREVERSE_HPP
#define LISTITERATORCONSTREVERSE_HPP

#include "ListIteratorConst.hpp"

template <typename Value>
class ListIteratorConstReverse : public ListIteratorConst<Value>
{
    public:
        typedef Value value_type;
        typedef ptrdiff_t difference_type;
        typedef Value* pointer;
        typedef Value& reference;
        typedef std::bidirectional_iterator_tag iterator_category;
        
        //bidirectional iterator requirements
        //Default constructible
        ListIteratorConstReverse(Node<Value> *node) : ListIteratorConst<Value>(node) {}
        ListIteratorConstReverse() {}
        //Copy-constructible
        ListIteratorConstReverse(const ListIteratorConstReverse<Value> &src)
            : ListIteratorConstReverse<Value>(src._currentElement) {}
        //Copy-assignable
        ListIteratorConstReverse<Value> &operator=(const ListIteratorConstReverse<Value> &rhs)
        {
            this->_currentElement = rhs._currentElement;
            return *this;
        }
        //++a
        ListIteratorConstReverse &operator++()
        { 
            this->_currentElement = this->_currentElement->prev;
            return *this; 
        };
        //a++
        ListIteratorConstReverse operator++(int) 
        { 

            ListIteratorConst<value_type> tmp = *this;
            this->_currentElement = this->_currentElement->prev;
            return tmp;
        }
        //--a
        ListIteratorConstReverse &operator--() 
        {
            this->_currentElement = this->_currentElement->next;
            return *this;
        }
        //a--
        ListIteratorConstReverse operator--(int)
        {
            ListIteratorConstReverse<Value> tmp = *this;
            this->_currentElement = this->_currentElement->next;
            return tmp;
        }      
};

#endif