#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

List *create(void *data)
{
    List *new = malloc(sizeof(List));
    new->data = data;
    new->next = NULL;

    return new;
}

List *prepend(List *l, void *data)
{
    List *new = create(data);
    new->next = l;
    return new;
}

void square(void *i)
{
    int *i_ = i; // precisamos fazer cast para calcular o quadrado
    *i_ *= *i_;
}

void apply(List *l, void (*f)(void *))
{
    while (l)
    {
        f(l->data);
        l = l->next;
    }
}

void show_list(List *l)
{
    while (l)
    {
        printf("%d -> ", *(int *)l->data);
        l = l->next;
    }
    printf("X\n");
}

int main(int argc, char const *argv[])
{
    int x1 = 1, x2 = 2, x3 = 3, x4 = 4;

    List *l = prepend(prepend(prepend(create(&x1), &x2), &x3), &x4);
    show_list(l);
    apply(l, &square);
    show_list(l);

    return 0;
}
