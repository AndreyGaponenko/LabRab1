#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "float_array.h"
#include "stdint.h"
void* zero_float=NULL;

dynArray* create0float(){
    int dimension;
    printf("Enter a quantity of elements in array:");
    scanf("%d",&dimension);
    while(dimension<0){
        printf("Count can't be minus! Enter quantity again:\n");
        scanf("%d",&dimension);
    }
    if (zero_float==NULL){
        zero_float=malloc(sizeof(float));
        *(float*)zero_float=0.0f;
    }
    return create0(dimension, sizeof(float), 1, zero_float,print_float,sort_float,concat_float,function_float,condition_float);
}

dynArray* createFromValues_float(){
    int dimension;
    printf("Enter a quantity of elements in array:");
    scanf("%d",&dimension);
    while(dimension<0){
        printf("Count can't be minus! Enter quantity again:\n");
        scanf("%d",&dimension);
    }
    if (zero_float==NULL){
        zero_float=malloc(sizeof(float));
        *(float*)zero_float=0.0f;
    }
    float* arr1=malloc(dimension*sizeof(float));
    for (size_t i=0; i<dimension;i++){
        printf("Enter a %d element:",i);
        scanf("%f",arr1+i);
        //printf("\n");
    }
    return createFromValues(dimension,sizeof(float),1, zero_float,arr1,print_float,sort_float,concat_float,function_float,condition_float);
}

float* get_elem_float(size_t num_of_elem,dynArray* arr){
    return (float*)get_elem(num_of_elem,arr);
}

float* set_elem_float(size_t num_of_elem,float* value,dynArray* arr){
    return (float*)set_elem(num_of_elem,value,arr);
}

dynArray* insert_elem_float(dynArray* arr){
    int index_elem;
    printf("Enter a index of element, where you want to insert element:");
    scanf("%d",&index_elem);
    while((index_elem<0)||(index_elem>arr->dimension)){
        printf("Doesn't exist such index! Please, enter number from 0 to %d: ",arr->dimension);
        scanf("%d",&index_elem);
    }
    float* element=malloc(sizeof(float));
    printf("Enter a float number, which you want insert:");
    scanf("%f",element);
    return insert_elem(index_elem, element, arr);
}

void print_float(dynArray* arr){
    printf("Float array:\n");
    for (int i=0; i<arr->dimension; i++){
        printf("arr[%d]=%.4f\n",i,*(float*)(arr->elements+i*arr->elementSize));
    }
}

dynArray* sort_float(dynArray* arr){
    for (size_t i = 0; i < arr->dimension; i++) {
        float *element1 = (float *) arr->elements + i ;
        for (size_t j = 0; j < arr->dimension; j++) {
            float *element2 = (float *) arr->elements + j;
            if (*element1 < *element2) {
                float temp = *element1;
                memcpy((void *) element1, (void *) element2, arr->elementSize);
                *element2 = temp;
            }
        }
    }
    return arr;
}

dynArray* concat_float(dynArray* arr1, dynArray* arr2){
     arr1->elements=(float*)realloc(arr1->elements,((arr1->dimension)+(arr2->dimension)*(arr1->elementSize)));
     for (size_t i=0; i<arr2->dimension; i++){
         int8_t* position=(int8_t*)arr1->elements+arr1->dimension*arr1->elementSize+i*arr1->elementSize;
         memcpy((void*)position,(int8_t*)arr2->elements+i*arr2->elementSize,arr1->elementSize);
     }
     arr1->dimension=(arr1->dimension)+(arr2->dimension);
     return arr1;
}

void function_float(dynArray* arr, int index_elem){
    float* temp=(float*)arr->elements+index_elem;
    *temp=(*temp)*(*temp);
}

int condition_float(dynArray* arr, int index_elem){
    float* temp=(float*)arr->elements+index_elem;
    if(*temp>0.0){
        return 1;
    }else {return 0;}
}