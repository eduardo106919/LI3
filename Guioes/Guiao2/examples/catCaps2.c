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
    if (argc < 2) {
        fprintf(stderr, "Missing filename.\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error"); // imprime "Error: No such file or directory" caso o
                         // ficheiro não exista
        return 2;
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
