#include "stdio.h"
#include "string.h"
#include "stdlib.h"

const int N = 1e6 + 3;

struct Stack {
    int TOP;
    int stk[N];
};

struct Stack initStack() {
    struct Stack S;
    S.TOP = -1;
    memset(S.stk, -1, sizeof S.stk);
}

int isEmpty(struct Stack S) {
    return S.TOP == -1;
}

int getSize(struct Stack S) {
    return S.TOP + 1;
}

int getTop(struct Stack S) {
    return S.stk[S.TOP];
}

void push(struct Stack S, int x) {
    S.stk[++S.TOP] = x;
}

void pop(struct Stack S) {
    S.TOP --;
}

void clear(struct Stack S) {
    S.TOP = -1;
}