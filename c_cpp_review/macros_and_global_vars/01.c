#include <features.h>
#include <stdio.h>

// Examples for each conditional macro:
// #if
// #ifdef
// #ifndef
// #elif
// #else
// #endif


// Define pi and a function for it
#define PI 3.14159
#define AREA(r) (PI*r*r)

// Define radius if it's not already defined
#ifndef radius
#define radius 7
#endif

// if elif else logic. We can use integer constants in these statements
#if radius > 10
#define radius 10
#elif radius < 5
#define radius 5
#else
#define radius 7
#endif

int main() {
    printf("Area of the circle with radius %d: %f\n", radius, AREA(radius));
}
