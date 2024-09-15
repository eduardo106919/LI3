/* main.c */
#include "deque.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_int(void *i) {
    int *i_ = i;
    printf("%d", *i_);
}

int main() {
    srand(time(NULL));

    Deque *q = create();
    for (int i = 0; i < 5; i++) {
        printDeque(q, &print_int);
        int *value1 = malloc(sizeof(int));
        int *value2 = malloc(sizeof(int));
        assert(value1 && value2);

        *value1 = rand() % 100;
        *value2 = rand() % 100;
        pushFront(q, value1);
        push(q, value2);
    }

    printDeque(q, &print_int);
    pop(q);
    printDeque(q, &print_int);
    popFront(q);
    printDeque(q, &print_int);

    free(q);

    return 0;
}