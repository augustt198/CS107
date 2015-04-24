#include <stdio.h>
#include <string.h>

void swap(void *vp1, void *vp2, int size) {
    char buffer[size];
    memcpy(buffer, vp1, size);
    memcpy(vp1, vp2, size);
    memcpy(vp2, buffer, size);
}

int main() {
    int a = 1;
    int b = 2;

    swap(&a, &b, sizeof(int));

    printf("a = %d\n", a);
    printf("b = %d\n" ,b);
}
