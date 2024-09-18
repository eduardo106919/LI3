#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *str) {
    int count = 0;
    char *token = strsep(&str, " ");

    while (token) {
        if (strlen(token) > 0) { // ignorar espaços consecutivos
            count++;
        }
        token = strsep(&str, " "); // obter próximo token
    }

    return count;
}

int main(int argc, char **argv) {
    FILE *fp = NULL;

    if (argc < 2) { // se não recebermos um ficheiro por argumento lemos do
                    // stdin (stdio.h)
        fp = stdin;
    } else {
        char *filename = argv[1];
        fp = fopen(filename, "r");
        if (!fp) {
            perror("Error");
            return 2;
        }
    }

    char *line = NULL;
    __ssize_t read;
    int count = 0;
    size_t len;

    while ((read = getline(&line, &len, fp)) != -1) {
        line[read - 1] = '\0'; // ignorar new line (\n)
        count += countWords(line);
    }

    printf("%d\n", count);

    return 0;
}