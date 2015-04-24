#include <stdio.h>

void swap(int *ap, int *bp) {
    int k = *ap;
    *ap = *bp;
    *bp = k;
}

int main() {
    int x = 7;
    int y = 117;

    swap(&x, &y);

    printf("x = %d, y = %d\n", x, y);
}
