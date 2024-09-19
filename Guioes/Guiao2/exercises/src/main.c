#include "command_parser.h"
#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *fp = NULL;

    // control of arguments
    if (argc < 2) {
        fp = stdin;
    } else {
        char *filename = argv[1];
        fp = fopen(filename, "r");
        if (!fp) {
            perror("Error");
            return EXIT_FAILURE;
        }
    }

    char *line = NULL;
    __ssize_t read;
    size_t len;

    Deque *deque = create();

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        Cmd *command = parseLine(line);
        processCommand(deque, command);
        free(command);
    }

    free(deque);

    return EXIT_SUCCESS;
}