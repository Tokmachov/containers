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
    static void printSubtree(Node* root, const std::string& prefix)
    {
        if (root == NULL)
        {
                return;
        }

        bool hasLeft = (root->left != NULL);
        bool hasRight = (root->right != NULL);

        if (!hasLeft && !hasRight)
        {
                return;
        }

        std::cout << prefix;
        std::cout << ((hasLeft  && hasRight) ? "├── " : "");
        std::cout << ((!hasLeft && hasRight) ? "└── " : "");

        if (hasRight)
        {
                bool printStrand = (hasLeft && hasRight && (root->right->right != NULL || root->right->left != NULL));
                std::string newPrefix = prefix + (printStrand ? "│   " : "    ");
                std::cout << root->right->value.first << std::endl;
                printSubtree(root->right, newPrefix);
        }

        if (hasLeft)
        {
                std::cout << (hasRight ? prefix : "") << "└── " << root->left->value.first << std::endl;
                printSubtree(root->left, prefix + "    ");
        }
    }
    template <typename Node>
    void printTree(Node *_root)
    {
        if (_root == NULL)
        {
                return;
        }
        std::cout << _root->value.first << std::endl;
        printSubtree(_root, "");
        std::cout << std::endl;
    }
}

#endif