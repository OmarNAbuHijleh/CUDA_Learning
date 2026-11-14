#include <stdio.h>

// Creating a new type definition using a struct
typedef struct {
    float x;
    float y;
} Point;

int main() {
    Point p = {1.2, 3.0};
    printf("size of Point: %zu\n", sizeof(Point)); // Output is 8 bytes --> 4 bytes for x float and 4 bytes for y float
}
