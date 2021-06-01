#ifndef LABA1_INT_ARRAY_H
#define LABA1_INT_ARRAY_H
#include "array.h"
#endif //LABA1_INT_ARRAY_H
dynArray* create0int();
dynArray* createFromValues_int();

int* get_elem_int(size_t num_of_elem,dynArray* arr);
int* set_elem_int(size_t num_of_elem,int*,dynArray* arr);
dynArray* insert_elem_int(dynArray* arr);
void print_int(dynArray* arr);
dynArray* sort_int(dynArray* arr);

dynArray* concat_int(dynArray* elements1, dynArray* elements2);
void function_int(dynArray*,int);
int condition_int(dynArray*,int);