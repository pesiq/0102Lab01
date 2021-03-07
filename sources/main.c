#include <stdio.h>
#include <stdlib.h>
#include "../headers/array.h"

int main(){

    struct meta info;
    info.concantenate = NULL;
    info.where = NULL;
    info.map = NULL;
    info.itemSize = sizeof (int);
    info.size = 10;

    Array* arr = constructor(info);

    int i, t;

    for(i = 0; i < 10; i++){
        set(arr, i, &i);
    }

    for(i = 0; i < 10; i++){
        get(arr, i, &t);
        printf("index %d: item: %d\n", i, t);
    }

    delete(arr);

    return 0;
}