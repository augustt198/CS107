#include <stdio.h>
#include <string.h>

void* lsearch(void *key, void *base,
              int n, int elemSize,
              int (*cmpfn)(void *, void *)) {
    for (int i = 0; i < n; i++) {
        void *elemAddr = (char*) base + i * elemSize;
        if (cmpfn(key, elemAddr) == 0)
            return elemAddr;
    }
    return NULL;
}

int intcmp(void *e1, void *e2) {
    return *((int*) e1) - *((int*) e2);
}

int StrCmp(void *e1, void *e2) {
    return strcmp(*((char**) e1), *((char**) e2));
}

void findnotes() {
    char *notes[] = {"Ab", "F#", "B", "Gb", "D"};
    char *favoriteNote = "Eb";
    char **found = lsearch(
            &favoriteNote, notes, 5, sizeof(char*), StrCmp
    );

    if (found == NULL) {
        printf("not found\n");
    } else {
        printf("found: %s", *found);
    }
}

int main() {
    int array[] = {4, 2, 3, 7, 11, 6};
    int size = 6;
    int number = 7;
    void* found = lsearch(&number, array, 6, sizeof(int), intcmp);
    if (found == NULL) {
        printf("not found\n");
    } else {
        printf("found: %d\n", *((int*) found));
    }

    findnotes();
}
