#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../headers/array.h"
#include "../headers/intArray.h"
#include "../headers/stringArray.h"
#include "../headers/funArray.h"

//abstract tests
void abstest() {
    struct meta abstract;
    abstract.map = NULL;
    int t1 = 10, t2 = 20, t3;

    //creation with no functions
    Array * absarr = constructor(abstract, 10, sizeof(int));
    assert(absarr != NULL);
    assert(getSize(absarr) == 10);
    puts("Abstract Array creation OK!");

    //copy
    Array* abscpy = copy(absarr);
    assert(abscpy != NULL);
    assert(getSize(abscpy) == 10);
    puts("Abstract Array copy OK!");

    //resize
    assert(expand(NULL, 10) == -1);
    assert(trim(NULL, 10 == -1));

    assert(expand(absarr, 20) == 1);
    assert(getSize(absarr) == 30);

    assert(trim(absarr, 10) == 1);
    assert(getSize(absarr) == 20);
    puts("Abstract resize OK!");

    //access
    assert(getSize(NULL) == -1);
    assert(get(NULL, 1, &t1) == -1);
    assert(set(NULL, 1, &t1) == -1);

    assert(getSize(absarr) == 20);
    assert(trim(absarr, 20) == 1);
    assert(getSize(absarr) == 0);

    for(int i = 0; i < 10; i++) {
        assert(set(abscpy, i, &t1) == 1);
    }
    for(int i = 0; i < 10; i++) {
        int temp;
        assert(get(abscpy, i, &temp) == 1);
        assert(t1 == temp);
    }

    for(int i = 10; i > 0; i--) {
        assert(set(abscpy, -10, &t2) == 1);
    }
    for(int i = 10; i > 0; i--) {
        int temp;
        assert(get(abscpy, -10, &temp) == 1);
        assert(t2 == temp);
    }
    puts("Abstract access OK!");


    //combined
    assert(push(NULL, &t1) == -1);
    assert(pop(NULL, &t3) == -1);

    puts("Combined access + resize OK!");

    //destruction
    assert(delete(absarr));
    assert(delete(abscpy));
    puts("Abstract deletion OK!");
}

void inttest(){
    Array* intarr = new_int_array(10);
    assert(intarr != NULL);
    assert(getSize(intarr) == 10);
    puts("Integer Array creation OK!");

    int stat[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    Array* statarr = int_array_fromStatic(10, stat);
    assert(getSize(statarr) == 10);
    for(int i = 0; i < 10; i++){
        int temp;
        get(statarr, i, &temp);
        assert(temp == i + 1);
    }
    puts("Integer Array from static OK!");

    //integer functions test
    Array* maptest = map(fun_for_map_i, statarr);
    assert(maptest != NULL);
    for(int i = 0; i < 10; i++){
        int temp;
       assert(get(maptest, i, &temp) == 1);
       assert(temp == (i+1)*2);
    }
    puts("Integer Array map OK!");

    Array* wheretest = where(fun_for_where_i, statarr);
    assert(wheretest != NULL);
    assert(getSize(wheretest) == 5);
    for (int i = 0; i < getSize(wheretest); i++) {
        int temp;
        assert(get(wheretest, i, &temp) == 1);
        assert(temp == i + 6);
    }
    puts("Int Array where OK!");

    Array* contest = concatenate(maptest, wheretest);
    assert(contest != NULL);
    for (int i = 0; i < getSize(contest); i++) {
        int temp, t1;
        get(contest, i, &temp);
        if(i < 10) {
            get(maptest, i, &t1);
            assert(t1 == temp);
        } else{
            get(wheretest, i - 10, &t1);
            assert(temp == t1);
        }
    }
    puts("Int Array concatenate OK!");

    assert(trim_dynamic(intarr, 10) == 0);
    assert(delete_dynamic(intarr) == 0);
    puts("Absent Integer Array functions OK!");

    assert(delete(intarr) == 1);
    assert(delete(statarr) == 1);
    assert(delete(wheretest) == 1);
    assert(delete(maptest) == 1);
    assert(delete(contest) == 1);
    puts("Integer Array destruction OK!");
}

void stringtest(){
    Array* strarr = new_string_array(10);
    assert(strarr != NULL);
    Array* dyn = copy(strarr);
    assert(dyn != NULL);
    puts("String creation OK!");

    char* a = "123456789";
    char* b = "abcdefg";

    for (int i = 0; i < 10; i++) {
        if(i % 2 == 0){
            assert(set(strarr, i, &a) == 1);
        }else{
            assert(set(strarr, i, &b) == 1);
        }
    }

    for (int i = 0; i < 10; i++) {
        char* temp;
        if(i % 2 == 0){
            assert(get(strarr, i, &temp) == 1);
            assert(strcmp(a, temp) == 0);
        }else{
            assert(get(strarr, i, &temp) == 1);
            assert(strcmp(b, temp) == 0);
        }
    }
    assert(delete(strarr) == 1);
    puts("Static string OK!");

    //allocated strings
    for (int i = 0; i < 10; i++) {
        char* temp;
        if(i % 2 == 0){
            size_t t = sizeof(char*) * strlen(a);
            temp = malloc(t);
            memcpy(temp, a, t);
            assert(set(dyn, i, &temp) == 1);
        }else{
            size_t t = sizeof(char*) * strlen(b);
            temp = malloc(t);
            memcpy(temp, b, t);
            assert(set(dyn, i, &temp) == 1);
        }
    }
    puts("Setting allocated str OK!");

    assert(trim_dynamic(dyn, 2) == 1);
    assert(getSize(dyn) == 8);
    puts("Dynamic resize OK!");

    Array* dynw = where(fun_for_where_s, dyn);
    assert(dynw != NULL);
    assert(getSize(dynw) == 4);


    Array* dynm = map(fun_for_map_s, dyn);
    for (int i = 0; i < getSize(dynm); i++) {
        char* temp;
        assert(get(dynm, i, &temp) == 1);
        assert(*temp == '6');
    }
    puts("String functions OK!");


    assert(delete_dynamic(dyn) == 1);
    assert(delete(dynw) == 1);
    assert(delete(dynm) == 1);
    puts("Dynamic destruction OK!");


}

void funtest(){
    Array* array = new_fun_array(4);
    assert(array != NULL);
    puts("Fun creation OK!");

    int (*temp)(int a, int b);
    temp = sum;
    assert(set(array, 0, &temp) == 1);
    temp = sub;
    assert(set(array, 1, &temp) == 1);
    temp = mult;
    assert(set(array, 2, &temp) == 1);
    temp = divis;
    assert(set(array, 3, &temp) == 1);


    for (int i = 0; i < 4; i++) {
        assert(get(array, i, &temp) == 1);
        int t = temp(40, 4);
        switch (i) {
            case 0:
                assert(t == 44);
                break;
            case 1:
                assert(t == 36);
                break;
            case 2:
                assert(t == 160);
                break;
            case 3:
                assert(t == 10);
                break;
        }
    }
    puts("Funtest get/set OK!");

    Array* funm = map(fun_for_map_f, array);
    assert(funm != NULL);
    for (int i = 0; i < 4; i++) {
        int t;
        assert(get(funm, i, &t) == 1);
        switch (i) {
            case 0:
                assert(t == 44);
                break;
            case 1:
                assert(t == 36);
                break;
            case 2:
                assert(t == 160);
                break;
            case 3:
                assert(t == 10);
                break;
        }
    }

    Array* funw = where(fun_for_where_f, array);
    assert(funw != NULL);
    assert(getSize(funw) == 2);

    delete(array);
    delete(funm);
    delete(funw);
    puts("Fun Array destruction OK!");
}

int main(){
    abstest();
    inttest();
    stringtest();
    funtest();
}