#ifndef MAP_HPP
# define MAP_HPP

# include "RedBlackTreeIterator.hpp"
# include "../utils.hpp"

namespace ft
{
    template 
    < 
        class Key,                                     // map::key_type
        class T,                                       // map::mapped_type
        class Compare = std::less<Key>,                     // map::key_compare
        class Alloc = std::allocator<std::pair<const Key,T> >    // map::allocator_type
    > 
    class map
    {
        public:
            typedef Key key_type;
            typedef T mapped_type;
            typedef std::pair<const key_type, mapped_type> value_type;
            typedef Compare key_compare;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            class value_compare
            {
                private:
                    key_compare comp;
                public:
                    value_compare(key_compare c) : comp(c) {} 
                    bool operator() (const value_type& x, const value_type& y) const
                    {
                        return comp(x.first, y.first);
                    }
            };
            enum NodeColor
            {
                red,
                black
            };
            template <typename Value>
            struct Node
            {
                typedef Value value_type;
                Node(value_type v, Node *p, Node *l, Node *r, NodeColor c)
                    : value(v), parent(p), left(l), right(r), color(c) {}
                Value value;
                Node *parent;
                Node *left;
                Node *right;
                NodeColor color; 
            };
            typedef Node<value_type> node;
            typedef typename Alloc:: template rebind< node >::other node_allocator;
            typedef typename node_allocator::pointer node_ptr;
            typedef typename node_allocator::pointer const_node_ptr;
            typedef RedBlackTreeIterator<node, value_type> iterator;
            typedef RedBlackTreeIterator<node, const value_type> const_iterator;
            typedef ReverseIterator<iterator> reverse_iterator;
            typedef ReverseIterator<iterator, const typename iterator::value_type> const_reverse_iterator;
            typedef typename std::iterator_traits<iterator>::difference_type size_type;
            //constructors
            explicit map
            (
                const key_compare& compLessKey = key_compare(), 
                const allocator_type& alloc = allocator_type()
            ) 
                : _node_alloc(node_allocator()),
                _alloc(alloc),
                _compLessPair(compLessKey), 
                _compLessKey(compLessKey),
                _size(0)
            { 
                _emptyNode = _makeEmptyNode();
                _root = _emptyNode;
                _updateMinMaxElementPassNode(_root, _emptyNode);
            }
            template <class InputIterator>
            map
            (
                InputIterator first, 
                InputIterator last,
                const key_compare& compLessKey = key_compare(),
                const allocator_type& alloc = allocator_type()
            )
                : _node_alloc(node_allocator()),
                _alloc(alloc),
                _compLessPair(compLessKey),
                _compLessKey(compLessKey),
                _size(0)
            {
                _emptyNode = _makeEmptyNode();
                _root = _emptyNode;
                for (;first != last; first++)
                    insert(*first);
            }
            map (const map& x)
                : _node_alloc(x._node_alloc),
                _alloc(x._alloc),
                _compLessPair(x._compLessPair),
                _compLessKey(x._compLessKey)
            {
                _emptyNode = _makeEmptyNode();
                _root = _emptyNode;
                for (const_iterator it = x.begin();it != x.end(); ++it)
                    insert(*it);
            }
            ~map() { _deallocateAndDestroyTree(); };
            map& operator= (const map& x) 
            { 
                _deallocateAndDestroyTree();
                _emptyNode = _makeEmptyNode();
                _root = _emptyNode;
                _compLessPair = x._compLessPair;
                _compLessKey = x._compLessKey;
                for (const_iterator it = x.begin();it != x.end(); ++it)
                    insert(*it);
                return *this;
            }
            //Iterators
            iterator begin()
            {
                return iterator(_getMinNode(_root), _emptyNode);
            }
            const_iterator begin() const
            {
                return const_iterator(_getMinNode(_root), _emptyNode);
            }
            iterator end()
            {
                return iterator(_emptyNode, _emptyNode);
            }
            const_iterator end() const
            {
                return const_iterator(_emptyNode, _emptyNode);
            }
            reverse_iterator rbegin()
            {
                return reverse_iterator(end());
            }
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(end());
            }
            reverse_iterator rend()
            {
                return reverse_iterator(end());
            }
            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(end());
            }
            //Modifiers
            std::pair<iterator, bool> insert(value_type value)
            {
                node_ptr nodeToInsert = _makeRedNode(value);
                node_ptr parent = 0;
                node_ptr current = this->_root;
                while (current != _emptyNode) 
                {
                    parent = current;
                    if (_compLessPair(nodeToInsert->value, current->value))
                        current = current->left;
                    else if (_compLessPair(current->value, nodeToInsert->value))
                        current = current->right;
                    else
                    {
                        _deallocateAndDestroyNode(nodeToInsert);
                        return std::pair<iterator, bool>(iterator(current, _emptyNode), false);
                    }
                }
                nodeToInsert->parent = parent;
                if (parent == 0)
                    _root = nodeToInsert;
                else if (nodeToInsert->value < parent->value)
                    parent->left = nodeToInsert;
                else
                    parent->right = nodeToInsert;
                _size++;
                _updateMinMaxElementPassNode(_root, _emptyNode);
                if (nodeToInsert->parent == 0)
                {
                    nodeToInsert->color = black;
                    return std::pair<iterator, bool>(iterator(nodeToInsert, _emptyNode), true);
                }
                if (nodeToInsert->parent->parent == 0) {
                    return std::pair<iterator, bool>(iterator(nodeToInsert, _emptyNode), true);
                }
                _insertBalance(nodeToInsert);
                return std::pair<iterator, bool>(iterator(nodeToInsert, _emptyNode), true);
            }
            iterator insert (iterator position, const value_type& val)
            {
                (void)position;
                return (insert(val)).first;
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                for (;first != last; first++)
                    insert(*first);
            }
            void erase (iterator position)
            {
                _deleteNode(_root, position->first);
            }
            size_type erase (const key_type& k)
            {
                return _deleteNode(_root, k);
            }
            void erase (iterator first, iterator last)
            {
                for (;first != last; first++)
                    erase(first);
            }
            void swap (map& x)
            {
                std::swap(_node_alloc, x._node_alloc);
                std::swap(_root, x._root);
                std::swap(_emptyNode, x._emptyNode);
                std::swap(_compLessPair, x._compLessPair);
                std::swap(_size, x._size);
            }
            void clear()
            {
                _deallocateAndDestroyValueNodes(_root);
                _root = _emptyNode;
                _emptyNode->left = 0;
                _emptyNode->right = 0;
                _updateMinMaxElementPassNode(_root, _emptyNode);
                _size = 0;
            }
            //Capacity:
            bool empty() const
            {
                return (_size == 0);
            }
            size_type size() const
            {
                return _size;
            }
            size_type max_size() const
            {
                return _node_alloc.max_size();
            }
            //Element access:
            mapped_type& operator[] (const key_type& k)
            {
                iterator it = (insert(value_type(k, mapped_type()))).first;
                return it->second;
            }
            //Observers:
            key_compare key_comp() const
            {
                return _compLessKey;
            }
            value_compare value_comp() const
            {
                return _compLessPair;
            }
            //Operations:
            iterator find (const key_type& k)
            {
                node_ptr nPtr = _searchTree(_root, k);
                return iterator(nPtr, _emptyNode);
            }
            const_iterator find (const key_type& k) const
            {
                node_ptr nPtr = _searchTree(_root, k);
                return const_iterator(nPtr, _emptyNode);
            }
            size_type count (const key_type& k) const
            {
                if (_searchTree(_root, k) != _emptyNode)
                    return 1;
                return 0;
            }
            iterator lower_bound (const key_type& k)
            {
                iterator it = begin();
                for (; it != end(); it++)
                {
                    if ((_compLessKey(it->first, k)) == false)
                        return it;
                }
                return it;
            }
            const_iterator lower_bound (const key_type& k) const
            {
                return lower_bound(k);
            }
            iterator upper_bound (const key_type& k)
            {
                iterator it = begin();
                for (; it != end(); it++)
                {
                    if ((_compLessKey(k, it->first)) == true)
                        return it;
                }
                return it;
            }
            const_iterator upper_bound (const key_type& k) const
            {
                return upper_bound(k);
            }
            std::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                return equal_range(k);
            }
            std::pair<iterator,iterator> equal_range (const key_type& k)
            {
                std::pair<iterator, iterator> range
                (
                    lower_bound(k), 
                    upper_bound(k)
                );
                return range;
            }
            //Allocator:
            allocator_type get_allocator() const
            {
                return _alloc;
            }
            const_node_ptr getRoot() const
            {
                return _root;
            }
            const_node_ptr getEmptyNode() const
            {
                return _emptyNode;
            }
        private:
            node_allocator _node_alloc;
            allocator_type _alloc;
            node_ptr _root;
            node_ptr _emptyNode;
            value_compare _compLessPair;
            key_compare _compLessKey;
            size_type _size;
            
            node_ptr _makeEmptyNode()
            {
                node_ptr nPtr = _node_alloc.allocate(1);
                nPtr->color = black;
                nPtr->left = 0;
                nPtr->right = 0;
                return nPtr;
            }
            node_ptr _makeRedNode(const value_type &v)
            {
                node_ptr nPtr = _node_alloc.allocate(1);
                _node_alloc.construct(nPtr, node(v, 0, _emptyNode, _emptyNode, red));    
                return nPtr;
            }
            node_ptr _searchTree(node_ptr node, const key_type &k) const
            {
                if (node == _emptyNode || _areEqual(node->value.first, k))
                    return node;
                if (_compLessKey(k, node->value.first))
                    return _searchTree(node->left, k);
                return _searchTree(node->right, k);
            }
            
            bool _areEqual(const key_type &k1, const key_type &k2) const
            {
                return (!_compLessKey(k1, k2) && !_compLessKey(k2, k1));
            }
            void _insertBalance(node_ptr k)
            {
                node_ptr u;
                while (k->parent->color == red) 
                {
                if (k->parent == k->parent->parent->right) 
                {
                    u = k->parent->parent->left;
                    if (u->color == red) 
                    {
                        u->color = black;
                        k->parent->color = black;
                        k->parent->parent->color = red;
                        k = k->parent->parent;
                    } 
                    else 
                    {
                        if (k == k->parent->left) 
                        {
                            k = k->parent;
                            _rightRotate(k);
                        }
                        k->parent->color = black;
                        k->parent->parent->color = red;
                        _leftRotate(k->parent->parent);
                    }
                }
                else 
                {
                    u = k->parent->parent->right;
                    if (u->color == red) 
                    {
                        u->color = black;
                        k->parent->color = black;
                        k->parent->parent->color = red;
                        k = k->parent->parent;
                    } 
                    else 
                    {
                        if (k == k->parent->right) 
                        {
                            k = k->parent;
                            _leftRotate(k);
                        }
                        k->parent->color = black;
                        k->parent->parent->color = red;
                        _rightRotate(k->parent->parent);
                    }
                }
                if (k == _root)
                    break;
                }
                _root->color = black;
            }
            void _rightRotate(node_ptr x) 
            {
                node_ptr y = x->left;
                x->left = y->right;
                if (y->right != _emptyNode)
                    y->right->parent = x;
                y->parent = x->parent;
                if (x->parent == 0)
                    this->_root = y; 
                else if (x == x->parent->right)
                    x->parent->right = y;
                else 
                    x->parent->left = y;
                y->right = x;
                x->parent = y;
            }
            void _leftRotate(node_ptr x) 
            {
                node_ptr y = x->right;
                x->right = y->left;
                if (y->left != _emptyNode)
                    y->left->parent = x;
                y->parent = x->parent;
                if (x->parent == 0)
                    this->_root = y; 
                else if (x == x->parent->left) 
                    x->parent->left = y;
                else
                    x->parent->right = y;
                y->left = x;
                x->parent = y;
            }
            void _deallocateAndDestroyTree()
            {
                _deallocateAndDestroyValueNodes(_root);
                _deallocateAndDestroyNode(_emptyNode);
            }
            void _deallocateAndDestroyValueNodes(node_ptr root)
            {
                if (root == _emptyNode)
                    return;
                _deallocateAndDestroyValueNodes(root->left);
                _deallocateAndDestroyValueNodes(root->right);
                _deallocateAndDestroyNode(root);
            }
            void _deallocateAndDestroyNode(node_ptr n)
            {
                _node_alloc.destroy(n);
                _node_alloc.deallocate(n, 1);
            }
            size_type _deleteNode(node_ptr node, const key_type &key)
            {
                node_ptr z = _emptyNode;
                node_ptr x, y;
                while (node != _emptyNode) 
                {
                    if (node->value.first == key)
                        z = node;
                    if (node->value.first <= key)
                        node = node->right;
                    else
                        node = node->left;
                }
                if (z == _emptyNode)
                    return 0;
                y = z;
                NodeColor y_original_color = y->color;
                if (z->left == _emptyNode) 
                {
                    x = z->right;
                    _rbTransplant(z, z->right);
                } 
                else if (z->right == _emptyNode) 
                {
                    x = z->left;
                    _rbTransplant(z, z->left);
                } 
                else 
                {
                    y = _getMinNode(z->right);
                    y_original_color = y->color;
                    x = y->right;
                    if (y->parent == z)
                        x->parent = y;
                    else 
                    {
                        _rbTransplant(y, y->right);
                        y->right = z->right;
                        y->right->parent = y;
                    }
                    _rbTransplant(z, y);
                    y->left = z->left;
                    y->left->parent = y;
                    y->color = z->color;
                }
                _deallocateAndDestroyNode(z);
                if (y_original_color == black)
                    _deleteBalance(x);
                _size--;
                _updateMinMaxElementPassNode(_root, _emptyNode);
                return 1;
            }
        void _rbTransplant(node_ptr u, node_ptr v) 
        {
            if (u->parent == 0)
                _root = v;
            else if (u == u->parent->left)
                u->parent->left = v;
            else
                u->parent->right = v;
            v->parent = u->parent;
        }
        void _deleteBalance(node_ptr x) 
        {
            node_ptr s;
            while (x != _root && x->color == black) 
            {
                if (x == x->parent->left) 
                {
                    s = x->parent->right;
                    if (s->color == red) 
                    {
                        s->color = black;
                        x->parent->color = red;
                        _leftRotate(x->parent);
                        s = x->parent->right;
                    }
                    if (s->left->color == black && s->right->color == black) 
                    {
                        s->color = red;
                        x = x->parent;
                    } 
                    else 
                    {
                        if (s->right->color == black) 
                        {
                            s->left->color = black;
                            s->color = red;
                            _rightRotate(s);
                            s = x->parent->right;
                        }
                        s->color = x->parent->color;
                        x->parent->color = black;
                        s->right->color = black;
                        _leftRotate(x->parent);
                        x = _root;
                    }
                } 
                else 
                {
                    s = x->parent->left;
                    if (s->color == red) 
                    {
                        s->color = black;
                        x->parent->color = red;
                        _rightRotate(x->parent);
                        s = x->parent->left;
                    }

                    if (s->right->color == black && s->right->color == black) 
                    {
                        s->color = red;
                        x = x->parent;
                    } 
                    else 
                    {
                        if (s->left->color == black) 
                        {
                            s->right->color = black;
                            s->color = red;
                            _leftRotate(s);
                            s = x->parent->left;
                        }
                        s->color = x->parent->color;
                        x->parent->color = black;
                        s->left->color = black;
                        _rightRotate(x->parent);
                        x = _root;
                    }
                }
            }
            x->color = black;
        }

        node_ptr _getMinNode(node_ptr node) const
        {
            if (node == _emptyNode)
                return node;
            while (node->left != _emptyNode)
            {
                node = node->left;
            }
            return node;
        }
        node_ptr _getMaxNode(node_ptr node) 
        {
            if (node == _emptyNode)
                return node;
            while (node->right != _emptyNode) 
            {
                node = node->right;
            }
            return node;
        }
        void _updateMinMaxElementPassNode(node_ptr root, node_ptr minMaxElementPassNode)
        {
            minMaxElementPassNode->left = _getMaxNode(root);
            minMaxElementPassNode->right = _getMinNode(root);
        }
    };
}
#endif
