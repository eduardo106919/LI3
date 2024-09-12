/* deque.c */

#include "deque.h"

Deque *create()
{
    Deque *new = calloc(1, sizeof(Deque));

    // check if there is memory
    assert(new != NULL);

    new->size = 0;
    new->back = new->front = NULL;

    return new;
}

D_List *create_node(void *data)
{
    D_List *new_node = calloc(1, sizeof(D_List));
    assert(new_node != NULL);

    new_node->data = data;
    new_node->before = new_node->next = NULL;

    return new_node;
}

void push(Deque *deque, void *data)
{
    D_List *new_node = create_node(data);

    if (deque->back == NULL && deque->front == NULL)
    {
        deque->back = deque->front = new_node;
        deque->size++;
    }

    /*          QUESTION
        if there is only one element on the queue,
        the cases in which the front is a node and
        the back is NULL won't exist right?
    */

    deque->back->next = new_node;
    new_node->before = deque->back;
    deque->back = new_node;
}

void pushFront(Deque *deque, void *data)
{
    D_List *new_node = create_node(data);

    if (deque->back == NULL && deque->front == NULL)
    {
        deque->back = deque->front = new_node;
        deque->size++;
    }

    deque->front->next = new_node;
    new_node->before = deque->front;
    deque->front = new_node;
}

void *pop(Deque *deque)
{
    if (isEmpty(deque))
        return NULL;

    // if there is only one element, I have to change the front too
    if (deque->size == 1)
    {
        Deque *temp = deque->back;
        deque->back = deque->back->before; // == NULL
        deque->front = deque->front->next; // == NULL

        // QUESTION: return the node or just the data ??
        return temp;
    }

    Deque *temp = deque->back;
    deque->back = deque->back->before;

    return temp;
}

void *popFront(Deque *deque)
{
    if (isEmpty(deque))
        return NULL;

    // if there is only one element, I have to change the front too
    if (deque->size == 1)
    {
        Deque *temp = deque->back;
        deque->front = deque->front->next; // == NULL
        deque->back = deque->back->before; // == NULL

        // QUESTION: return the node or just the data ??
        return temp;
    }

    Deque *temp = deque->front;
    deque->front = deque->front->next;

    return temp;
}

int size(Deque *deque)
{
    return deque->size;
}

bool isEmpty(Deque *deque)
{
    return deque->size == 0;
}


// WHEN TO STOP IS THE PROBLEM !!!!!
void reverse(Deque *deque)
{
    while (deque->front && deque->back) {
        D_List * temp_front = deque->front->next;
        D_List * temp_back = deque->back->before;

        deque->front->next = deque->back->next;
        deque->back->next = temp_front;

        deque->back->before = deque->front->before;
        deque->front->before = temp_back;

        deque->front = temp_front;
        deque->back = temp_back;
    }
}

void printDeque(Deque *deque, void (*printFunc)(void *))
{
    D_List *temp = deque->front;
    while (temp)
    {
        printFunc(temp->data);
        temp = temp->next;
    }
}

void destroy(Deque *deque)
{
    while (deque->front && deque->back)
    {
        D_List *temp_front = deque->front->next;
        D_List *temp_back = deque->back->before;

        if (deque->front == deque->back)
        {
            free(deque->front);
            return;
        }
        else
        {
            free(deque->front);
            free(deque->back);
        }

        deque->front = temp_front;
        deque->back = temp_back;
    }
}
