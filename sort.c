#include "sort.h"

void quickSort(void* table, int size, GetIthElement getIthElement, Swap swap, Compare compare, bool ascending){
    if(size <= 1)
        return;
    
    int pivot = size - 1;
    int i = -1;
    int j = 0;

    while (j != pivot){
        int condif = compare(getIthElement(table, j), getIthElement(table, pivot));
        if(ascending){
            condif = !condif;
        }
        if(condif){
            j++;
        } else{
            i++;
            swap(getIthElement(table, i), getIthElement(table, j));
            j++;
        }
    }
    i++;
    swap(getIthElement(table, pivot), getIthElement(table, i));
    
    quickSort(table, i, getIthElement, swap, compare, ascending);
    quickSort(getIthElement(table, i + 1), size - i - 1, getIthElement, swap, compare, ascending);

}

void mergeSort(void* table, int size, CopyArr copyArr, Compare compare, GetIthElement getIthElement, SetIthElement setIthElement){
    if(size <= 1){
        return;
    }
    void *subtable1 = copyArr(table, size/2);
    void *subtable2 = copyArr(getIthElement(table, size/2), size - size/2);


    mergeSort(subtable1, size/2, copyArr, compare, getIthElement, setIthElement);
    mergeSort(subtable2, size - size/2, copyArr, compare, getIthElement, setIthElement);
    int i = 0;
    int j = 0;
    for(int n = 0; n < size; n++){
        if(i < size/2 && (j >= (size - size/2) || compare(getIthElement(subtable1, i) , getIthElement(subtable2, j)))){
            setIthElement(table, n, getIthElement(subtable1, i));
            i++;
        } 
        else {
            setIthElement(table, n, getIthElement(subtable2, j));
            j++;
        }
    }

    free(subtable1);
    free(subtable2);
}