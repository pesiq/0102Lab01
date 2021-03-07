//
// Created by pesel on 18.02.2021.
//

#ifndef LAB01_ARRAY_H
#define LAB01_ARRAY_H

struct meta{
    size_t size;
    size_t itemSize;

    void* (*map) (void*, void*);
    void* (*where);
    void* concantenate;

};

typedef struct array{
    void* items;
    struct meta meta;
} Array;

Array* constructor(struct meta info);

void expand(Array* array, size_t amount);
void trim(Array* array, size_t amount);
void push(Array array, void* element);
void* pop(Array array);

void get(Array* array, size_t index, void* dest);
void set(Array* array, size_t index, void* item);

void delete(Array* array);

#endif //LAB01_ARRAY_H
