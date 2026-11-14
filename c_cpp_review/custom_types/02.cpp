// cpp equivalent of 02.c

#include <iostream>

using namespace std;

typedef struct {
    float x;
    float y;
} Point;

int main() {
    Point p = {1.2, 3.0};
    printf("size of Point type is: %zu\n", sizeof(Point));
    return 0;
}
