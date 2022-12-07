#ifndef MATRIX_H
#define MATRIX_H

#include "static_array.h"
#include "dynamic_array.h"

template<typename Type, size_type Rows, size_type Columns>
class Matrix{
    public:
        using value_type = Type;
        using reference = value_type&;
        using const_reference = value_type const &;
        using pointer = value_type*;
        using nested_initializer = std::initializer_list<std::initializer_list<value_type>>;

        Matrix(nested_initializer list)
            : rows_(0)
            , columns_(list.begin()->size()){
            for(auto line : list){
                _data[rows_++] = line;
            }
        }

        auto begin(){return &_data[0];}
        auto end(){return &_data[0] + rows_;}

        const auto begin() const {return &_data[0];}
        const auto end() const {return &_data[0] + rows_;}

        size_type rows(){return _data.size();}
        size_type columns(){return _data[0].size();}

        Array<Type,Columns>& operator [](index i){return _data[i];}
        const Array<Type,Columns>& operator[](index i) const {return _data[i];}

    private:
        Array<Array<Type,Columns>,Rows> _data;
        size_type rows_;
        size_type columns_;
};





#endif