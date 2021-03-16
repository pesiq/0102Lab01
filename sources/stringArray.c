#include "../headers/stringArray.h"

Array* map_s(void (*fun)(char*), Array* array){
    Array* result = copy(array);
    if(result) {
        int i;
        size_t size = getSize(result);
        char *pos = NULL;
        for (i = 0; i < size; i++) {
            get(result, i, &pos);
            (*fun)(pos);
            set(result, i, &pos);
        }
        return result;
    }
    return NULL;
}

Array* where_s(int (*fun)(char*),Array* array){
    size_t counter = 0, i;
    char* ptr = NULL;
    Array* result = copy(array);
    for(i = 0; i < getSize(array); i++){
        get(array, i, &ptr);
        if((*fun)(ptr)){
            set(result, counter, &ptr);
            counter++;
        }

    }
    trim(result, (getSize(array) - counter));
    return result;
}

Array* concatenate_s(Array* a1, Array* a2){
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

void fun_for_map_s(char* str){
    str[0] = '6';
}

int fun_for_where_s(const char* str){
    if(strlen(str) > 45){
        return 1;
    }
    return 0;
}

int delete_d(Array* array) {
    if (array) {
        int i;
        size_t size = getSize(array);
        for (i = 0; i < size; i++) {
            char *pos = NULL;
            get(array, i, &pos);
            free(pos);
        }
        delete(array);
        return 1;
    }
    return 0;
}

int trim_d(Array* array, size_t amount){
    if(array){
        int i;
        for(i = 0; i < amount; i++){
            char* ptr = NULL;
            get(array, -i, ptr);
            free(ptr);
        }
        return trim(array, amount);
    }
    return -1;
}

Array* new_string_array(size_t size){
    struct meta info;

    info.trim_dynamic = &trim_d;
    info.delete_dynamic = &delete_d;
    info.map = &map_s;
    info.concatenate = &concatenate_s;
    info.where = &where_s;

    size_t itemSize = sizeof(char*);
    return constructor(info, size, itemSize);
}

char *getstring() {

    char buffer[121] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;

    do {
        n = scanf("%120[^\n]", buffer);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int part_len = strlen(buffer);
            int str_len = len + part_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buffer, part_len);
            len = str_len;
        } else {
            scanf("%*c");
        }

    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }
    return res;
}

char *generate_random(int seed) {

    srand(seed);
    const char charset[] = "    abcdefghijklmnopqrstuvwxyz  ";
    int len = rand() % 50 + 20;
    char *dest = calloc(len + 1, sizeof(char));

    int i;
    for (i = 0; i < len; i++) {
        dest[i] = charset[rand() % strlen(charset)];
    }
    dest[len] = '\0';
    return dest;
}