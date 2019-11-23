#include "lab.h"

const elem_type A = -20;
const elem_type B = 20;

int read_and_create(elem_type* h, elem_type** arr, long int* n)
{
    printf("\nPlease, write step:\nh = ");
    scanf("%f", h);

    *n = calc_arr_num(*h);
    *arr = (elem_type*)calloc(*n, sizeof(elem_type));
    if (*arr == NULL)
    {
        printf("\nError\n");
        exit(EXIT_FAILURE);
    }

    **arr = A;
    for(int i = 1; i < *n; i++)
        *(*arr + i) = *(*arr + i - 1) + *h;
    
    return 1;
}

long int calc_arr_num(elem_type h)
{
    long int n = (B - (A)) / h;
    
    return n; 
}

elem_type func(elem_type x)
{
    elem_type f = pow(x, 2) + x;       
    return f;
}

elem_type analitic_diff(elem_type x)
{
    elem_type f = 2*x + 1;
    return f;
}

elem_type aprox_diff(elem_type x, elem_type h)
{
    elem_type f = (func(x + h) - func(x)) / h;
    return f;
}

elem_type arithm_error(elem_type x, elem_type h)
{
    elem_type delta = fabs(analitic_diff(x) - aprox_diff(x, h));
    return delta;
}

void inf_print(long n, elem_type h, elem_type* arr)
{
    printf("\n");
    printf("____________________Stepping == %f", h);
    printf("\n");

    for(int i = 0; i < n; i++)
        printf("x = %f  |  f(x) = %f  |  aprox_diff = %f  |  analitic_diff = %f  |  arithmetical error = %f\n", arr[i], func(arr[i]), aprox_diff(arr[i], h), analitic_diff(arr[i]), arithm_error(arr[i], h));
}

void print_max_error(long n, elem_type h, elem_type* arr)
{
    elem_type max_err = arithm_error(arr[0], h);

    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            printf("\nPlease wait...\n");
        

        if(arithm_error(arr[i], h) > max_err)
            max_err = arithm_error(arr[i], h);
    }
    
    printf("\n__________________ maximum error = %f__________________\n", max_err);
}


void run(long n, elem_type h, elem_type* arr)
{
    int button;
    while(1)
    {
        printf("\nDo you want calculate all errors(press 1) or maximum error(press 2) or exit(3)\n");
        scanf("%d", &button);
        if(button == 1)
            inf_print(n, h, arr);
        else
        if(button == 2)
            print_max_error(n, h, arr);
        else
        if(button == 3)
            exit(EXIT_SUCCESS);
        else
        { 
            printf("\nInput error");
            exit(EXIT_FAILURE);
        }
    }
}



