#include <stdio.h>
#include "generic_stack.h"

int main() {
    stack s;
    StackNew(&s, sizeof(int));

    int push = 1;
    StackPush(&s, &push);

    int popped;
    StackPop(&s, &popped);

    printf("popped: %d\n", popped);
}
