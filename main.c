#include "array.h"
#include "float_array.h"
#include "int_array.h"
#include "UI.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    UI();
  dynArray* arr1=createFromValues_float();
  print_Array(arr1);
  dynArray* arr2=createFromValues_float();
  print_Array(arr2);
  arr1=concatenation(arr1,arr2);
  print_Array(arr1);
  arr1=delete_elem(arr1,2);
  sort_array(arr1);
  where(arr1,arr1->condition);
  print_Array(arr1);
  //map(arr1,arr1->function);
  //arr1=insert_elem_int(arr1);
  //print_Array(arr1);
  //map(arr1);
  //print_Array(arr1);
  //where(arr1);
  //print_Array(arr1);
}