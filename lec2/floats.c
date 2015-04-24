#include <stdio.h>

int main() {
    int i = 37;
    float f = * (float*) &i;
    printf("%f\n", f);

    float f2 = 7.0;
    short s = *(short*) &f2;
    printf("%d\n", s);
}
