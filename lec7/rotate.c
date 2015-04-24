#include <stdio.h>
#include <string.h>

void rotate(void *front, void *middle, void *end) {
    int frontSize = (char*) middle - (char*) front;
    int backSize = (char*) end - (char*) middle;
    char buffer[frontSize];
    memcpy(buffer, front, frontSize);
    memmove(front, middle, backSize);
    memcpy((char*) end - frontSize, buffer, frontSize);
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    int len = 5;
    rotate(array, array + 2, array + len);

    for (int i = 0; i < len; i++)
        printf("%d ", array[i]);

    printf("\n");
}
