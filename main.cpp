#include "static_array.h"
#include "dynamic_array.h"
#include "print.h"


int main(){
    Array<float> A = {1,2,3,4,5};

    print("something");

    for(auto element : A){
        print(element);
    }

    return 0;
}