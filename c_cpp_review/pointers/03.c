// This one goes over VOID pointers
#include <stdio.h>


int main() {
    int num = 10;
    float fnum = 3.14;
    void* vptr; // Declaring our void pointer

    vptr = &num;
    printf("Integer: %d\n", *(int*)vptr); // Output 10
    // vptr is a memory address &num but it is stored as a void pointer (no data type)
    
    // We can't dereference a void pointer, so we have to cast it to an integer pointer to store the integer value at "*(int*)vptr"
    vptr = &fnum;

    printf("Float: %.2f\n", *(float*)vptr); // Output is 3.14
}

// Void pointers are used when we don't know the data type of the memory address
// malloc() returns a void pointer but we see it as a pointer to the specific type after the cast (int*)malloc(4) or (float*)malloc(4), etc.