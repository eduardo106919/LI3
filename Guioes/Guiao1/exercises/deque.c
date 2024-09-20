/* deque.c */

#include "deque.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* creates an empty deque */
Deque *create() {
    Deque *new = calloc(1, sizeof(Deque));
    assert(new != NULL); // check if there is memory

    return new;
}

/* creates a node with data */
D_List *create_node(void *data) {
    D_List *new_node = calloc(1, sizeof(D_List));
    assert(new_node != NULL); // check if there is memory

    new_node->data = data;

    return new_node;
}

/* adds an element to the back of the deque */
void push_aux(Deque *deque, void *data) {
    D_List *new_node = create_node(data);

    // if the deque is empty
    if (isEmpty(deque)) {
        deque->back = deque->front = new_node;
        deque->size++;
        return;
    }

    // attach the new node
    deque->back->next = new_node;
    new_node->before = deque->back;
    // replace the back
    deque->back = new_node;
    deque->size++;
}

/* adds an element to the front of the deque */
void pushFront_aux(Deque *deque, void *data) {
    D_List *new_node = create_node(data);

    // if the deque is empty
    if (isEmpty(deque)) {
        deque->back = deque->front = new_node;
        deque->size++;
        return;
    }

    // attach the new node
    deque->front->before = new_node;
    new_node->next = deque->front;
    // replace the front
    deque->front = new_node;
    deque->size++;
}

void push(Deque *deque, void *data) {
    deque->reversed ? pushFront_aux(deque, data) : push_aux(deque, data);
}

void pushFront(Deque *deque, void *data) {
    deque->reversed ? push_aux(deque, data) : pushFront_aux(deque, data);
}

/* removes the last node from the deque */
void *pop_aux(Deque *deque) {
    if (isEmpty(deque))
        return NULL;

    // detach the last node
    D_List *temp = deque->back;
    deque->back = temp->before;

    // if there is only one element, I have to change the front too
    if (deque->size == 1) {
        deque->front = deque->front->next; // == NULL
    } else {
        temp->before->next = NULL;
    }

    // free the space of the node
    void *temp_data = temp->data;
    free(temp);
    deque->size--;

    return temp_data;
}

/* removes the first node from the deque */
void *popFront_aux(Deque *deque) {
    if (isEmpty(deque))
        return NULL;

    // detach the front node
    D_List *temp = deque->front;
    deque->front = temp->next;

    // if there is only one element, I have to change the back too
    if (deque->size == 1) {
        deque->back = deque->back->before; // == NULL
    } else {
        temp->next->before = NULL;
    }

    // free the space of the node
    void *temp_data = temp->data;
    free(temp);
    deque->size--;

    return temp_data;
}

void *pop(Deque *deque) {
    return deque->reversed ? popFront_aux(deque) : pop_aux(deque);
}

void *popFront(Deque *deque) {
    return deque->reversed ? pop_aux(deque) : popFront_aux(deque);
}

/* returns the size of the deque */
int size(Deque *deque) { return deque->size; }

/* checks if the deque is empty */
bool isEmpty(Deque *deque) { return deque->size == 0; }

/* inverts the order of the deque */
void reverse(Deque *deque) { deque->reversed = !deque->reversed; }

/* shows the deque */
void printDeque(Deque *deque, void (*printFunc)(void *)) {
    D_List *temp = !deque->reversed ? deque->front : deque->back;
    printf("X <-> ");

    while (temp) {
        printFunc(temp->data);
        temp = !deque->reversed ? temp->next : temp->before;
        printf(" <-> ");
    }
    printf("X\n");
}

/* frees the space allocated by the deque */
void destroy(Deque *deque) {
    D_List *front = deque->front;

    while (front) {
        D_List *temp = front;
        front = front->next;
        free(temp);
    }

    free(deque);
}
