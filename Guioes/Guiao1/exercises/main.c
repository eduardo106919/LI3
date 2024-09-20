/* main.c */
#include "deque.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum dequeOp {
    PUSH,
    PUSH_FRONT,
    POP,
    POP_FRONT,
    REVERSE,
    SIZE,
    IS_EMPTY
} DequeOp;

void print_int(void *i) {
    int *i_ = i;
    printf("%d", *i_);
}

int *random_int() {
    int *value = (int *)calloc(1, sizeof(int));
    assert(value);
    *value = rand() % 100;
    return value;
}

DequeOp random_command() { return rand() % 7; }

int main(int argc, char **argv) {
    srand(time(NULL));

    Deque *deque = create();
    push(deque, random_int());
    push(deque, random_int());
    push(deque, random_int());
    push(deque, random_int());
    push(deque, random_int());

    printDeque(deque, &print_int);

    int loop = rand() % 50;
    printf("Number of operations to do: %d\n", loop);

    for (int i = 0; i < loop; i++) {
        int *value = NULL;
        DequeOp operation = random_command();

        switch (operation) {
            case PUSH:
                value = random_int();
                printf("PUSH(%d) = ", *value);
                push(deque, value);
                break;
            case PUSH_FRONT:
                value = random_int();
                printf("PUSH_FRONT(%d) = ", *value);
                pushFront(deque, value);
                break;
            case POP:
                printf("POP = ");
                value = pop(deque);
                if (value)
                    free(value);
                break;
            case POP_FRONT:
                printf("POP_FRONT = ");
                value = popFront(deque);
                if (value)
                    free(value);
                break;
            case REVERSE:
                printf("REVERSE = ");
                reverse(deque);
                break;

            case SIZE:
                printf("SIZE: %d ", size(deque));
                break;

            case IS_EMPTY:
                printf("IS_EMPTY: %s ", isEmpty(deque) ? "TRUE" : "FALSE");
                break;
        }
        printDeque(deque, &print_int);
    }

    int *data = pop(deque);
    while (data) {
        free(data);
        data = pop(deque);
    }

    destroy(deque);

    return 0;
}