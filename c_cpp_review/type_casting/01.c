#include <stdio.h>

int main() {
    // c-style type casting
    float f = 69.69;
    int i = (int)f;
    printf("%d\n", i); // Gives a rounded down number (truncation) -> 69
    // to char
    char c = (char)i;
    printf("%c\n", c); // Outputs E (ASCII value of 69. Can reference https://www.asciitable.com/)
}
