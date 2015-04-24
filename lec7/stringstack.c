#include "generic_stack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void StringFree(void *elem) {
    free(*(char**) elem);
}

int main() {
    const char *friends[] = {"Al", "Bob", "Carl"};
    stack stringStack;

    StackNew(&stringStack, sizeof(char*), StringFree);
    for (int i = 0; i < 3; i++) {
        char *copy = strdup(friends[i]);
        StackPush(&stringStack, &copy);
    }

    char *name;
    for (int i = 0; i < 3; i++) {
        StackPop(&stringStack, &name);
        printf("%s\n", name);
        free(name);
    }

    StackDispose(&stringStack);
}
