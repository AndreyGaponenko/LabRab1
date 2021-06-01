#pragma once
#include <string.h>
#include <stdint.h>
#ifndef ARRAY
#define ARRAY
#define INTEGER 0
#define FLOAT 1
#endif
typedef struct dynArray{
    size_t dimension;
    size_t elementSize;
    size_t type;
    void* elements;
    void* zero;
    struct dynArray* (*sort)(struct dynArray* arr);
    struct dynArray* (*concat)(struct dynArray* arr1, struct dynArray* arr2);
    void (*function)(struct dynArray* arr, int index_elem);
    void (*print)(struct dynArray* arr);
    int (*condition)(struct dynArray* arr, int index_elem);
} dynArray;

dynArray* create0(size_t dimension, size_t elementSize, size_t type, void* zero, void (*NewPrint)(dynArray*),dynArray*(*NewSort)(dynArray*), dynArray* (*NewConcat)(dynArray*, dynArray*),void (*function)(dynArray*, int),int (*condition)(dynArray*,int));
dynArray* createFromValues(size_t dimension, size_t elementSize, size_t type, void* zero, void* values,void (*NewPrint)(dynArray*), dynArray*(*NewSort)(dynArray*), dynArray* (*NewConcat)(dynArray*, dynArray*),void (*function)(dynArray*,int),int (*condition)(dynArray*,int));
void print_Array(dynArray* arr);

void* get_elem(size_t num_of_elem, dynArray* arr);
void* set_elem(size_t num_of_elem,void* values, dynArray* arr);
dynArray* insert_elem(int index_elem, void* value, dynArray* arr);
dynArray* delete_elem(dynArray* arr, int index_elem);

dynArray* concatenation(dynArray* arr1, dynArray* arr2);
void sort_array(dynArray* arr);
void map(dynArray* arr, void (*function)(dynArray*,int));
void where(dynArray* arr, int (*condition)(dynArray*,int));