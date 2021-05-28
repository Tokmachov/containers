#ifndef NODE_HPP
#define NODE_HPP
template <typename Data>
struct Node
{
    Node<Data>(const Data &d)
        : data(d), next(0), prev(0) {};
    Data data;
    Node<Data> *next;
    Node<Data> *prev;
};
#endif