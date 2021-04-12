#include "../headers/funArray.h"
#include "../headers/intArray.h"

Array* map_f(int (*fun)(void*), Array* array){
    int (*temp)(int, int), i, size = getSize(array);
    Array* result = new_int_array(size);
    for(i = 0; i < size; i++){
        int t;
        get(array, i, &temp);
        t = fun(temp);
        set(result, i,&t);
    }
    return result;
}

Array* where_f(int (*fun)(void*), Array* array){
    Array* result = new_fun_array(getSize(array));
    int i, counter = 0, (*temp)(int, int);
    for (i = 0; i < getSize(array); i++){
        get(array, i, &temp);
        if(fun(temp)){
            set(result, counter, &temp);
            counter++;
        }
    }
    trim(result, (getSize(array) - counter));
    return result;
}

Array* concatenate_f(Array* a1, Array* a2){
    Array* result = copy(a1);
    if(result){
        if(expand(result, getSize(a2)) != 1) return NULL;
        int i, offset = getSize(a1);
        int (*temp)(int, int) = NULL;
        for(i = 0; i < getSize(a2); i++){
            get(a2, i, &temp);
            set(result, offset + i, &temp);
        }

    }
    return result;
}

Array* new_fun_array(size_t size){
    struct meta info;
    info.map = &map_f;
    info.where = &where_f;
    info.concatenate = &concatenate_f;

    info.trim_dynamic = NULL;
    info.delete_dynamic = NULL;

    return constructor(info, size, sizeof(&new_fun_array));
}

int fun_for_map_f(int (*item)(int, int)){
    return item(40, 4);
}
int fun_for_where_f(int (*item)(int, int)){
    return (item(40, 4) > 40);
}

int sum(int a, int b){
    return a + b;
}

int mult(int a, int b){
    return a * b;
}

int sub(int a, int b){
    return a - b;
}

int divis(int a, int b){
    return a / b;
}