#include "stack.h"
#include <stdio.h>
#include <string.h>

void printInt(void *data) {
    int *num = (int *)data;
    printf("%d", *num);
}

void printChar(void *data) {
    int *character = (int *)data;
    printf("%c", *character);
}

int main(int argc, char *argv[]) {
    Stack *stack1 = stackCreate(printInt);
    Stack *stack2 = stackCreate(printChar);

    int num = 10;
    char line[] = "Hello World";

    stackPush(stack1, (void *)&num);
    for (int i = 0; i < strlen(line); i++) {
        stackPush(stack2, (void *)&line[i]);
    }

    stackPrint(stack1);
    stackPrint(stack2);
}