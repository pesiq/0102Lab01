#include "../headers/intArray.h"

void fun_for_map_i(int n, int* res){
    *res = n * 2;
}
int fun_for_where_i(int n){
    return n > 10;
}

Array* map_i(void (*fun)(int, int*), Array* array){
    Array* result = copy(array);
    if(result) {
        int i;
        size_t size = getSize(result);
        int temp = 0, foo;
        for (i = 0; i < size; i++) {
            get(result, i, &temp);
            (*fun)(temp, &foo);
            set(result, i, &foo);
        }
        return result;
    }
    return NULL;
}

Array* where_i(int (*fun)(int), Array* array){
    size_t counter = 0, i;
    int temp;
    Array* result = copy(array);
    for(i = 0; i < getSize(array); i++){
        get(array, i, &temp);
        if((*fun)(temp)){
            set(result, counter, &temp);
            counter++;
        }
    }
    trim(result, (getSize(array) - counter));
    return result;
}

Array* concatenate_i(Array* a1, Array* a2){
    Array* result = copy(a1);
    if(result){
        if(expand(result, getSize(a2)) != 1) return NULL;
        int i, offset = getSize(a1);
        char * ptr = NULL;
        for(i = 0; i < getSize(a2); i++){
            get(a2, i, &ptr);
            set(result, offset + i, &ptr);
        }

    }
    return result;
}

Array* new_int_array(size_t size){
    struct meta info;
    info.map = &map_i;
    info.where = &where_i;
    info.concatenate = &concatenate_i;
    info.delete_dynamic = NULL;
    info.trim_dynamic = NULL;

    return constructor(info, size, sizeof(int));
}

Array* int_array_fromStatic(size_t size, int* array){

    Array* result = new_int_array(size);
    if(array && result){
        int i;
        for (i = 0; i < size; i++) {
            set(result, i, &array[i]);
        }
        return result;
    }
    return result;
}


