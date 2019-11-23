#include "lab.h"
 

int main()
{
    elem_type h;
    elem_type* arr;
    long num = 0;

    read_and_create(&h, &arr, &num);
    
    run(num, h, arr);

    return 0;
}