/* command_parser.h */

#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "deque.h"

typedef struct cmd Cmd;

typedef enum dequeOp DequeOp;

void processCommand(Deque *deque, const Cmd *cmd);
Cmd *parseLine(char *line);

#endif