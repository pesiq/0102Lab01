#ifndef LAB01_ARRAY_H
#define LAB01_ARRAY_H

#include <stdlib.h>

typedef struct array Array;

struct meta{
    void* (*trim_dynamic)(Array* array, size_t amount);
    void* (*pop_dynamic)(Array* array, void* item);
    void (*delete_dynamic)(Array* array);

    Array* (*map) (Array* array);
    void* (*where);
    Array* (*concatenate) (Array* a1, Array* a2);

};


//creation, returns array ptr upon success or nullptr upon failure
Array* constructor(struct meta info, size_t size, size_t itemSize);
Array* copy(Array* array);

//array resize, returns 1 upon success, -1 if array ptr null, 0 if failed resize operation;
int expand(Array* array, size_t amount);
int trim(Array* array, size_t amount);
int push(Array* array, void* item);
int pop(Array* array, void* item);

//array access, returns 1 if success, 0 if index out of bounds, -1 if array is NULL
int get(Array* array, int index, void* item);
int set(Array* array, int index, void* item);
size_t getSize(Array* array);

//function access, returns 1 if function present, 0 in function ptr == NULL
int trim_dynamic(Array* array, size_t amount);
int pop_dynamic(Array* array, void* item);
int delete_dynamic(Array* array);

Array* map(Array* array);

//deletion, returns 1 if success 0, if array ptr == NULL
int delete(Array* array);

#endif //LAB01_ARRAY_H
