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
}

#endif