#ifndef FLOAT_HEADER
#define FLOAT_HEADER
#include "array.h"
#endif
dynArray* create0float();
dynArray* createFromValues_float();

float* get_elem_float(size_t num_of_elem,dynArray* arr);
float* set_elem_float(size_t num_of_elem,float*,dynArray* arr);
dynArray* insert_elem_float(dynArray* arr);
void print_float(dynArray* arr);
dynArray* sort_float(dynArray* arr);

dynArray* concat_float(dynArray* elements1, dynArray* elements2);
void function_float(dynArray*,int);
int condition_float(dynArray*,int);