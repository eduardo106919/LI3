/* deque.c */

#include "deque.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Deque *create() {
    Deque *new = calloc(1, sizeof(Deque));

    // check if there is memory
    assert(new != NULL);

    new->size = 0;
    new->back = new->front = NULL;

    return new;
}

D_List *create_node(void *data) {
    D_List *new_node = calloc(1, sizeof(D_List));
    assert(new_node != NULL);

    new_node->data = data;
    new_node->before = new_node->next = NULL;

    return new_node;
}

void push(Deque *deque, void *data) {
    D_List *new_node = create_node(data);

    if (deque->back == NULL && deque->front == NULL) {
        deque->back = deque->front = new_node;
        deque->size++;
        return;
    }

    /*          QUESTION
        if there is only one element on the queue,
        the cases in which the front is a node and
        the back is NULL won't exist right?
    */

    deque->back->next = new_node;
    new_node->before = deque->back;
    deque->back = new_node;
    deque->size++;
}

void pushFront(Deque *deque, void *data) {
    D_List *new_node = create_node(data);

    if (deque->back == NULL && deque->front == NULL) {
        deque->back = deque->front = new_node;
        deque->size++;
        return;
    }

    deque->front->before = new_node;
    new_node->next = deque->front;
    deque->front = new_node;
    deque->size++;
}

void *pop(Deque *deque) {
    if (isEmpty(deque))
        return NULL;

    D_List *temp = deque->back;
    deque->back = temp->before;
    deque->back->next = NULL;

    // if there is only one element, I have to change the front too
    if (deque->size == 1) {
        deque->front = deque->front->next; // == NULL
        deque->front->before = NULL;       // necessary ????
    }

    void *temp_data = temp->data;
    free(temp);
    deque->size--;

    return temp_data;
}

void *popFront(Deque *deque) {
    if (isEmpty(deque))
        return NULL;

    D_List *temp = deque->front;
    deque->front = temp->next;
    deque->front->before = NULL;

    // if there is only one element, I have to change the back too
    if (deque->size == 1) {
        deque->back = deque->back->before; // == NULL
        deque->back->next = NULL;          // necessary ????
    }

    void *temp_data = temp->data;
    free(temp);
    deque->size--;

    return temp_data;
}

int size(Deque *deque) { return deque->size; }

bool isEmpty(Deque *deque) { return deque->size == 0; }

void reverse(Deque *deque) {
    int aux = 0;
    while (deque->front && deque->back && !aux) {
        D_List *temp_front = deque->front->next;
        D_List *temp_back = deque->back->before;

        deque->front->next = deque->back->next;
        deque->back->next = temp_front;

        deque->back->before = deque->front->before;
        deque->front->before = temp_back;

        deque->front = temp_front;
        deque->back = temp_back;

        // first case is for odd size queues, second is for even size queues
        if (deque->front == deque->back || deque->front->next == deque->back)
            aux = 1;

        break;
    }
}

void printDeque(Deque *deque, void (*printFunc)(void *)) {
    D_List *temp = deque->front;
    printf("X <-> ");

    while (temp) {
        printFunc(temp->data);
        temp = temp->next;
        printf(" <-> ");
    }
    printf("X\n");
}

void destroy(Deque *deque) {
    while (deque->front && deque->back) {
        D_List *temp_front = deque->front->next;
        D_List *temp_back = deque->back->before;

        if (deque->front == deque->back) {
            free(deque->front);
            return;
        } else {
            free(deque->front);
            free(deque->back);
        }

        deque->front = temp_front;
        deque->back = temp_back;
    }
}
