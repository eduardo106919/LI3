/* command_parser.h */

#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "../deque_base/deque.h"

typedef struct cmd {
    char *command;
    int *args; // NULL se não houver
    int nargs; // número de argumentos
} Cmd;

void processCommand(Deque *deque, Cmd *cmd);
Cmd *parseLine(char *line);

#endif