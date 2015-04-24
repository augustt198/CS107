#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "generic_stack.h"

void StackNew(stack *s, int elemSize) {
    assert(elemSize > 0);
    s->elemSize = elemSize;
    s->logicalLength = 0;
    s->allocatedLength = 4;
    s->elems = malloc(4 * elemSize);
    assert(s->elems != NULL);
}

void StackDispose(stack *s) {
    free(s->elems);
}

static void StackGrow(stack *s) {
    s->allocatedLength *= 2;
    s->elems = realloc(
            s->elems,
            s->allocatedLength * s->elemSize
    );
}

void StackPush(stack *s, void *elemAddr) {
    if (s->logicalLength == s->allocatedLength)
        StackGrow(s);
    void *target = (char*) s->elems +
        s->logicalLength * s->elemSize;
    memcpy(target, elemAddr, s->elemSize);
    s->logicalLength++;
}

void StackPop(stack *s, void *elemAddr) {
    s->logicalLength--;
    void *source = (char*) s->elems +
            (s->logicalLength) * s->elemSize;
    memcpy(elemAddr, source, s->elemSize);
}
