#include "../headers/stringArray.h"

Array* map_s(Array* array){
    Array* result = copy(array);
    if(result) {
        int i;
        size_t size = getSize(result);
        char *pos = NULL;
        for (i = 0; i < size; i++) {
            get(result, i, &pos);
            *pos = '2';
            set(result, i, &pos);
        }
        return result;
    }
    return NULL;
}

void delete_d(Array* array) {
    if (array) {
        int i;
        size_t size = getSize(array);
        for (i = 0; i < size; i++) {
            char *pos = NULL;
            get(array, i, &pos);
            free(pos);
        }
        delete(array);
    }
}

void trim_d(Array* array, size_t amount){

}

Array* new_string_array(size_t size){
    struct meta info;

    info.delete_dynamic = &delete_d;
    info.map = &map_s;

    info.concatenate = NULL;
    info.where = NULL;

    size_t itemSize = sizeof(char*);
    return constructor(info, size, itemSize);
}
