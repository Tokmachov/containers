#ifndef UTILS_HPP
# define UTILS_HPP
namespace ft
{
    template <bool Cond, typename T = void>
    struct enable_if {};

    template<typename T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template <typename Iterator, typename Category = typename std::iterator_traits<Iterator>::iterator_category >
    struct is_suitable_as_input_iterator
    {
        static const bool value = false;
    };

    template <typename Iterator>
    struct is_suitable_as_input_iterator<Iterator, std::forward_iterator_tag>
    {
        static const bool value = true;
    };

    template <typename Iterator>
    struct is_suitable_as_input_iterator<Iterator, std::bidirectional_iterator_tag>
    {
        static const bool value = true;
    };

    template <typename Iterator>
    struct is_suitable_as_input_iterator<Iterator, std::random_access_iterator_tag>
    {
        static const bool value = true;
    };
    template <typename InputIterator>
    size_t distance(InputIterator first, const InputIterator &last)
    {
        size_t dist = 0;
        for (;first != last; first++)
            dist++;
        return dist;
    }
    template <typename Node>
    static void printSubtree(Node* root, Node *tnull, const std::string& prefix)
    {
        if (root == tnull)
        {
                return;
        }

        bool hasLeft = (root->left != tnull);
        bool hasRight = (root->right != tnull);

        if (!hasLeft && !hasRight)
        {
                return;
        }

        std::cout << prefix;
        std::cout << ((hasLeft  && hasRight) ? "├── " : "");
        std::cout << ((!hasLeft && hasRight) ? "└── " : "");

        if (hasRight)
        {
                bool printStrand = (hasLeft && hasRight && (root->right->right != tnull || root->right->left != NULL));
                std::string newPrefix = prefix + (printStrand ? "│   " : "    ");
                std::cout << root->right->value.first << std::endl;
                printSubtree(root->right, tnull, newPrefix);
        }

        if (hasLeft)
        {
                std::cout << (hasRight ? prefix : "") << "└── " << root->left->value.first << std::endl;
                printSubtree(root->left, tnull, prefix + "    ");
        }
    }
    template <typename Node>
    void printTree(Node *root, Node *tnull)
    {
        if (root == tnull)
        {
                return;
        }
        std::cout << root->value.first << std::endl;
        printSubtree(root, tnull, "");
        std::cout << std::endl;
    }
    template <typename Iterator>
    class ReverseIterator
    {
        public:
            typedef typename std::iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename std::iterator_traits<Iterator>::value_type value_type;
            typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
            typedef typename std::iterator_traits<Iterator>::pointer pointer;
            typedef typename std::iterator_traits<Iterator>::reference reference;
            typedef Iterator base_iter_type;
        
        ReverseIterator(const base_iter_type & iter)
            : _base(iter) {}
        //X a;
        ReverseIterator() : _base() {}
        //X b(a);
        ReverseIterator(const ReverseIterator &src) : _base(src._base) {}
        //b = a;
        reference operator=(const ReverseIterator &rhs)
        {
            _base = rhs._base;
            return *this;
        }
        //a == b
        bool operator==(const ReverseIterator &rhs) { return (_base == rhs._base); }
        //a != b
        bool operator!=(const ReverseIterator &rhs) { return _base == rhs._base; }
        //*a
        reference operator*() const {Iterator tmp = _base; return *--tmp;}
        //a->m
        pointer  operator->() const { return &(operator*()); }
        //++a
        ReverseIterator& operator++() { --_base; return *this; }
        //a++
        ReverseIterator  operator++(int) { ReverseIterator tmp(*this); --_base; return tmp; }
        //--a
        ReverseIterator& operator--() { ++_base; return *this; }
        //a--
        ReverseIterator operator--(int) { ReverseIterator tmp(*this); ++_base; return tmp; }
        //iterator + n
        ReverseIterator  operator+(difference_type n) const { return ReverseIterator(_base - n); }
        //iterator += n
        ReverseIterator& operator+=(difference_type n) { _base -= n; return *this; }
        //iterator - n
        ReverseIterator  operator-(difference_type n) const { return ReverseIterator(_base + n); }
        //iterator -= n
        ReverseIterator& operator-=(difference_type n) { _base += n; return *this; }
        // []
        reference operator[](difference_type n) const { return *(*this + n); }
        ReverseIterator base()
        {
            return _base;
        }
        private:
            base_iter_type _base;    
    };
    template <class Iter1, class Iter2>
    bool operator==(const ReverseIterator<Iter1>& x, const ReverseIterator<Iter2>& y)
    {
        return x._base() == y._base();
    }

    template <class Iter1, class Iter2>
    bool operator<(const ReverseIterator<Iter1>& x, const ReverseIterator<Iter2>& y)
    {
        return x.base() > y.base();
    }

    template <class Iter1, class Iter2>
    bool operator!=(const ReverseIterator<Iter1>& x, const ReverseIterator<Iter2>& y)
    {
        return x.base() != y.base();
    }

    template <class Iter1, class Iter2>
    bool operator>(const ReverseIterator<Iter1>& x, const ReverseIterator<Iter2>& y)
    {
        return x.base() < y.base();
    }

    template <class Iter1, class Iter2>
    bool operator>=(const ReverseIterator<Iter1>& x, const ReverseIterator<Iter2>& y)
    {
        return x.base() <= y.base();
    }

    template <class Iter1, class Iter2>
    bool operator<=(const ReverseIterator<Iter1>& x, const ReverseIterator<Iter2>& y)
    {
        return x.base() >= y.base();
    }

    template <class Iter1, class Iter2> 
    typename ReverseIterator<Iter1>::difference_type 
    operator-(const ReverseIterator<Iter1>& x, const ReverseIterator<Iter2>& y)
    {
        return y.base() - x.base();
    }
    template <class Iter>
    ReverseIterator<Iter>
    operator+(typename ReverseIterator<Iter>::difference_type n, const ReverseIterator<Iter>& x)
    {
        return ReverseIterator<Iter>(x.base() - n);
    }
}

#endif