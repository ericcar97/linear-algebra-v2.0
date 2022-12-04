#ifndef STATIC_ARRAY
#define STATIC_ARRAY

#include <iostream>
#include "iterator.h"

using size_type = std::size_t;
using index = std::size_t;

template<typename Type, size_type ... Sizes> class Array;

template<typename Type, size_type Size>
class Array<Type,Size>{
    public:
        using value_type = Type;
        using array_type = value_type[Size];
        using reference = value_type&;
        using const_reference = value_type const &;
        using iterator = Iterator<Array<Type,Size>>;
        using initializer = std::initializer_list<value_type>;

        iterator begin(){return data_;}
        iterator end(){return data_ + Size;}

        size_type size(){return Size;}

        Array() : data_{} {}
        Array(initializer list){std::copy(list.begin(), list.end(), data_);}

        reference operator[](index i){return data_[i];}
        const_reference operator[](index i) const {return data_[i];}
    private:
        array_type data_;
};

template<typename Type, size_type Size, size_type ... Sizes>
class Array<Type,Size,Sizes...>{
    public:
        using value_type = Type;
        using squeezed_array = typename Array<Type,Sizes...>::array_type;
        using array_type = squeezed_array[Size];
        using reference = squeezed_array&;
        using const_reference = squeezed_array const &;

        Array() : data_{} {}

        reference operator[](index i){return data_[i];}
        const_reference operator[](index i) const {return data_[i];}

    private:
        array_type data_;
};

#endif