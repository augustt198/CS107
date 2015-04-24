typedef struct {
    void *elems;
    int elemSize;
    int logicalLength;
    int allocatedLength;
} stack;

void StackNew(stack *s, int elemSize);
void stackDispose(stack *s);
void StackPush(stack *s, void *elemAddr);
void StackPop(stack *s, void *elemAddr);
