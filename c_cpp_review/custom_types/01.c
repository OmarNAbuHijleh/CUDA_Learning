// size_t = size type for the memory type allocation (unsigned long -> uint64)
// size_t is an unsigned integer data type used to represent the size of the object in bytes
// It is guaranteed to be big enough to contain the size of the biggest object the host system can handle
//
// nothing special about size_t, it's just a type definition for unsigned long long int


#include <stdio.h>
#include <stdlib.h>


int main() {
    int arr[] = {12, 24, 36, 48, 60};

    /*
     * Explanation:
     * The "sizeof" function gives the size (in bytes) of the argument. In our case, this is the entire array for the numerator and the size of an individual element in the denominator.
     * The result in the below case is an unsigned size type, which will be the number of elements in our array, because:
     * The array has 5 elements that are 32bit integers (4 bytes each) -> 20 bytes
     * The first element is 4 bytes, so by taking this division we have the length of the array, which is 5
     */
    size_t size = sizeof(arr) / sizeof(arr[0]);

    /*
     * Printing some details and explaining each:
     * z -> size_t
     * u -> unsigned integer
     *
     */
    printf("Size of array %zu\n", size);
    printf("Size of size_t is %zu\n", sizeof(size));
    printf("Size of int in bytes is %zu\n", sizeof(int));
    return 0;
}
