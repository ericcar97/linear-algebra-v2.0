#include "static_array.h"
#include "dynamic_array.h"
#include "matrix.h"
#include "vector.h"
#include "print.h"

int main(){
    Vector<float,5> v = {1,2,3,4,5};
    print(v);
    return 0;
}