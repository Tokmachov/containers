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
    template <typename InputIterator>
    bool equal(InputIterator first1, InputIterator last1, InputIterator first2)
    {
        for (; first1 != last1; first1++, first2++)
        {
            if (*first1 != *first2)
                return false;
        }
        return true;
    }
    template <typename InputIterator>
    bool lexicographical_compare
    (
        InputIterator first1, 
        InputIterator last1, 
        InputIterator first2, 
        InputIterator last2
    )
    {
        for (; first1 != last1 && first2 != last2; first1++, first2++)
        {
            if (*first1 != *first2)
                return *first1 < *first2;
        }
        if ((*first1 == *last1) && (*first2 != *last2))
            return true;
        return false;
    }
    template <typename Node>
    std::string colorLetter(Node *n)
    {
        if (n->color == 0)
            return std::string("(R)");
        else if (n->color == 1)
            return std::string("(B)");
        else
            return std::string("X");
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
                std::cout << root->right->value.first << colorLetter(root->right) << std::endl;
                printSubtree(root->right, tnull, newPrefix);
        }

        if (hasLeft)
        {
                std::cout << (hasRight ? prefix : "") << "└── " << root->left->value.first << colorLetter(root->left) << std::endl;
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
        std::cout << root->value.first << colorLetter(root) << std::endl;
        printSubtree(root, tnull, "");
        std::cout << std::endl;
    }
    template <typename Iterator, typename Value = typename Iterator::value_type>
    class ReverseIterator
    {
        public:
            typedef typename std::iterator_traits<Iterator>::iterator_category iterator_category;
            typedef Value value_type;
            typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
            typedef value_type *pointer;
            typedef value_type &reference;
            typedef Iterator base_iter_type;
        
        ReverseIterator(const base_iter_type & iter)
            : _base(iter) {}
        operator ReverseIterator<Iterator, const value_type>()
        {
            return ReverseIterator<Iterator, const value_type>(_base);
        }
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
    template <typename InputIterator>
    void printContainer(InputIterator first, InputIterator last)
    {
        std::cout << "---Container_print_start---\n";
        for (;first != last; first++) 
        {
            std::cout << " |" << *first << "|";
        }
        std::cout << std::endl;
        std::cout << "---Container_print_end---\n";
    }
}

#endif