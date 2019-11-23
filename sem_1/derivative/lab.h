#ifndef LAB_H
#define LAB_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef float elem_type;



int read_and_create(elem_type* h, elem_type** arr, long int* n);
long  int calc_arr_num(elem_type h);
elem_type func(elem_type x);
elem_type analitic_diff(elem_type x);
elem_type aprox_diff(elem_type x, elem_type h);
elem_type arithm_error(elem_type x, elem_type h);
void inf_print(long n, elem_type h, elem_type* arr);
void print_max_error(long n, elem_type h, elem_type* arr);
void run(long n, elem_type h, elem_type* arr);


#endif