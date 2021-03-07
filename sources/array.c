#include <stdlib.h>
#include <string.h>
#include "../headers//array.h"


Array* constructor(struct meta info){

    Array* result = malloc(sizeof(Array));

    result->meta.size = info.size;
    result->meta.itemSize = info.itemSize;
    result->items = malloc(info.size * info.itemSize);
    result->meta.map = info.map;
    result->meta.where = info.where;
    result->meta.concantenate = info.concantenate;

    return result;
}

void delete(Array* array){
    free(array->items);
    free(array);
}

void set(Array* array, size_t index, void* item){
    void* pos = array->items + index * array->meta.itemSize;
    memcpy(pos, item, array->meta.itemSize);
}

void get(Array* array, size_t index, void* dest){
    void* pos = array->items + index * array->meta.itemSize;
    memcpy(dest, pos, array->meta.itemSize);
}


void expand(Array* array, size_t amout){

}

void trim(Array* array, size_t amout){

}