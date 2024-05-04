#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "sort.h"

// Prints the ith element of the table
typedef void (*Print) (void*, int i);

// Some abritrary object
typedef struct{
    int age;
    char* name;
    char* surname;
}* Person;

char* randNames[] = {"John", "Jane", "Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hank", "Ivy", "Jack", "Kate", "Liam", "Mia", "Noah", "Olivia", "Paul", "Quinn", "Ryan", "Sara", "Tom", "Uma", "Vince", "Wendy", "Xander", "Yara", "Zane"};
char* randSurNames[] = {"Doe", "Smith", "Johnson", "Brown", "Lee", "Wilson", "Anderson", "Taylor", "Clark", "White", "Moore", "Hall", "Martin", "Thompson", "Garcia", "Martinez", "Robinson", "Lewis", "Walker", "Perez", "Hall", "Young", "Allen", "Sanchez", "Wright", "King", "Scott", "Green"};

int sizeNames = sizeof(randNames)/sizeof(randNames[0]);
int sizeSurNames = sizeof(randSurNames)/sizeof(randSurNames[0]);

Person createPerson(int age, char* name, char* surname){
    Person p = malloc(sizeof(*p));
    p->age = age;
    p->name = name;
    p->surname = surname;
    return p;
}

// Prints the table
void printArray(void* A, int n, Print print){
    for(int i = 0; i < n; i++){
        print(A, i);
    }
    printf("\n");
}

void printInts(int* a, int i){
    printf("%d ", a[i]);
}

void printStrings(char** a, int i){
    printf("%s ", a[i]);
}

void printFloats(float* a, int i){
    printf("%.2f ", a[i]);
}

void printPerson(Person* a, int i){
    printf("%s %s, %d years old\n", a[i]->name, a[i]->surname, a[i]->age);
}

void* copyArrInts(int* A, int n){
    int* B = (int *)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        B[i] = A[i];
    }
    return B;
}

void* copyArrStrings(char** A, int n){
    char** B = (char **)malloc(n * sizeof(char*));
    for(int i = 0; i < n; i++){
        B[i] = A[i];
    }
    return B;
}

void* copyArrPersons(Person* A, int n){
    Person* B = (Person *)malloc(n * sizeof(Person));
    for(int i = 0; i < n; i++){
        B[i] = A[i];
    }
    return B;
}

void setIthElementInts(int* table, int i, int* value){
    table[i] = *value;
}

void setIthElementStrings(char** table, int i, char** value){
    table[i] = *value;
}

void setIthElementPersons(Person* table, int i, Person* value){
    table[i] = *value;
}

void* getIthElementInts(int* table, int i){
    return table + i;
}

void* getIthElementStrings(char** table, int i){
    return table + i;
}

void* getIthElementFloats(float* table, int i){
    return table + i;
}

void* getIthElementPersons(Person* table, int i){
    return table + i;
}

void swap_ints(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_strings(char** a, char** b){
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void swap_floats(float* a, float* b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

void swap_persons(Person* a, Person* b){
    Person temp = *a;
    *a = *b;
    *b = temp;
}

int compare_ints(int* a, int* b){
    return (*a < *b);
}

int compare_strings(char** a, char** b){
    if(strcmp(*a, *b) < 0){
        return 1;
    }
    return 0;
}

int compare_floats(float* a, float* b){
    return (*a < *b);
}

int compare_persons(Person* a, Person* b){
    if(strcmp((*a)->name, (*b)->name) < 0){
        return 1;
    }
    else if(strcmp((*a)->name, (*b)->name) == 0){
        if(strcmp((*a)->surname, (*b)->surname) < 0){
            return 1;
        }
        else if(strcmp((*a)->surname, (*b)->surname) == 0){
            return (*a)->age < (*b)->age;
        }
    }
    return 0;
}

int main(){
    srand(time(NULL));
    int size = 10;
    int *array = malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        array[i] = rand() % 1000;
    }
    printArray(array, size, (Print)printInts);
    mergeSort(array, size, (CopyArr)copyArrInts, (Compare)compare_ints, (GetIthElement)getIthElementInts, (SetIthElement)setIthElementInts);
    printArray(array, size, (Print)printInts);
    printf("\n");
    free(array);

    char* array2[] = {"hello", "world", "this", "is", "a", "test"};
    size = sizeof(array2)/sizeof(array2[0]);
    printArray(array2, size, (Print)printStrings);
    mergeSort(array2, size, (CopyArr)copyArrStrings, (Compare)compare_strings, (GetIthElement)getIthElementStrings, (SetIthElement)setIthElementStrings);
    printArray(array2, size, (Print)printStrings);
    printf("\n");

    int arr[] = {8, 3, 0, 7, 2, 19, 78, 1, 100, 1000, 999, 99, 89, 56};
    size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, size, (Print)printInts);
    quickSort(arr, size, (GetIthElement)getIthElementInts, (Swap)swap_ints, (Compare)compare_ints, true);
    printArray(arr, size, (Print)printInts);
    printf("\n");

    char* arr2[] = {"hello", "world", "this", "is", "a", "test"};
    size = sizeof(arr2)/sizeof(arr2[0]);
    printArray(arr2, size, (Print)printStrings);
    quickSort(arr2, size, (GetIthElement)getIthElementStrings, (Swap)swap_strings, (Compare)compare_strings, true);
    printArray(arr2, size, (Print)printStrings);
    printf("\n");

    float arr3[] = {1.2, 3.4, 0.1, 0.0, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1};
    size = sizeof(arr3)/sizeof(arr3[0]);
    printArray(arr3, size, (Print)printFloats);
    quickSort(arr3, size, (GetIthElement)getIthElementFloats, (Swap)swap_floats, (Compare)compare_floats, true);
    printArray(arr3, size, (Print)printFloats);
    printf("\n");

    size = 10;
    Person* people = malloc(size * sizeof(Person));
    for(int i = 0; i < size; i++){
        people[i] = createPerson(rand() % 100, randNames[rand() % sizeNames], randNames[rand() % sizeSurNames]);
    }
    mergeSort(people, size, (CopyArr)copyArrPersons, (Compare)compare_persons, (GetIthElement)getIthElementPersons, (SetIthElement)setIthElementPersons);
    printArray(people, size, (Print)printPerson);
    for(int i = 0; i < size; i++){
        free(people[i]);
    }
    free(people);

    return 0;
}