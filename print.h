#ifndef PRINT_H
#define PRINT_H

#include<iostream>


template<typename Type, size_type Size>
std::ostream& operator<<(std::ostream& stream, const Array<Type,Size>& array){
    stream << '[';
    for(const auto & element : array){
        stream << element << ',';
    }
    return stream << '\b' << ']' << std::endl;
 }


template<typename Type, size_type Size>
std::ostream& operator<<(std::ostream& stream, const Vector<Type,Size>& vector){
    for(const auto & element : vector){
        stream << '[' << element << ']' << std::endl;
    }
    return stream;
 }

template<typename Type, size_type Rows, size_type Columns>
std::ostream& operator<<(std::ostream& stream, const Matrix<Type,Rows,Columns>& matrix){
    for(const auto & row : matrix){
        stream << row;
    }
    return stream;
 }


template<typename ...Args>
void print(Args&&... args){
    (std::cout << ... << args);
}

template<>
void print(){
    std::cout << std::endl;
}

#endif