#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s string file", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *f;
    char line[MAX];

    if ((f = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Failed to open %s!", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, MAX, f) != NULL) {
        if (strstr(line, argv[1]) != NULL) {
            fputs(line, stdout);
        }
    }
    if (fclose(f) == EOF) {
        fprintf(stderr, "Failed to close %s!", argv[2]);
    }
    puts("Done!");
    return 0;
}
