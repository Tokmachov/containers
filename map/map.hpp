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
                friend class map;
                protected:
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
            typedef ReverseIterator<iterator> const_reverse_iterator;
            typedef typename std::iterator_traits<iterator>::difference_type size_type;
            
            //constructors
            explicit map
            (
                const key_compare& compLessKey = key_compare(), 
                const allocator_type& alloc = allocator_type()
            ) 
                : _node_alloc(node_allocator()), 
                _compLessPair(compLessKey), 
                _compLessKey(compLessKey),
                _size(0)
            { 
                _tnull = _node_alloc.allocate(1);
                _tnull->color = black;
                _tnull->left = 0;
                _tnull->right = 0;
                _root = _tnull;
                _updateMinMaxElementPassNode(_root, _tnull);
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
                _compLessPair(compLessKey),
                _compLessKey(compLessKey),
                _size(0)
            {
                _tnull = _node_alloc.allocate(1);
                _tnull->color = black;
                _tnull->left = 0;
                _tnull->right = 0;
                _root = _tnull;
                for (;first != last; first++)
                    insert(*first);
            }
            map (const map& x)
                : _node_alloc(x._node_alloc), 
                _compLessPair(x._compLessPair),
                _compLessKey(x._compLessKey)
            {
                _tnull = _node_alloc.allocate(1);
                _tnull->color = black;
                _tnull->left = 0;
                _tnull->right = 0;
                _root = _tnull;
                for (const_iterator it = x.begin();it != x.end(); ++it)
                    insert(*it);
            }
            ~map() { _deallocateAndDestroyTree(); };
            map& operator= (const map& x) 
            { 
                _deallocateAndDestroyTree();
                _tnull = _node_alloc.allocate(1);
                _tnull->color = black;
                _tnull->left = 0;
                _tnull->right = 0;
                _root = _tnull;
                _compLessPair = x._compLessPair;
                _compLessKey = x._compLessKey;
                for (const_iterator it = x.begin();it != x.end(); ++it)
                    insert(*it);
                return *this;
            }
            //Iterators
            iterator begin()
            {
                return iterator(_getMinNode(), _tnull);
            }
            const_iterator begin() const
            {
                return const_iterator(_getMinNode(), _tnull);
            }
            iterator end()
            {
                return iterator(_tnull, _tnull);
            }
            const_iterator end() const
            {
                return const_iterator(_tnull, _tnull);
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
                node_ptr nodeToInsert = _node_alloc.allocate(1);
                _node_alloc.construct(nodeToInsert, node(value, 0, _tnull, _tnull, red));
                node_ptr y = 0;
                node_ptr x = this->_root;

                while (x != _tnull) {
                y = x;
                if (_compLessPair(nodeToInsert->value, x->value)) {
                    x = x->left;
                } 
                else if (_compLessPair(x->value, nodeToInsert->value))
                {
                    x = x->right;
                }
                else
                {
                    _node_alloc.destroy(nodeToInsert);
                    _node_alloc.deallocate(nodeToInsert, 1);
                    return std::pair<iterator, bool>(iterator(x, _tnull), false);
                }
                }
                nodeToInsert->parent = y;
                if (y == 0) {
                _root = nodeToInsert;
                } else if (nodeToInsert->value < y->value) {
                    y->left = nodeToInsert;
                } else {
                    y->right = nodeToInsert;
                }
                _size++;
                _updateMinMaxElementPassNode(_root, _tnull);
                if (nodeToInsert->parent == 0) {
                    nodeToInsert->color = black;
                    return std::pair<iterator, bool>(iterator(nodeToInsert, _tnull), true);
                }

                if (nodeToInsert->parent->parent == 0) {
                    return std::pair<iterator, bool>(iterator(nodeToInsert, _tnull), true);
                }
                insertFix(nodeToInsert);
                return std::pair<iterator, bool>(iterator(nodeToInsert, _tnull), true);
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
                _deleteNode(position->first);
            }
            size_type erase (const key_type& k)
            {
                return _deleteNode(k);
            }
            void erase (iterator first, iterator last)
            {
                for (;first != last; first++)
                {
                    erase(first);
                }
            }
            void swap (map& x)
            {
                std::swap(_node_alloc, x._node_alloc);
                std::swap(_root, x._root);
                std::swap(_tnull, x._tnull);
                std::swap(_compLessPair, x._compLessPair);
                std::swap(_size, x._size);
            }
            void clear()
            {
                _deallocateAndDestroyValueNodes(_root);
                _root = _tnull;
                _tnull->left = 0;
                _tnull->right = 0;
                _updateMinMaxElementPassNode(_root, _tnull);
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
                node_ptr nPtr = _searchTree(k);
                return iterator(nPtr, _tnull);
            }
            const_iterator find (const key_type& k) const
            {
                node_ptr nPtr = _searchTree(k);
                return const_iterator(nPtr, _tnull);
            }
            size_type count (const key_type& k) const
            {
                if (_searchTree(k) != _tnull)
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
                const_iterator it = begin();
                for (; it != end(); it++)
                {
                    if (_compLessKey(it->first, k) == false)
                        return it;
                }
                return it;
            }
            const_node_ptr getRoot() const
            {
                return _root;
            }
            const_node_ptr getTNull() const
            {
                return _tnull;
            }
        private:
            node_allocator _node_alloc;
            node_ptr _root;
            node_ptr _tnull;
            value_compare _compLessPair;
            key_compare _compLessKey;
            size_type _size;
            
            node_ptr _searchTree(const key_type &k) const
            {
                return _searchTreeHelper(_root, k);
            }
            node_ptr _searchTreeHelper(node_ptr node, const key_type &k) const
            {
                if (node == _tnull || _areEqual(node->value.first, k))
                {
                    return node;
                }
                if (_compLessKey(k, node->value.first))
                {
                    return _searchTreeHelper(node->left, k);
                }
                return _searchTreeHelper(node->right, k);
            }
            
            bool _areEqual(const key_type &k1, const key_type &k2) const
            {
                return (!_compLessKey(k1, k2) && !_compLessKey(k2, k1));
            }
            void insertFix(node_ptr k)
            {
                node_ptr u;
                while (k->parent->color == red) {
                if (k->parent == k->parent->parent->right) {
                    u = k->parent->parent->left;
                    if (u->color == red) {
                    u->color = black;
                    k->parent->color = black;
                    k->parent->parent->color = red;
                    k = k->parent->parent;
                    } else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = black;
                    k->parent->parent->color = red;
                    leftRotate(k->parent->parent);
                    }
                } else {
                    u = k->parent->parent->right;

                    if (u->color == red) {
                    u->color = black;
                    k->parent->color = black;
                    k->parent->parent->color = red;
                    k = k->parent->parent;
                    } else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = black;
                    k->parent->parent->color = red;
                    rightRotate(k->parent->parent);
                    }
                }
                if (k == _root) {
                    break;
                }
                }
                _root->color = black;
            }
            void rightRotate(node_ptr x) 
            {
                node_ptr y = x->left;
                x->left = y->right;
                if (y->right != _tnull) {
                y->right->parent = x;
                }
                y->parent = x->parent;
                if (x->parent == 0) {
                this->_root = y;
                } else if (x == x->parent->right) {
                x->parent->right = y;
                } else {
                x->parent->left = y;
                }
                y->right = x;
                x->parent = y;
            }
            void leftRotate(node_ptr x) 
            {
                node_ptr y = x->right;
                x->right = y->left;
                if (y->left != _tnull) {
                y->left->parent = x;
                }
                y->parent = x->parent;
                if (x->parent == 0) {
                this->_root = y;
                } else if (x == x->parent->left) {
                x->parent->left = y;
                } else {
                x->parent->right = y;
                }
                y->left = x;
                x->parent = y;
            }
            node_ptr _getMinNode()
            {
                if (!_root)
                    return 0;
                node_ptr current = _root;
                while (current->left != _tnull)
                {
                    current = current->left;
                }
                return current;
            }
            const_node_ptr _getMinNode() const
            {
                if (!_root)
                    return 0;
                node_ptr current = _root;
                while (current->left != _tnull)
                {
                    current = current->left;
                }
                return current;
            }
            void _deallocateAndDestroyTree()
            {
                 _deallocateAndDestroyValueNodes(_root);
                _node_alloc.destroy(_tnull);
                _node_alloc.deallocate(_tnull, 1);
            }
            void _deallocateAndDestroyValueNodes(node_ptr root)
            {
                if (root == _tnull)
                    return;
                _deallocateAndDestroyValueNodes(root->left);
                _deallocateAndDestroyValueNodes(root->right);
                _node_alloc.destroy(root);
                _node_alloc.deallocate(root, 1);
            }
            size_type _deleteNode(const key_type &key) 
            {
                size_type result = _deleteNodeHelper(_root, key);
                _updateMinMaxElementPassNode(_root, _tnull);
                return result;
            }
            size_type _deleteNodeHelper(node_ptr node, const key_type &key)
            {
                node_ptr z = _tnull;
                node_ptr x, y;
                while (node != _tnull) {
                    if (node->value.first == key) {
                    z = node;
                    }

                    if (node->value.first <= key) {
                    node = node->right;
                    } else {
                    node = node->left;
                    }
                }

                if (z == _tnull) {
                    return 0;
                }

                y = z;
                NodeColor y_original_color = y->color;
                if (z->left == _tnull) {
                    x = z->right;
                    rbTransplant(z, z->right);
                } else if (z->right == _tnull) {
                    x = z->left;
                    rbTransplant(z, z->left);
                } else {
                    y = minimum(z->right);
                    y_original_color = y->color;
                    x = y->right;
                    if (y->parent == z) {
                    x->parent = y;
                    } else {
                    rbTransplant(y, y->right);
                    y->right = z->right;
                    y->right->parent = y;
                    }

                rbTransplant(z, y);
                y->left = z->left;
                y->left->parent = y;
                y->color = z->color;
                }
                delete z;
                if (y_original_color == black) {
                deleteFix(x);
                }
                _size--;
                return 1;
            }
        void rbTransplant(node_ptr u, node_ptr v) 
        {
            if (u->parent == 0) {
                _root = v;
            } else if (u == u->parent->left) {
                u->parent->left = v;
            } else {
                u->parent->right = v;
            }
            v->parent = u->parent;
        }
        void deleteFix(node_ptr x) 
        {
        node_ptr s;
        while (x != _root && x->color == black) {
            if (x == x->parent->left) {
            s = x->parent->right;
            if (s->color == red) {
                s->color = black;
                x->parent->color = red;
                leftRotate(x->parent);
                s = x->parent->right;
            }

            if (s->left->color == black && s->right->color == black) {
                s->color = red;
                x = x->parent;
            } else {
                if (s->right->color == black) {
                s->left->color = black;
                s->color = red;
                rightRotate(s);
                s = x->parent->right;
                }

                s->color = x->parent->color;
                x->parent->color = black;
                s->right->color = black;
                leftRotate(x->parent);
                x = _root;
            }
            } else {
            s = x->parent->left;
            if (s->color == red) {
                s->color = black;
                x->parent->color = red;
                rightRotate(x->parent);
                s = x->parent->left;
            }

            if (s->right->color == black && s->right->color == black) {
                s->color = red;
                x = x->parent;
            } else {
                if (s->left->color == black) {
                s->right->color = black;
                s->color = red;
                leftRotate(s);
                s = x->parent->left;
                }

                s->color = x->parent->color;
                x->parent->color = black;
                s->left->color = black;
                rightRotate(x->parent);
                x = _root;
            }
            }
        }
        x->color = black;
        }
        
        node_ptr minimum(node_ptr node) {
            if (node == _tnull)
                return node;
            while (node->left != _tnull)
            {
                node = node->left;
            }
            return node;
        }
        node_ptr maximum(node_ptr node) {
            if (node == _tnull)
                return node;
            while (node->right != _tnull) 
            {
                node = node->right;
            }
            return node;
        }
        void _updateMinMaxElementPassNode(node_ptr root, node_ptr minMaxElementPassNode)
        {
            minMaxElementPassNode->left = maximum(root);
            minMaxElementPassNode->right = minimum(root);
        }
    };
}
#endif
