#include <stdlib.h>
#include <assert.h>
#include "stack.h"

int main() {
}

void StackNew(stack *s) {
    s->logicalLength = 0;
    s->allocatedLength = 0;
    s->elems = malloc(4 * sizeof(int));
}

void StackDispose(stack *s) {
    free(s->elems);
}

void StackPush(stack *s, int value) {
    if (s->logicalLength == s->allocatedLength) {
        s->allocatedLength *= 2;
        s->elems = realloc(
                s->elems,
                s->allocatedLength * sizeof(int)
        );
    }

    s->elems[s->logicalLength] = value;
    s->logicalLength++;
}

int StackPop(stack *s) {
    assert(s->logicalLength > 0);
    s->logicalLength--;
    return s->elems[s->logicalLength];
}
