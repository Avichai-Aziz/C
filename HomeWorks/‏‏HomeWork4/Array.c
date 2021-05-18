//Avichai Aziz & Asaf Ben Shabat.
#include "LinkedList.h"
#include "Array.h"
#include <stdio.h>
#include <stdlib.h>

struct Array
{
    LinkedList ll;
};

Array ArrayCreate(int arraysize, Element (*cpy)(Element), void (*fre)(Element))
{
    if (arraysize > MAX_ARRAY_SIZE) {
        fprintf(stderr, "the size you requesting for the array is too big ! file %s, line:%d\n", __FILE__, __LINE__);
        exit(-3);
    }
    Array array = (Array)malloc(sizeof(struct Array)); // freed by ArrayDestroy
    if (!array)
    {
        fprintf(stderr, "Error, memory not allocated! file : %s line : %d\n", __FILE__, __LINE__);
        exit(-2);
    }
    array->ll = LLCreate(cpy, fre); // allocate NULL as requsted.
    int i;
    for (i = 0; i < arraysize; i++)
    {
        LLAdd(array->ll, i, NULL);
    }
    return array;
}

void ArrayDestroy(Array array)
{
    LLDestroy(array->ll);
}

int ArraySize(Array array)
{
    return LLSize(array->ll);
}

void ArrayResize(Array array, int new_array_size)
{
    if (new_array_size < ArraySize(array))
    {
        unsigned int index = ArraySize(array);
        while (index != new_array_size)
        {
            LLRemove(array->ll, index);
            index--;
        }
    }

    else if (new_array_size > ArraySize(array))
    {
        unsigned int index2 = ArraySize(array);
        while (index2 < new_array_size)
        {
            LLAdd(array->ll, index2, NULL);
            index2++;
        }
    }

    else if (new_array_size > MAX_ARRAY_SIZE)
    {
        fprintf(stderr, "Error, the maximum size of the array is 1000000,entered: %d,File : %s, Line: %d\n", new_array_size, __FILE__, __LINE__);
	    exit(-3);
    }
}

Element ArrayGet(Array array, int index)
{
    if (index > ArraySize(array))
    {
        fprintf(stderr, "Error, over range exception, %d is too big ,File : %s, Line: %d\n", index, __FILE__, __LINE__);
	    return NULL;
    }
    Element temp_val = LLRemove(array->ll, index); //remove the element and placement the removed element to this variable
    Arrayput(array, temp_val, index); //add the removed element back to it place in the array 
    return temp_val;
}
void Arrayput(Array array, Element element, int index)
{
    if (index > ArraySize(array))
    {
        ArrayResize(array, index);
        LLAdd(array->ll, index, element);
    }
    else
    {
        LLAdd(array->ll, index, element);
    }
}
