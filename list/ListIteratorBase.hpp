#ifndef LISTITERATORBASE_HPP
#define LISTITERATORBASE_HPP

# include "Node.hpp"

template <typename Value>
class ListIteratorBase
{
    friend class list;
    protected:
        Node<Value> *_currentElement;
        int el;
    public:
        
        ListIteratorBase() : _currentElement(0) {}
        ListIteratorBase(Node<Value> *n) : _currentElement(n) {}
        
        //a == b a != b
        bool operator==(const ListIteratorBase<Value> &rhs)
        {
            return _currentElement == rhs._currentElement;
        }
        bool operator!=(const ListIteratorBase<Value> &rhs)
        {
            return !(*this == rhs);
        }
};

#endif