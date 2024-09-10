#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv) {

    printf("%s recebeu %d argumentos.\n", argv[0], argc);

    int repeats = atoi(argv[2]); // atoi converte uma string para um inteiro
    while (repeats > 0) {
        printf("%s\n", argv[1]);
        repeats--;
    }

    return 0;
}