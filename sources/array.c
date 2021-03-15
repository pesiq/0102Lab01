#include <string.h>
#include "../headers//array.h"


struct array{
    void* items;

    size_t size;
    size_t itemSize;

    struct meta fun;
};

// control
Array* constructor(struct meta info, size_t size, size_t itemSize){

    Array* result = malloc(sizeof(Array));

    if(!result)
        return NULL;

    result->items = malloc(size * itemSize);
    if(!result->items){
        free(result);
        return NULL;
    }

    result->size = size;
    result->itemSize = itemSize;
    result->fun.map = info.map;
    result->fun.where = info.where;
    result->fun.concatenate = info.concatenate;
    result->fun.delete_dynamic = info.delete_dynamic;
    result->fun.pop_dynamic = info.pop_dynamic;
    result->fun.trim_dynamic = info.trim_dynamic;

    return result;
}

Array* copy(Array* array){
    if(array) {

        Array* result = malloc(sizeof(Array));

        if(!result)
            return NULL;

        result->items = malloc(array->size * array->itemSize);
        if(!result->items){
            free(result);
            return NULL;
        }

        result->size = array->size;
        result->itemSize = array->itemSize;
        memcpy(result->items, array->items, result->size * result->itemSize);
        result->fun.map = array->fun.map;
        result->fun.where = array->fun.where;
        result->fun.concatenate = array->fun.concatenate;
        result->fun.delete_dynamic = array->fun.delete_dynamic;
        result->fun.pop_dynamic = array->fun.pop_dynamic;
        result->fun.trim_dynamic = array->fun.trim_dynamic;

        return result;
    }
    return NULL;
}

int delete(Array* array){
    if(array) {
        free(array->items);
        free(array);
        return 1;
    }
    return 0;
}

//access
int set(Array* array, int index, void* item){
    if(!array){
        return -1;
    }

    if(abs(index) >= array->size)
        return 0;

    void *pos;
    if (index >= 0) {
        pos = array->items + index * array->itemSize;

    } else{
        pos = array->items + (array->size + index) * array->itemSize;
    }
    memcpy(pos, item, array->itemSize);
    return 1;
}

int get(Array* array, int index, void* item){
    if(!array){
        return -1;
    }

    if(abs(index) >= array->size)
        return 0;

    void* pos;
    if(index >= 0) {
        pos = array->items + index * array->itemSize;
    }else{
        pos = array->items + (array->size + index) * array->itemSize;
    }
    memcpy(item, pos, array->itemSize);

    return 1;

}

size_t getSize(Array* array){
    if(array) {
        return array->size;
    }
    return -1;
}

//resize
int expand(Array* array, size_t amount){
    if(array) {
        array->size += amount;
        void* temp = realloc(array->items, (array->size) * array->itemSize);
        if(temp){
            array->items = temp;
            return 1;
        }
        return 0;
    }
    return -1;
}

int trim(Array* array, size_t amount){
    if(array) {
        array->size -= amount;
        void* temp = realloc(array->items, (array->size) * array->itemSize);
        if(temp){
            array->items = temp;
            return 1;
        }
        return 0;
    }
    return -1;
}

int push(Array* array, void* item){
    if(array) {
        array->size++;
        void* temp = realloc(array->items, array->size * array->itemSize);
        if(temp) {
            array->items = temp;
            void *ptr = array->items + array->size * array->itemSize;
            memcpy(ptr, item, array->itemSize);
        }
        return 0;
    }
    return -1;
}

int pop(Array* array, void* item) {
    if (array) {
        array->size--;
        void *ptr = array->items + array->size * array->itemSize;
        memcpy(item, ptr, array->itemSize);
        void* temp = realloc(array->items, array->size * array->itemSize);
        if(temp){
            array->items = temp;
            return 1;
        }
        return 0;
    }
    return -1;
}
//function access

int delete_dynamic(Array* array){
    if(array->fun.delete_dynamic) {
        array->fun.delete_dynamic(array);
        return 1;
    }
    return 0;
}

int pop_dynamic(Array* array, void* item){
    if(array->fun.pop_dynamic) {
        array->fun.pop_dynamic(array, item);
        return 1;
    }
    return 0;
}

int trim_dynamic(Array* array, size_t amount){
    if(array->fun.trim_dynamic) {
        array->fun.trim_dynamic(array, amount);
        return 1;
    }
    return 0;
}

Array* map(Array* array){
    return array->fun.map(array);
}