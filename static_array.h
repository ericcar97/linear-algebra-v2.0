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
        using self = Array<Type,Size>;
        using value_type = Type;
        using array_type = value_type[Size];
        using reference = value_type&;
        using const_reference = value_type const &;
        using initializer = std::initializer_list<value_type>;
        using iterator = Iterator<self>;
        using const_iterator = ConstIterator<self>;


        iterator begin(){return data_;}
        iterator end(){return data_ + size_;}

        const_iterator begin() const {return data_;}
        const_iterator end() const {return data_ + size_;}

        size_type size() const {return size_;}

        Array() : data_{} {}
        Array(initializer list){std::copy(list.begin(), list.end(), data_);}

        reference operator[](index i){return data_[i];}
        const_reference operator[](index i) const {return data_[i];}
    private:
        array_type data_;
        size_type size_ = Size;
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