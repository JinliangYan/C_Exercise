#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *f1, *f2;
    int ch1, ch2;
    if (argc != 3) {
        fprintf(stderr, "Usage: %s file1 file2", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((f1 = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Failed to open %s", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((f2 = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Failed to open %s", argv[2]);
        exit(EXIT_FAILURE);
    }
    ch1 = getc(f1);
    ch2 = getc(f2);
    while (ch1 != EOF || ch2 != EOF) {
        while (ch1 != EOF) {
            putchar(ch1);
            ch1 = getc(f1);
            if (ch1 == '\n') {
//                putchar('\n');
                ch1 = getc(f1);
                break;
            }
        }
        while (ch2 != EOF) {
            putchar(ch2);
            ch2 = getc(f2);
            if (ch2 == '\n') {
                putchar('\n');
                ch2 = getc(f2);
                break;
            }
        }
    }
    return 0;
}
