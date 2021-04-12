#include <stdlib.h>
#include "array.h"
#include <time.h>
#ifndef LAB01_FUNARRAY_H
#define LAB01_FUNARRAY_H

Array* new_fun_array(size_t size);
int fun_for_map_f(int (*item)(int, int));
int fun_for_where_f(int (*item)(int, int));

//functions to test array with
int sum(int a, int b);
int mult(int a, int b);
int sub(int a, int b);
int divis(int a, int b);

#endif
