#ifndef MAP_HPP
# define MAP_HPP

# include "RedBlackTreeIterator.hpp"

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
            typedef Node<value_type> tree_node;
            typedef typename Alloc:: template rebind< tree_node >::other node_allocator;
            typedef typename node_allocator::pointer node_ptr;
            typedef typename node_allocator::pointer const_node_ptr;
            typedef RedBlackTreeIterator<tree_node, value_type> iterator;
            typedef RedBlackTreeIterator<tree_node, const value_type> const_iterator;
            typedef typename std::iterator_traits<iterator>::difference_type size_type;
            
            //constructors
            explicit map
            (
                const key_compare& compLessKey = key_compare(), 
                const allocator_type& alloc = allocator_type()
            ) 
                : _node_alloc(node_allocator()), _compLessPair(compLessKey), _size(0)
            { 
                _tnull = _node_alloc.allocate(1);
                _tnull->color = black;
                _tnull->left = 0;
                _tnull->right = 0;
                _root = _tnull;
            }
            template <class InputIterator>
            map
            (
                InputIterator first, 
                InputIterator last,
                const key_compare& compLessKey = key_compare(),
                const allocator_type& alloc = allocator_type()
            )
                : _node_alloc(node_allocator()), _compLessPair(compLessKey), _size(0)
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
                _compLessPair(x._compLessPair)
            {
                _tnull = _node_alloc.allocate(1);
                _node_alloc.construct(_tnull, *(x._tnull));
                _root = _tnull;
                for (const_iterator it = x.begin();it != x.end(); ++it)
                    insert(*it);
            }
            ~map() { _deallocateAndDestroyTree(); };
            //Assigment operator
            map& operator= (const map& x) 
            { 
                _deallocateAndDestroyTree();
                _tnull = _node_alloc.allocate(1);
                _node_alloc.construct(_tnull, *(x._tnull));
                _root = _tnull;
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
            //Modifiers
            std::pair<iterator, bool> insert(value_type value)
            {
                node_ptr node = _node_alloc.allocate(1);
                tree_node n(value, 0, _tnull, _tnull, red);
                _node_alloc.construct(node, n);
                node_ptr y = 0;
                node_ptr x = this->_root;

                while (x != _tnull) {
                y = x;
                if (node->value < x->value) {
                    x = x->left;
                } 
                else if (x->value < node->value) 
                {
                    x = x->right;
                }
                else
                {
                    _node_alloc.destroy(node);
                    _node_alloc.deallocate(node, 1);
                    return std::pair<iterator, bool>(iterator(x, _tnull), false);
                }
                }
                node->parent = y;
                if (y == 0) {
                _root = node;
                } else if (node->value < y->value) {
                    y->left = node;
                } else {
                    y->right = node;
                }
                _size++;
                if (node->parent == 0) {
                    node->color = black;
                    return std::pair<iterator, bool>(iterator(node, _tnull), true);
                }

                if (node->parent->parent == 0) {
                    return std::pair<iterator, bool>(iterator(node, _tnull), true);
                }
                insertFix(node);
                return std::pair<iterator, bool>(iterator(node, _tnull), true);
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
            size_type size() const
            {
                return _size;
            }
            const_node_ptr getRoot() const
            {
                return _root;
            }
        private:
            node_allocator _node_alloc;
            node_ptr _root;
            node_ptr _tnull;
            value_compare _compLessPair;
            size_type _size;
            
            node_ptr _searchTreeHelper(node_ptr node, value_type value)
            {
                if (node == _tnull || _areEqual(node->value, value))
                {
                    return node;
                }
                if (_compLessPair(value, node->value))
                {
                    return searchTreeHelper(node->left, value);
                }
                return searchTreeHelper(node->right, value);
            }
            
            bool _areEqual(value_type v1, value_type v2)
            {
                return (!_compLessPair(v1, v2) && !compLess(v2, v1));
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
    };
}
#endif
