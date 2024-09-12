/* deque.h */
#ifndef DEQUE_H
#define DEQUE_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Data structures

typedef struct d_list {
    void *data;
    struct d_list *before, *next;
} D_List;

typedef struct deque {
    int size;
    D_List *back, *front;
    // void (*elemPrint)(void *);
} Deque;

// Function declarations

Deque *create();
void push(Deque *deque, void *data);
void pushFront(Deque *deque, void *data);
void *pop(Deque *deque);
void *popFront(Deque *deque);
int size(Deque *deque);
bool isEmpty(Deque *deque);
void reverse(Deque *deque);
void printDeque(Deque *deque, void (*printFunc)(void *));
void destroy(Deque *deque);

#endif