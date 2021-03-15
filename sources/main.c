#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../headers/array.h"
#include "../headers/stringArray.h"

#define len 60
#define type char*

int main(){


    /*struct meta info;
    info.concatenate = NULL;
    info.where = NULL;
    info.map = NULL;
    size_t itemSize = sizeof (type);
    size_t size = 10;
*/
    Array* arr = new_string_array(10);
    char* str = "0123456789123456789";
    int sin[len] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int* sin2 = NULL;
    char* str2 = NULL;
    int i, t;

    for(i = 0; i < 10; i++){
        char* ptr = malloc(20 * sizeof(char));
        memcpy(ptr, str, 20 * sizeof(char));
        printf("Set was successful?: %d\n",set(arr, i, &ptr));
    }

    Array* mapped = map(arr);

    for(i = 0; i < 10; i++){
        printf("Get successful?: %d ",get(arr, i, &str2));
        printf("index %d: item: %s\n", i, str2);
    }

    for(i = 0; i < 10; i++){
        printf("Get successful?: %d ",get(mapped, i, &str2));
        printf("index %d: item: %s\n", i, str2);
    }

    //delete_dynamic(mapped);
    delete(mapped);
    delete_dynamic(arr);

    //delete(arr);

/*
    int arr[len] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    printf("Size in bytes: %zu\n", sizeof(arr));

    printf("Size: %zu\n", sizeof(arr)/ sizeof(int));
*/

    return 0;
}