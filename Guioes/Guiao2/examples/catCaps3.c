#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void toUpperStr(char *str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
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
    size_t len; // Será definido pela função getline quando alocar espaço para a
                // string
    while ((read = getline(&line, &len, fp)) != -1) {
        toUpperStr(line); // line conterá a linha toda (incluindo o newline)
        printf("%s", line);
    }
    free(line); // É preciso libertar a memória alocada

    fclose(fp);
    return 0;
}

