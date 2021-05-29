template <typename Value>
class VectorIterator
{
    public:
        typedef Value value_type;
        typedef ptrdiff_t difference_type;
        typedef Value* pointer;
        typedef Value& reference;
        typedef std::random_access_iterator_tag iterator_category;

        VectorIterator<Value>() {}
    private:
        //pointer value_addr;

};