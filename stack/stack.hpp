#ifndef STACK_HPP
# define STACK_HPP

# include "../list/list.hpp"

namespace ft
{
    template <class T, class Container = ft::list<T> >
    class stack
    {
        //Member types
        public:
            typedef T value_type;
            typedef Container container_type;
            typedef size_t size_type;
        //Member functions:
        explicit stack (const container_type& ctnr = container_type())
            : _container(ctnr) {}
        bool empty() const
        {
            return _container.empty();
        }
        size_type size() const
        {
            return _container.size();
        }
        value_type& top()
        {
            return _container.back();
        }
        const value_type& top() const
        {
            return _container.back();
        }
        void push (const value_type& val)
        {
            _container.push_back(val);
        }
        void pop()
        {
            _container.pop_back();
        }
        //Global ops overloads
        friend bool operator== (const stack& lhs, const stack& rhs)
        {
            return lhs._container == rhs._container;
        }
        friend bool operator!= (const stack& lhs, const stack& rhs)
        {
            return lhs._container != rhs._container;
        }
        friend bool operator< (const stack& lhs, const stack& rhs)
        {
            return lhs._container < rhs._container;
        }
        friend bool operator<= (const stack& lhs, const stack& rhs)
        {
            return lhs._container <= rhs._container;
        }
        friend bool operator> (const stack& lhs, const stack& rhs)
        {
            return lhs._container > rhs._container;
        }
        friend bool operator>= (const stack& lhs, const stack& rhs)
        {
            return lhs._container >= rhs._container;
        }
        private:
            container_type _container;
    };
}

#endif