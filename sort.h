#pragma once

#include <stdlib.h>
#include <stdbool.h>

// Copies the array A of size n into a new array and returns the address of the new array
typedef void* (*CopyArr) (void*, int);

// Swaps the values of a and b
typedef void (*Swap) (void*, void*);

// Must return 1 if a < b, 0 otherwise
typedef int (*Compare) (void*, void*);

// Returns the address of the ith element of the table
typedef void* (*GetIthElement) (void*, int);

// Sets the ith element of the table to value
typedef void (*SetIthElement) (void*, int, void*);

void quickSort(void* table, int size, GetIthElement getIthElement, Swap swap, Compare compare, bool ascending);

void mergeSort(void* table, int size, CopyArr copyArr, Compare compare, GetIthElement getIthElement, SetIthElement setIthElement);