#include <stdio.h> // Standard io header file (for printf)

// "&" is the "address of" operator
// "*" is the "dereference" operator


int main() {
    int x = 10;
    int* ptr = &x; // "&" is used to get the memory address of a variable
    printf("Address of x: %p\n", ptr); 
    printf("Value of x: %d\n", *ptr); // Should output 10
    // * in the previous line is used to get the value from the memory address 

}