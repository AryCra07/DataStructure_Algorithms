#include "stdio.h"
#include "stdlib.h"

#define DELTA 0x80

struct sequenceList {
    int size, len;
    int *data;
};

struct sequenceList *createList(int size) {
    struct sequenceList *L = NULL;
    if (size > 0) {
        L = malloc(sizeof(struct sequenceList));
    }
    if (L != NULL) {
        L->data = malloc(size * sizeof(int));
        if (L->data == NULL) {
            free(L);
            return NULL;
        }
        L->size = size;
        L->len = 0;
    }
    return L;
}

int insertList(struct sequenceList *L, int i, int x) {
    if (L->len >= L->size) {
        puts("This sequence list is full!");
        return 0;
    }
    if (i < 0 || i > L->len) {
        puts("Invalid location to insert!");
    }
    for (int k = L->len; k > i; k--) {
        L->data[k] = L->data[k - 1];
    }
    L->data[i] = x;
    L->len++;
    return 1;
}

int insertListPlus(struct sequenceList *L, int i, int x) {
    if (i < 0 || i > L->len) {
        puts("Invalid location to insert!");
        return 0;
    }
    if (L->len >= L->size) {
        L->data = realloc(L->data, (L->size + DELTA) * sizeof(int));
        if (L->data == NULL) {
            puts("Insufficient memory!");
            exit(1);
        }
        L->size += DELTA;
    }
    for (int k = L->len; k > i; k--) {
        L->data[k] = L->data[k - 1];
    }
    L->data[i] = x;
    L->len++;
    return 1;
}

int deleteList(struct sequenceList *L, int i) {
    if (i < 0 || i >= L->len) {
        puts("Invalid location");
        return 0;
    }
    for (int k = i + 1; k < L->len; k++) {
        L->data[k - 1] = L->data[k];
    }
    L->len--;
    return 1;
}

int findLocationByKey(struct sequenceList *L, int value) {
    for (int k = 0; k < L->len; k++) {
        if (L->data[k] == value) {
            return k;
        }
    }
    return -1;
}

int mergeList(struct sequenceList *A, struct sequenceList *B, struct sequenceList *C) {
    int i = 0, j = 0, k = 0;
    while (i < A->len && j < B->len) {
        if (A->data[i] < B->data[j]) {
            C->data[k++] = A->data[i++];
        } else {
            C->data[k++] = B->data[j++];
        }
        if (k >= C->size) {
            puts("The list C overflows!");
        }
    }
    while (i < A->len) {
        C->data[k++] = A->data[i++];
        if (k >= C->size) {
            puts("The list C overflows!");
        }
    }
    while (j < B->len) {
        C->data[k++] = B->data[j++];
        if (k >= C->size) {
            puts("The list C overflows!");
        }
    }
    C->len = k;
    return 1;
}

int main() {
    puts("Hello world!");
    return 0;
}

