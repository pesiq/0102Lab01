#include <stdlib.h>
#include "array.h"
#ifndef LAB01_INTARRAY_H
#define LAB01_INTARRAY_H

Array* new_int_array(size_t size);
Array* int_array_fromStatic(size_t size, int* array);
void fun_for_map_i(int n, int* res);
int fun_for_where_i(int n);

#endif
