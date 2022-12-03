#ifndef STATIC_ARRAY
#define STATIC_ARRAY

#include<iostream>
using size_type = std::size_t;

template<typename Type, size_type ... Sizes> class Array;

template<typename Type, size_type Size>
class Array<Type,Size>{
    public:
        using value_type = Type;
        using reference = value_type&;
        using const_reference = value_type const &;
        using pointer = value_type*;
        using initializer = std::initializer_list<value_type>;
        using self = Array<value_type>;
};

#endif