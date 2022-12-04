#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include<iostream>
#include "iterator.h"

using size_type = std::size_t;

template<typename Type, size_type ... Sizes> class Array;

template<typename Type>
class Array<Type>{
    public:
        using value_type = Type;
        using reference = value_type&;
        using const_reference = value_type const &;
        using pointer = value_type*;
        using initializer = std::initializer_list<value_type>;
        using self = Array<Type>;
        using index = std::size_t;
        using iterator = Iterator<Array<Type>>;

        size_type size() const {return size_;}
        size_type capacity() const {return capacity_;}

        Array()
            : size_(0)
            , capacity_(3)
            , data_(new value_type[capacity_]){}

        Array(size_type size)
            : size_(size)
            , capacity_(size)
            , data_(new value_type[capacity_]){}

        Array(initializer list)
            : Array(list.size()){
                std::copy(list.begin(), list.end(), data_);
        }

        Array(const self& other)
            : size_(other.size_)
            , capacity_(other.capacity_)
            , data_(new value_type[capacity_]){
                std::copy(other.data_, other.data_ + size_, this->data_);
                //std::cout << "copy constructor" << std::endl;
        }

        Array(self && other)
            : Array(0){
                swap(*this, other);
                //std::cout << "move constructor" << std::endl;
        }

        ~Array(){
            delete[] data_;
            //std::cout << "destructor" << std::endl;
        }

        iterator begin(){return data_;}
        iterator end(){return data_ + size_;}

        self& operator = (self other){
            swap(*this,other);
            //std::cout << "copy operator" << std::endl;
            return *this;
        }

        reference operator[](index i){
            return data_[i];
            //return *(data_ + i);
        }

        const_reference operator[](index i) const{
            return data_[i];
            //return *(data_ + i);
        }

        void append(const_reference value){
            if(size_ == capacity_){
                reallocate(size_ + size_/2);
            }
            data_[size_++] = value;
        }

    private:
        size_type size_;
        size_type capacity_;
        pointer data_;

        void reallocate(size_type capacity){
            size_type size = size_;
            if(capacity < size){
                size = capacity;
            }
            
            value_type data = new value_type[capacity];

            for(index i = 0; i < size; i++){
                data[i] = data_[i];
            }
            size_ = size;
            capacity_ = capacity;
            data_ = data;
            delete[] data;
        };

        friend void swap(self& first, self& other){
            std::swap(first.size_,other.size_);
            std::swap(first.capacity_, other.capacity_);
            std::swap(first.data_, other.data_);
        }
};

#endif