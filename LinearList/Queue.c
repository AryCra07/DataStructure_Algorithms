#include "stdio.h"
#include "string.h"

const int N = 1e6 + 3;

struct Queue {
    int head;
    int tail;
    int q[N];
};

struct Queue initQueue() {
    struct Queue Q;
    Q.head = Q.tail = -1;
    memset(Q.q, -1, sizeof Q.q);
    return Q;
}

int isEmpty(struct Queue Q) {
    return Q.head == Q.tail;
}

int getSize(struct Queue Q) {
    return Q.tail - Q.head;
}

int getHead(struct Queue Q) {
    return Q.q[Q.head + 1];
}

int getTail(struct Queue Q) {
    return Q.q[Q.tail + 1];
}

void push(struct Queue Q, int x) {
    Q.q[++Q.tail] = x;
}

void pop(struct Queue Q) {
    Q.head++;
}

int clear(struct Queue Q) {
    Q.head = Q.tail = -1;
}