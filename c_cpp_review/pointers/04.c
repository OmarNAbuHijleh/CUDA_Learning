// PURPOSE: Demonstrate the NULL pointer initialization and safe usage


// Key points:
// 1. Initialize pointers to be NULL when they do not yet point to valid data 
// 2. Check pointers for NULL before using to avoid crashes
// 3. NULL checks allow for graceful handling of uninitialized or failed allocations

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize pointer to NULL
    int* ptr = NULL;
    printf("1. Initialize pointer to null: %p\n", (void*)ptr);
    
    // Check for NULL before using:
    if (ptr == NULL) {
        printf("2. Pointer is NULL, cannot dereference");
    }
    
    // Allocate memory to the pointer so we can safely use it later on. Whatever is currently there in memory will be the pointer assignment
    ptr = malloc(sizeof(int)); // malloc stands for memory allocation. Allocates memory to the heap during program runtime
    if (ptr==NULL) {
        printf("3. Memory allocation failed\n");
        return 1;
    }
    
    printf("We have successfully assigned an address for the pointer!\n");
    printf("The memory address of the pointer is: %p\n", ptr);
    printf("The value stored at our memory address is: %d\n", *ptr);
    
    *ptr = 20;
    printf("We should now see 20 as the value stored at our pointer: %d\n", *ptr);
}