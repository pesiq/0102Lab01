#include <string.h>
#include "../headers//array.h"


Array* constructor(struct meta info){

    Array* result = malloc(sizeof(Array));

    result->meta.size = info.size;
    result->meta.itemSize = info.itemSize;
    result->items = malloc(info.size * info.itemSize);
    result->meta.map = info.map;
    result->meta.where = info.where;
    result->meta.concatenate = info.concatenate;

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

void get(Array* array, size_t index, void* item){
    void* pos = array->items + index * array->meta.itemSize;
    memcpy(item, pos, array->meta.itemSize);
}


void expand(Array* array, size_t amount){
    array->meta.size += amount;
    realloc(array->items, (array->meta.size) * array->meta.itemSize);
}

void trim(Array* array, size_t amount){
    array->meta.size -= amount;
    realloc(array->items, (array->meta.size) * array->meta.itemSize);
}

void push(Array* array, void* item){
    array->meta.size++;
    realloc(array->items, array->meta.size * array->meta.itemSize);
    void* ptr = array->items + array->meta.size * array->meta.itemSize;
    memcpy(ptr, item, array->meta.itemSize);
}

void pop(Array* array, void* item){
    array->meta.size--;
    void* ptr = array->items + array->meta.size * array->meta.itemSize;
    memcpy(item, ptr, array->meta.itemSize);
    realloc(array->items, array->meta.size * array->meta.itemSize);
}

/*
void delete_dynamic(Array* array){

    int i;
    for(i = 0; i < array->meta.size; i++){
        char** pos = (char **)(array->items + i * array->meta.itemSize);
        free(*pos);
    }

    free(array->items);
    free(array);
}
*/