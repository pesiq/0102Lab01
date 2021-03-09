//
// Created by pesel on 18.02.2021.
//

#ifndef LAB01_ARRAY_H
#define LAB01_ARRAY_H

#include <stdlib.h>

typedef struct array Array;

struct meta{
    size_t size;
    size_t itemSize;

    void* (*trim_dynamic)(Array* array, size_t amount);
    void* (*pop_dynamic)(Array* array, void* item);
    void* (*delete_dynamic)(Array array);

    void* (*map) (void*, void*);
    void* (*where);
    void* concatenate;

};

struct array{
    void* items;
    struct meta meta;
};

//creation
Array* constructor(struct meta info);

//array resize
void expand(Array* array, size_t amount);
void trim(Array* array, size_t amount);
void push(Array* array, void* item);
void pop(Array* array, void* item);

//array access
void get(Array* array, size_t index, void* item);
void set(Array* array, size_t index, void* item);

//deletion
void delete(Array* array);

#endif //LAB01_ARRAY_H
