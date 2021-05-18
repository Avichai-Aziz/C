#ifndef ARRRAY_H
#define ARRAY_H
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX_ARRAY_SIZE 1000000
typedef struct  Array* Array;
Array ArrayCreate(int arraysize,Element (*cpy)(Element), void (*fre)(Element)); /* creating array using linkedlist */ 
void ArrayDestroy(Array array); // destroyes the array.
int ArraySize(Array array); //returns the array size
void ArrayResize(Array array,int new_array_size); // resizing the array
void Arrayput(Array array,Element element,int index); // inserting the element to the array at the index requested
Element ArrayGet(Array array,int index); // returning the element at the requested index
#endif