#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *intMonthToStr(int monthInt) {
    char *monthStr = malloc(10 * sizeof(char));

    switch (monthInt) {
        case 1:
            strcpy(monthStr, "January");
            break;
        case 2:
            strcpy(monthStr, "February");
            break;
        case 3:
            strcpy(monthStr, "March");
            break;
        case 4:
            strcpy(monthStr, "April");
            break;
        case 5:
            strcpy(monthStr, "May");
            break;
        case 6:
            strcpy(monthStr, "June");
            break;
        case 7:
            strcpy(monthStr, "July");
            break;
        case 8:
            strcpy(monthStr, "August");
            break;
        case 9:
            strcpy(monthStr, "September");
            break;
        case 10:
            strcpy(monthStr, "October");
            break;
        case 11:
            strcpy(monthStr, "November");
            break;
        case 12:
            strcpy(monthStr, "December");
            break;
        default:
            break;
    }

    return monthStr;
}

void sayEntry(char *str) {
    int year, month, day, hour, minute, second;
    char *text = malloc((strlen(str) - 24) * sizeof(char));

    // %[^\n] significa "ler até encontrar um \n"
    sscanf(str, "[%d-%d-%d %d:%d:%d] - %[^\n]", &year, &month, &day, &hour,
           &minute, &second, text);

    char *monthFull = intMonthToStr(month);
    printf("On %s %d of %d, at %d:%d:%d, the log says: '%s'\n", monthFull, day,
           year, hour, minute, second, text);

    free(monthFull);
    free(text);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Missing filename.\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error");
        return 2;
    }

    char *line = NULL;
    __ssize_t read;
    size_t len;
    while ((read = getline(&line, &len, fp)) != -1) {
        sayEntry(line);
    }

    return 0;
}