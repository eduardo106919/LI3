/* command_parser.h */

#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "deque.h"

typedef struct cmd {
    char *command;
    int *args; // NULL se não houver
    int nargs; // número de argumentos
} Cmd;

typedef enum dequeOp {
    PUSH,
    PUSH_FRONT,
    POP,
    POP_FRONT,
    REVERSE,
    SIZE,
    PRINT,
    NOTHING
} DequeOp;

void processCommand(Deque *deque, const Cmd *cmd);
Cmd *parseLine(char *line);

#endif