#ifndef LISTITERATORREVERSE_HPP
#define LISTITERATORREVERSE_HPP

#include "ListIterator.hpp"
#include "ListIteratorConstReverse.hpp"

template <typename Value >
class ListIteratorReverse : public ListIterator<Value>
{
    public:
    //bidirectional iterator requirements
    //Default constructible
    ListIteratorReverse(Node<Value> *node) : ListIterator<Value>(node) {}
    ListIteratorReverse() {}
    //Copy-constructible
    ListIteratorReverse(const ListIteratorReverse<Value> &src)
        : ListIterator<Value>(src._currentElement) {}
    //Copy-assignable
    ListIteratorReverse<Value> &operator=(const ListIteratorReverse<Value> &rhs)
    {
        this->_currentElement = rhs._currentElement;
        return *this;
    }
    ListIteratorReverse &operator++() 
    { 
        this->_currentElement = this->_currentElement->prev;
        return *this;
    };
    //a++
    ListIteratorReverse operator++(int) 
    {
        ListIteratorReverse<value_type> tmp = *this;
        this->_currentElement = this->_currentElement->prev;
        return tmp;
    }
    //--a
    ListIteratorReverse &operator--() 
    {
        this->_currentElement = this->_currentElement->next;
        return *this;
    }
    //a--
    ListIteratorReverse operator--(int)
    {
        ListIteratorReverse<Value> tmp = *this;
        this->_currentElement = this->_currentElement->next;
        return tmp;
    }
    //convertible to const_iterator
    operator ListIteratorReverse<Value>() 
    {
        return ListIteratorConstReverse<Value>(this->_currentElement);
    }
};

#endif