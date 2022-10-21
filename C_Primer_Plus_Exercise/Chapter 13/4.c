#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int ch;
    FILE *fp;
    if (argc < 2) {
        fprintf(stderr, "Usage: %s file1 file2 ...", argv[0]);
        exit(EXIT_FAILURE);
    }
    for (int i = 1; i < argc; i++) {
        printf("%%file %s:\n", argv[i]);
        if ((fp = fopen(argv[i], "r")) == NULL) {
            fprintf(stderr, "Failed to open %s", argv[i]);
            exit(EXIT_FAILURE);
        }
        while ((ch = getc(fp)) != EOF) {
            putc(ch, stdout);
        }
        if (fclose(fp) != 0) {
            fprintf(stderr, "Failed to close %s", argv[i]);
            exit(EXIT_FAILURE);
        }
        putchar('\n');
    }
    return 0;
}
