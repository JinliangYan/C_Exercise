#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    int ch1, ch2;
    if (argc != 3) {
        fprintf(stderr, "Usage: %s file1 file2", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fp1, *fp2;
    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Failed to open %s.", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Failed to open %s.", argv[2]);
        exit(EXIT_FAILURE);
    }

    ch1 = getc(fp1);
    ch2 = getc(fp2);
    while (ch1 != EOF || ch2 != EOF) {
        while (ch1 != EOF && ch1 != '\n') {
            putchar(ch1);
            ch1 = getc(fp1);
        }
        if (ch1 != EOF) {
            putchar(ch1);
            ch1 = getc(fp1);
        }
        while (ch2 != EOF && ch2 != '\n') {
            putchar(ch2);
            ch2 = getc(fp2);
        }
        if (ch2 != EOF) {
            putchar(ch2);
            ch2 = getc(fp2);
        }
    }
    if (fclose(fp1)) {
        fprintf(stderr, "Failed to close %s.", argv[1]);
    }
    if (fclose(fp2)) {
        fprintf(stderr, "Failed to close %s.", argv[2]);
    }
}
