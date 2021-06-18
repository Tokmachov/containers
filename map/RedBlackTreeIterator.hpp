#ifndef REDBLACKTREEITERATOR_HPP
#define REDBLACKTREEITERATOR_HPP

namespace ft
{
    template <typename Node, typename Value>
    class RedBlackTreeIterator
    {
        public:
            typedef Value value_type;
            typedef Node node_type;
            typedef ptrdiff_t difference_type;
            typedef size_t size_type;
            typedef value_type *pointer;
            typedef value_type& reference;
            typedef std::bidirectional_iterator_tag iterator_category;
            RedBlackTreeIterator(node_type *minNode, node_type *tnull) : _node(minNode), _tnull(tnull) {}
            //bidirectional iterator requirements
            //X a;
            RedBlackTreeIterator() {}
            //X b(a);
             RedBlackTreeIterator(const RedBlackTreeIterator &src)
                : _node(src._node), _tnull(src._tnull) {}
            //b = a;
            //Copy-assignable
            RedBlackTreeIterator &operator=(const RedBlackTreeIterator &rhs)
            {
                _node = rhs._node;
                _tnull = rhs._tnull;
                return *this;
            }
            //a == b
            bool operator==(const RedBlackTreeIterator &rhs)
            {
                return _node == rhs._node;
            }
            //a != b
            bool operator!=(const RedBlackTreeIterator &rhs)
            {
                return !(*this == rhs);
            }
            //*a
            reference operator*() 
            {
                return _node->value;; 
            };
            //a->m
            pointer operator->() { return &(_node->value); };
            //++a
            RedBlackTreeIterator &operator++()
            { 
                _node = _nextNode();
                return *this;
            };
            //a++
            RedBlackTreeIterator operator++(int) 
            {
                RedBlackTreeIterator tmp = *this;
                ++(*this);
                return tmp;
            }
            //--a
            RedBlackTreeIterator &operator--() 
            {
                _node = _prevNode();
                return *this;
            }
            //a--
            RedBlackTreeIterator operator--(int)
            {
                RedBlackTreeIterator tmp = *this;
                --(*this);
                return tmp;
            }
            //convertible to const_iterator
            operator RedBlackTreeIterator<node_type, const value_type>()
            {
                return RedBlackTreeIterator<node_type, const value_type>(_node, _tnull);
            }
            #define STOP 0
            #define LEFT 1
            #define RIGHT 2
            #define PARENT 3
            Node *_node;
            Node *_tnull;
            Node *_nextNode()
            {
                if (_node == _tnull)
                    return _tnull->right;
                int prevPos = STOP;
                Node *prev = 0;
                while (true)
                {
                    prev = _node;
                    if (prevPos == STOP)
                    {
                        _node = _nextFromStop(_node);
                        if (!_node)
                            return _tnull; //all elements traversed
                        prevPos = getPrevPos(prev, _node);
                    }
                    else if (prevPos == LEFT)
                    {
                        return _node;
                    }
                    else if (prevPos == RIGHT)
                    {
                        prev = _node;
                        _node = _node->parent;
                        if (_node == 0)
                            return _tnull; //all elements traversed
                        prevPos = getPrevPos(prev, _node);
                    }
                    else if (prevPos == PARENT)
                    {
                        _node = moveFromParent(_node);
                        if (prev == _node)
                            return _node;
                        else
                            prevPos = getPrevPos(prev, _node);
                    }
                }
            }
            Node *_nextFromStop(Node *n)
            {
                if (n->right != _tnull)
                    return n->right;
                return n->parent;
            }
            Node *moveFromParent(Node *_node)
            {
                if (_node->left != _tnull)
                    return _node = _node->left;
                return _node;
            }
            
            Node *_prevNode()
            {
                if (_node == _tnull)
                    return _tnull->left;
                int prevPos = STOP;
                Node *prev = 0;
                while (true)
                {
                    prev = _node;
                    if (prevPos == STOP)
                    {
                        _node = _moveFromStopPositionBack(_node);
                        if (!_node)
                            return _tnull; //all elements traversed
                        prevPos = getPrevPos(prev, _node);
                    }
                    else if (prevPos == RIGHT)
                    {
                        return _node;
                    }
                    else if (prevPos == LEFT)
                    {
                        prev = _node;
                        _node = _node->parent;
                        if (_node == 0)
                            return _tnull; //all elements traversed
                        prevPos = getPrevPos(prev, _node);
                    }
                    else if (prevPos == PARENT)
                    {
                        _node = moveFromParentBack(_node);
                        if (prev == _node)
                            return _node;
                        else
                            prevPos = getPrevPos(prev, _node);
                    }
                }
            }
            Node *_moveFromStopPositionBack(Node *n)
            {
                if (n->left != _tnull)
                    return n->left;
                return n->parent;
            }
            Node *moveFromParentBack(Node *_node)
            {
                if (_node->right != _tnull)
                    return _node = _node->right;
                return _node;
            }
            int getPrevPos(Node *prev, Node *curr)
            {
                if (prev == curr->left)
                    return LEFT;
                if (prev == curr->right)
                    return RIGHT;
                return PARENT;
            }
    };
    
}
#endif