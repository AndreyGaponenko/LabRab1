#include <stdio.h>
#include "array.h"
#include "float_array.h"
#include "int_array.h"
#include "UI.h"
const char *MENU[]={"0.Integer", "1.Float", "2.Exit"};
const int MENU_SIZE = sizeof(MENU)/sizeof(MENU[0]);
const char *MENU1[]={"0.Insert element", "1.Delete element","2.Sort of array","3.Concatenation","4.Map","5.Where","6.Exit"};
const int MENU_SIZE1=sizeof(MENU1)/sizeof(MENU1[0]);
int interface (const char *menu[], int f){
    char *error="";
    int choice;
    do {
        puts(error);
        error="You're wrong. Try again!";
        for (int i=0; i<f; ++i){
            puts(menu[i]);
        }
        puts("Make your choice: ");
        choice=getchar();
        choice=choice-'0';
        if (choice==-38){
            choice=getchar()-'0';
        }
        while (getchar() != '\n') {}
    } while (choice < 0 || choice >= f);
    return choice;
}
void UI() {
    int choice1, choice2;
    do {
        printf("Choose a type of elements in array:");
        choice1 = interface(MENU, MENU_SIZE);
        switch (choice1) {
            case 0:
                puts("We are working with int array.");
                dynArray *arr1 = createFromValues_int();
                print_Array(arr1);
                do {
                    printf("Choose, what you want to do with array:");
                    choice2 = interface(MENU1, MENU_SIZE1);
                    switch (choice2) {
                        case 0:
                            arr1 = insert_elem_int(arr1);
                            print_Array(arr1);
                            break;
                        case 1:
                            printf("Enter e index of element, which we want to delete:");
                            int index;
                            scanf("%d", &index);
                            arr1 = delete_elem(arr1, index);
                            print_Array(arr1);
                            break;
                        case 2:
                            sort_array(arr1);
                            break;
                        case 3:
                            puts("enter second int array:");
                            dynArray *arr2 = createFromValues_int();
                            arr1 = concat_int(arr1, arr2);
                            print_Array(arr1);
                            break;
                        case 4:
                            map(arr1, arr1->function);
                            break;
                        case 5:
                            where(arr1, arr1->condition);
                            break;
                        case 6:
                            puts("Goodbye!");
                            break;
                    }
                } while (choice2 != 6);
                break;
            case 1:
                puts("We are working with float array.");
                dynArray *arr3 = createFromValues_float();
                print_Array(arr3);
                do {
                    printf("Choose, what you want to do with array:");
                    choice2 = interface(MENU1, MENU_SIZE1);
                    switch (choice2) {
                        case 0:
                            arr3 = insert_elem_float(arr3);
                            print_Array(arr3);
                            break;
                        case 1:
                            printf("Enter e index of element, which we want to delete:");
                            int index;
                            scanf("%d", &index);
                            arr3 = delete_elem(arr3, index);
                            print_Array(arr3);
                            break;
                        case 2:
                            sort_array(arr3);
                            break;
                        case 3:
                            puts("enter second float array:");
                            dynArray *arr4 = createFromValues_float();
                            arr1 = concat_int(arr3, arr4);
                            print_Array(arr3);
                            break;
                        case 4:
                            map(arr3, arr3->function);
                            break;
                        case 5:
                            where(arr3, arr3->condition);
                            break;
                        case 6:
                            puts("Goodbye!");
                            break;
                    }
                } while (choice2 != 6);
                break;
        }
    }while ((choice1 != 2)||(choice2 != 6));
}