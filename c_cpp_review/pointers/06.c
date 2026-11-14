#include <stdio.h>

// matrix -> array -> integers
// similar to 01.c but with arrays

int main() {
    int arr[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7, 8};
    int* ptr = arr; // Create a pointer who's value is the first value in the array
    int* ptr2 = arr2;
    int* matrix[] = {ptr, ptr2}; // Our matrix is an array of pointers to integer arrays, but what we have here is really a pointer to the first value of each array

    for (int i=0; i < 2; i++) { // use this to iterate over the matrix elements
        for (int j = 0; j < 4; j++) { // use this to iterate over the elements of the array our matrix pointer is at
            int* tmp = matrix[i]; // current array pointer
            int* current_array_value_pointer = tmp + j; // NOTE: Even though we're incrementing a pointer by the value of an integer (which is not a pointer), the gcc will know how much to increment the memory address because j is an int type and we're incrementing a pointer of int type. It knows how much to adjust the memory address as a result!
            printf("The current address we're pointing to is %p and its value is %d\n", current_array_value_pointer, *current_array_value_pointer);
        }
    }

}