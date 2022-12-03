#include "dynamic_array.h"

int main(){
    Array<float> A = {1,2,3,4,5};

    std::cout << A.capacity();
    A.append(6);

    std::cout << A.capacity();
    return 0;
}