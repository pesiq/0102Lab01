#include "../headers/menu.h"

Array* initMenu(){
    Array* menuFun = new_fun_array(7);
    unsigned int (*tmp)() = menuInitial;
    set(menuFun, 0, &tmp);
    tmp = menuStrings;
    set(menuFun, 1, &tmp);
    tmp = menuIntegers;
    set(menuFun, 2, &tmp);
    tmp = menuFunctions;
    set(menuFun, 3, &tmp);
    /*tmp = menuStrings2;
    set(menuFun, 4, tmp);
    tmp = menuIntegers2;
    set(menuFun, 5, tmp);
    tmp = menuFunctions2;
    set(menuFun, 6, tmp);
    */
    return menuFun;
}

unsigned int menuInitial(){
    unsigned int selection;
    printf("///-----MENU-----///\nPlease enter a number to select menu item\n");
    printf("1. String array\n2. Integer array\n3. Function array\n");
    do {
        if (scanf("%d", &selection) != 1) {
            scanf("%*[^\n]");
            selection = 9;
        }
        if (selection < 4) {
            return selection;
        }
        printf("Invalid input!\n");
    } while (1);
}

unsigned int menuStrings(){
    printf("///-----STRINGS-----///\nPlease enter a number to select menu item\n");
    printf("1. Enter strings manually\n2. Randomly generate strings\n");
    unsigned int selection, menu = 1;
    do {
        if (scanf("%d", &selection) != 1) {
            scanf("%*[^\n]");
            selection = 9;
        }

        if (selection > 2){
            printf("Invalid input!\n");
        }
        else
            menu = 0;
    } while (menu);
    if(!--selection){
        printf("///-----ENTER STRINGS MANUALLY------///\n");
        printf("Enter amount of strings: ");
        scanf("%d", &selection);
        scanf("%*[^\n]");
        scanf("%*c");
        fflush(stdin);
        Array* array = new_string_array(selection);
        printf("Created array id %d elements.\n", selection);
        int i;
        for(i = 0; i < selection; i++){
            char* temp = getstring();
            set(array, i, &temp);
        }
        printf("\nArray is: \n");
        for (i = 0; i < selection; i++) {
            char* temp = NULL;
            get(array, i, &temp);
            printf("%s\n", temp);
        }

        delete_dynamic(array);
    }
}

unsigned int menuIntegers(){
    printf("///-----INTEGERS-----///\nPlease enter a number to select menu item\n");
    printf("1. Enter number array manually\n2. Randomly generate array\n");
    unsigned int selection;
    do {
        if (scanf("%d", &selection) != 1) {
            scanf("%*[^\n]");
            selection = 9;
        }
        if (selection < 3) {
            return selection;
        }
        printf("Invalid input!\n");
    } while (1);
}

unsigned int menuFunctions(){
    printf("///-----FUNCTIONS-----///\nPlease enter a number to select menu item\n");
    printf("1. Enter strings manually\n2. Randomly generate strings");
    unsigned int selection;
    do {
        if (scanf("%d", &selection) != 1) {
            scanf("%*[^\n]");
            selection = 9;
        }
        if (selection < 3) {
            return selection;
        }
        printf("Invalid input!\n");
    } while (1);
}