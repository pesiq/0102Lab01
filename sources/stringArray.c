#include "../headers/stringArray.h"

Array* new_string_array(size_t size){
    struct meta info;

    info.size = size;
    info.itemSize = sizeof(char*);
    return constructor(info);
}
