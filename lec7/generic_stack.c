#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "generic_stack.h"

void StackNew(
        stack *s,
        int elemSize,
        void (*freefn)(void*)
    ) {

    assert(elemSize > 0);
    s->elemSize = elemSize;
    s->logicalLength = 0;
    s->allocatedLength = 4;
    s->elems = malloc(4 * elemSize);
    s->freefn = freefn;
    assert(s->elems != NULL);
}

void StackDispose(stack *s) {
    if (s->freefn != NULL) {
        for (int i = 0; i < s->logicalLength; i++) {
            s->freefn((char*) s->elems +
                    i * s->elemSize);
        }
    }

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
