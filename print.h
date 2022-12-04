#ifndef PRINT_H
#define PRINT_H

#include<iostream>

template<typename ...Args>
void print(Args&&... args){
    (std::cout << ... << args);
}

#endif