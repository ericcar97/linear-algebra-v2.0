#include "static_array.h"
#include "dynamic_array.h"
#include "matrix.h"
#include "print.h"

int main(){
    Matrix<float,unknown,unknown>
    A = {{1,2,3},
         {4,5,3},
         {2,3,4},
         {2,1,2}};

    print("Matrix:",'\n',A);
    return 0;
}