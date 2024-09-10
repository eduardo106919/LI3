#ifndef LISTS_H
#define LISTS_H

typedef struct list
{
    void *data;
    struct list *next;
} List;

List *create(void *data);
List *prepend(List *l, void *data);
void square(void *i);
void apply(List *l, void (*f)(void *));
void show_list(List *l);




#endif