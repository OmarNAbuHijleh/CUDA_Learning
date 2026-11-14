#include <stdio.h>

int main() {
    int arr[] = {4, 10, 15, -3, 80, 90, 2}; // Each element is 4 bytes by default (32 bits)
    int* ptr = arr; //ptr points to the first element in the array by default in C

    printf("Position one: %d\n", *ptr); // Should give 4
    
    for (int i = 0; i < 7; i++) {
        printf("%d ", *ptr); // Dereferencing the pointer
        printf("%p\n", ptr); // The memory address of our pointer
        ptr++; // increment our pointer. Since it is an integer pointer, it increments by 1 integer in memory!
    }

    // the pointer should be incrementing by 4 bytes each iteration of the loop
    // pointers are 64 bits in size (8 bytes)
    // arrays are laid out in memory contiguously 
}