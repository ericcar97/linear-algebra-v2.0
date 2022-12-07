#ifndef VECTOR_H
#define VECTOR_H

#include "dynamic_array.h"
#include "static_array.h"

template<typename Type, size_type Size>
class Vector{
    public:
        using value_type = Type;
        using reference = value_type&;
        using const_reference = value_type const &;
        using pointer = value_type*;
        using initializer = std::initializer_list<Type>;

        size_type size() const {return size_;}

        auto begin(){return _data.begin();}
        auto end(){return _data.end();}

        const auto begin() const {return _data.begin();}
        const auto end() const {return _data.end();}

        Vector(initializer list)
            : size_(list.size())
            , _data(list) {}

        reference operator[](index i){
            return _data[i];
        }

        const_reference operator[](index i) const {
            return _data[i];
        }

    private:
        Array<Type,Size> _data;
        size_type size_;
};

#endif