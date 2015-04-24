#include <stdio.h>

int main() {
    double d = 3.1416;
    char ch = *(char*) &d;
    printf("%d\n", ch);
}
