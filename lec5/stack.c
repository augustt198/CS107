#include <stdlib.h>
#include "stack.h"

int main() {
}

void StackNew(stack *s) {
    s->logicalLength = 0;
    s->allocatedLength = 0;
    s->elems = malloc(4 * sizeof(int));
}
