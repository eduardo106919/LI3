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

    char str[100];
    while (fgets(str, 100, fp)) {
        toUpperStr(str); // notar que str pode não conter a linha toda de uma
                         // vez se esta for maior que 100. O resto da linha
                         // estará nos próximos fgets
        printf("%s", str);
    }

    fclose(fp);
    return 0;
}
