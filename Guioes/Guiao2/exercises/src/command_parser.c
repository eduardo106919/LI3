/* command_parser.c */

#include "command_parser.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prints the value of an integer pointer */
void printInt(void *i) {
    int *i_ = i;
    printf("%d", *i_);
}

DequeOp cmdToOp(char *cmd) {
    if (!strcmp(cmd, "PUSH"))
        return PUSH;
    if (!strcmp(cmd, "PUSH_FRONT"))
        return PUSH_FRONT;
    if (!strcmp(cmd, "POP"))
        return POP;
    if (!strcmp(cmd, "POP_FRONT"))
        return POP_FRONT;
    if (!strcmp(cmd, "SIZE"))
        return SIZE;
    if (!strcmp(cmd, "PRINT"))
        return PRINT;
    if (!strcmp(cmd, "REVERSE"))
        return REVERSE;

    return NOTHING;
}

void processCommand(Deque *deque, Cmd *cmd) {
    switch (cmdToOp(cmd->command)) {
        case PUSH:
            for (int i = 0; i < cmd->nargs; i++) {
                push(deque, cmd->args + i);
            }
            break;
        case PUSH_FRONT:
            for (int i = 0; i < cmd->nargs; i++) {
                pushFront(deque, cmd->args + i);
            }
            break;
        case POP:
            int *value_back = (int *)pop(deque);
            if (value_back == NULL)
                puts("EMPTY");
            else {
                printInt(value_back);
                printf("\n");
            }
            break;
        case POP_FRONT:
            int *value_front = (int *)popFront(deque);
            if (value_front == NULL)
                puts("EMPTY");
            else {
                printInt(value_front);
                printf("\n");
            }
            break;
        case SIZE:
            int size_value = size(deque);
            printf("%d\n", size_value);
            break;
        case REVERSE:
            reverse(deque);
            break;
        case PRINT:
            printDeque(deque, &printInt);
            break;

        default: // case NOTHING
            break;
    }
}

Cmd *parseLine(char *line) {
    Cmd *new_command = (Cmd *)calloc(1, sizeof(Cmd));
    assert(new_command); // check if there is memory

    // the first word should be the command
    char *token = strsep(&line, " ");
    DequeOp operation = cmdToOp(token);

    if (operation != NOTHING) {
        new_command->command = strdup(token);
    } else {
        free(new_command->args);    // may not be necessary
        free(new_command->command); // may not be necessary
        free(new_command);

        // the command is not valid, so it's not worth to create it
        return NULL;
    }

    // no need to read the arguments, if it's not supposed to have arguments
    if ((operation != PUSH && operation != PUSH_FRONT) || line == NULL)
        return new_command;

    char *temp_copy = strdup(line);

    int count = 0;
    // count the number of arguments
    do {
        token = strsep(&line, " ");

        // strlen() does not take NULL
        if (token && strlen(token) > 0) {
            count++;
            // is it better this way or new_command->nargs++ ?? memory acesses
        }
    } while (token != NULL);

    new_command->nargs = count;
    // allocate the right amount of memory for the arguments
    new_command->args = (int *)calloc(count, sizeof(int));
    assert(new_command->args);

    // loop through the arguments a second time to store them
    for (int i = 0; i < count; i++) {
        token = strsep(&temp_copy, " ");
        if (strlen(token) > 0) {
            new_command->args[i] = atoi(token);
        }
    }

    free(temp_copy);

    return new_command;
}
