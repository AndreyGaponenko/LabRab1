#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "array.h"

dynArray* create0(size_t dimensionNew, size_t elementSizeNew, size_t typeNew, void* zeroNew, void (*NewPrint)(dynArray*),dynArray*(*NewSort)(dynArray*), dynArray* (*NewConcat)(dynArray*,dynArray*),void (*Newfunction)(dynArray*,int),int (*Newcondition)(dynArray*,int)){
    dynArray* arr=malloc(sizeof(dynArray));
    arr->dimension=dimensionNew;
    arr->elementSize=elementSizeNew;
    arr->type=typeNew;
    arr->zero=zeroNew;
    arr->print=NewPrint;
    arr->sort=NewSort;
    arr->concat=NewConcat;
    arr->function=Newfunction;
    arr->condition=Newcondition;
    arr->elements=malloc(dimensionNew*elementSizeNew);
    for (size_t i=0; i<(arr->dimension);i++){
        int8_t* element=(int8_t*)arr->elements+i*arr->elementSize;
        memcpy((void*)element,arr->zero,arr->elementSize);
    }
    return arr;
}
dynArray* createFromValues(size_t dimensionNew, size_t elementSizeNew, size_t typeNew, void* zeroNew, void* values, void (*NewPrint)(dynArray*), dynArray*(*NewSort)(dynArray*), dynArray* (*NewConcat)(dynArray*, dynArray*),void (*Newfunction)(dynArray*,int),int (*Newcondition)(dynArray*,int)){
    dynArray* arr=malloc(sizeof(dynArray));
    arr->dimension=dimensionNew;
    arr->elementSize=elementSizeNew;
    arr->type=typeNew;
    arr->zero=zeroNew;
    arr->print=NewPrint;
    arr->sort=NewSort;
    arr->concat=NewConcat;
    arr->function=Newfunction;
    arr->condition=Newcondition;
    arr->elements=malloc(dimensionNew*elementSizeNew);
    for(size_t i=0; i<(arr->dimension);i++){
        int8_t* element=(int8_t*)arr->elements+i*arr->elementSize;
        memcpy((void*)element,(int8_t*)values+i*elementSizeNew,arr->elementSize);
    }
    return arr;
}

void print_Array(dynArray* arr){
arr->print(arr);
}

void* get_elem(size_t num_of_elem,dynArray* arr){
    return (void*)((int8_t*)arr->elements+num_of_elem*arr->elementSize);
}

void* set_elem(size_t num_of_elem,void* value, dynArray* arr){
    void* position=(int8_t*)(arr->elements+num_of_elem*arr->elementSize);
    memcpy(position,value,arr->elementSize);
}

dynArray* insert_elem(int index_elem, void* value, dynArray* arr){
    dynArray* result = create0 (arr->dimension+1, arr->elementSize, arr->type, arr->zero,arr->print,arr->sort, arr->concat, arr->function, arr->condition);
    int8_t* element=(int8_t*)result->elements;
    memcpy((void*)element,(int8_t*)arr->elements,index_elem*arr->elementSize);
    element=(int8_t*)result->elements+index_elem*arr->elementSize;
    memcpy(element, value, arr->elementSize);
    element=(int8_t*)result->elements+(index_elem+1)*arr->elementSize;
    memcpy((void*)element, (int8_t*)arr->elements+index_elem*arr->elementSize, (arr->dimension-index_elem)*arr->elementSize);
    free(arr);
    return result;
}

dynArray* delete_elem(dynArray* arr, int index_elem){
    while ((index_elem<0)||(index_elem>=arr->dimension)) {
        printf("You enter a index, which doesn't exist! Enter a number between 0 and %d", arr->dimension - 1);
        scanf("%d", &index_elem);
    }
    dynArray* arrNew=create0(arr->dimension-1,arr->elementSize, arr->type, arr->zero,arr->print,arr->sort, arr->concat,arr->function,arr->condition);
    int8_t* element=(int8_t*)arrNew->elements;
    memcpy((void*)element, arr->elements, index_elem*arr->elementSize);
    element=(int8_t*)arrNew->elements+index_elem*arrNew->elementSize;
    memcpy((void*)element,(int8_t*)arr->elements+(index_elem+1)*arr->elementSize,(arr->dimension-1-index_elem)*arr->elementSize);
    free(arr);
    return arrNew;
}

dynArray* concatenation(dynArray* arr1, dynArray* arr2){
    if (arr1->elementSize!=arr2->elementSize){
        int dimension;
        printf("Types of arr1 and arr2 don't match to each other! Please rewrite arr2.\n");
        return arr1;
    } else {
        arr1=arr1->concat(arr1,arr2);
        return arr1;
    }
}

void sort_array(dynArray* arr){
    arr->sort(arr);
    printf("Result after sorting of array:\n");
    print_Array(arr);
}

void map(dynArray* arr, void (*fun)(dynArray*,int)){
    printf("Map function for array:\n");
    for (int i=0; i<arr->dimension;i++){
        fun(arr,i);
    }
    print_Array(arr);
}

void where(dynArray* arr, int (*condition)(dynArray*,int)){
    printf("Array after function where:\n");
    int k=0;
    while (k<arr->dimension){
        if (!condition(arr,k)){
            arr=delete_elem(arr,k);
        }else {
            k += 1;
        }
    }
    print_Array(arr);
}