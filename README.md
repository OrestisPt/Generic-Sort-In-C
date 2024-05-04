# Generic Sort Functions in C
 
## Files and Usablity

There are 2 files (plus an extra test for demonstration purposes):

 1. **sort.h:** Includes declarations of types and functions. Specifically it holds the types of function pointers that are used to achieve genericness and the declaration of **mergeSort()** and  **quickSort()**.
 2. **sort.c:** Includes the definition of the two sort functions.
 3.**test_sort.c:** Simple test for both functions with different types of arrays.

There is also a simple **Makefile** included that compiles and runs **test_sort.c** and shows how to link the **sort.c** file.

## 2. Quick explanation and information

Each sort function follows the standard procedure. **quickSort()** is implemented with the pivot being selected as the last item of each array/subarray.

In order for the functions to work the user has to provide 6 extra functions in order to manage the data he has inserted (So as to work for multiple types even ones the user creates). The functions are:

 1. void* CopyArr (void* array, int size)
 2. void Swap (void* valueA, void* valueB)
 3. int Compare (void* valueA, void* valueB)
 4. void* GetIthElement (void* array, int i)
 5. void SetIthElement (void* array, int i, void* value)

Each sort functions uses only a number of those so it isn't necessary for all functions to be implemented.

Each of these are typedef'ed as function pointers in **sort.h** and are pretty simple to undertsand and create. There are also 3-4 examples given in the **test_sort.c** file for different data types.

Both sort functions overwrite the array so as to be sorted and thus if the unsorted array held any importance it is advised to be copied in order not to lose the data. The sort functions dont free the user's array.

Both functions are leak-free, the user has to free only the memory he himself allocates.

The test file also includes printing functions which themselves are also generic thtough the use of the handler **printArray()**.