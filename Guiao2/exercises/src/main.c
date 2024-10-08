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
        fp = fopen(argv[1], "r");
        if (!fp) {
            perror("Error");
            return EXIT_FAILURE;
        }
    }

    char *line = NULL;
    ssize_t read;
    size_t len;

    Deque *deque = create();

    // read each line of the file
    while ((read = getline(&line, &len, fp)) != -1) {
        // ignore new lines
        if (line[read - 1] == '\n')
            line[read - 1] = '\0';

        // create a command
        Cmd *command = parseLine(line);
        // execute the command on the deque
        processCommand(deque, command);

        // free the allocated space from the command
        free(command->args);
        free(command->command);
        free(command);
    }

    free(line);

    // free the allocated space from the deque
    int *data = (int *)pop(deque);
    while (data) {
        free(data);
        data = pop(deque);
    }

    destroy(deque);
    fclose(fp);

    return EXIT_SUCCESS;
}