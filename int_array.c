#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "int_array.h"
#include "stdint.h"
void* zero_int=NULL;

dynArray* create0int(){
    int dimension;
    printf("Enter a quantity of elements in array:");
    scanf("%d",&dimension);
    while(dimension<0){
        printf("Count can't be minus! Enter quantity again:\n");
        scanf("%d",&dimension);
    }
    if (zero_int==NULL){
        zero_int=malloc(sizeof(int));
        *(int*)zero_int=0;
    }
    return create0(dimension, sizeof(int),0, zero_int,print_int,sort_int,concat_int,function_int,condition_int);
}

dynArray* createFromValues_int(){
    int dimension;
    printf("Enter a quantity of elements in array:");
    scanf("%d",&dimension);
    while(dimension<0){
        printf("Count can't be minus! Enter quantity again:\n");
        scanf("%d",&dimension);
    }
    if (zero_int==NULL){
        zero_int=malloc(sizeof(int));
        *(int*)zero_int=0;
    }
    int* arr1=malloc(dimension*sizeof(int));
    for (size_t i=0; i<dimension;i++){
        printf("Enter a %d element:",i);
        scanf("%d", arr1 + i);
        //printf("\n");
    }
    return createFromValues(dimension,sizeof(int),0,zero_int, arr1, print_int,sort_int, concat_int,function_int,condition_int);
}

int* get_elem_int(size_t num_of_elem,dynArray* arr){
    return (int*)get_elem(num_of_elem,arr);
}

int* set_elem_int(size_t num_of_elem,int* value,dynArray* arr){
    return (int*)set_elem(num_of_elem,value,arr);
}

dynArray* insert_elem_int(dynArray* arr){
    int index_elem;
    printf("Enter a index of element, where you want to insert element:");
    scanf("%d",&index_elem);
    while((index_elem<0)||(index_elem>arr->dimension)){
        printf("Doesn't exist such index! Please, enter number from 0 to %d: ",arr->dimension);
        scanf("%d",&index_elem);
    }
    int* element=malloc(sizeof(int));
    printf("Enter a int number, which you want insert:");
    scanf("%d",element);
    return insert_elem(index_elem, element, arr);
}
void print_int(dynArray* arr) {
    printf("Integer array:\n");
    for (int i = 0; i < arr->dimension; i++) {
        printf("arr[%d]=%d\n", i, *(int *) (arr->elements + i * arr->elementSize));
    }
}

dynArray* sort_int(dynArray* arr){
    for (int i = 0; i < arr->dimension; i++) {
        int *element1 = (int *) arr->elements + i;
        for (int j = 0; j < arr->dimension; j++) {
            int *element2 = (int *) arr->elements + j;
            if (*element1 < *element2) {
                int temp = *element1;
                memcpy((void *) element1, (void *) element2, arr->elementSize);
                *element2 = temp;
            }
        }
    }
    return arr;
}

dynArray* concat_int(dynArray* arr1, dynArray* arr2){
    arr1->elements=(int*)realloc(arr1->elements,((arr1->dimension)+(arr2->dimension)*(arr1->elementSize)));
    for (size_t i=0; i<arr2->dimension; i++){
        int8_t* position=(int8_t*)arr1->elements+arr1->dimension*arr1->elementSize+i*arr1->elementSize;
        memcpy((void*)position,(int8_t*)arr2->elements+i*arr2->elementSize,arr1->elementSize);
    }
    arr1->dimension=(arr1->dimension)+(arr2->dimension);
    return arr1;
}

void function_int(dynArray* arr,int index_elem){
    int* temp=(int*)arr->elements+index_elem;
    *temp=(*temp)*(*temp);
}

int condition_int(dynArray* arr, int index_elem){
    int* temp=(int*)arr->elements+index_elem;
    if(*temp>0){
        return 1;
    }else {return 0;}
}