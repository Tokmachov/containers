#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "../list/list.hpp"

namespace ft
{
    template <class T, class Container = ft::list<T> > 
    class queue
    {
        public:
            //Member types
            typedef T value_type;
            typedef Container container_type;
            typedef typename Container::size_type size_type;
            explicit queue (const container_type& ctnr = container_type())
                : _container(ctnr) {}
            //Member functions
            bool empty() const
            {
                return _container.empty();
            }
            size_type size() const
            {
                return _container.size();
            }
            value_type& front()
            {
                return _container.front();
            }
            const value_type& front() const
            {
                return _container.front();
            }
            value_type& back()
            {
                return _container.back();
            }
            const value_type& back() const
            {
                _container.back();
            }
            void push (const value_type& val)
            {
                _container.push_back(val);
            }
            void pop()
            {
                _container.pop_front();
            }
            friend bool operator== (const queue& lhs, const queue& rhs)
            {
                return lhs._container == rhs._container;
            }
            friend bool operator!= (const queue& lhs, const queue& rhs)
            {
                return lhs._container != rhs._container;
            }
            friend bool operator<  (const queue& lhs, const queue& rhs)
            {
                return lhs._container < rhs._container;
            }
            friend bool operator<= (const queue& lhs, const queue& rhs)
            {
                return lhs._container <= rhs._container;
            }
            friend bool operator>  (const queue<T,Container>& lhs, const queue<T,Container>& rhs)
            {
                return lhs._container > rhs._container;
            }
            friend bool operator>= (const queue& lhs, const queue& rhs)
            {
                return lhs._container >= rhs._container;
            }
        private:
            container_type _container;
    };
}

#endif