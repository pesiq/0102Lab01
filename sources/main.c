#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/array.h"

#define len 20
#define type char*

int main(){


    struct meta info;
    info.concatenate = NULL;
    info.where = NULL;
    info.map = NULL;
    info.itemSize = sizeof (type);
    info.size = 10;

    Array* arr = constructor(info);
    char* str = "0123456789123456789";
    int sin[len] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int* sin2 = NULL;
    char* str2 = NULL;
    int i, t;

    for(i = 0; i < 10; i++){
        //char* ptr = malloc(sizeof(int)*20);
        //memcpy(ptr, sin, sizeof(int)*20);
        set(arr, i, &str);
    }

    for(i = 0; i < 10; i++){
        get(arr, i, &str2);
        printf("index %d: item: %s\n", i, str2);
    }

    delete(arr);

    return 0;
}