#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096

void append(FILE *dest_file, FILE *source_file);
int main(int argc, char *argv[]){
    FILE *fa, *fs;
    int file_num = argc - 2;
    if (file_num < 1) {
        fprintf(stderr, "Usage: %s dest_file file1 file2 ...", argv[0]);
        exit(EXIT_FAILURE);
    }
    if ((fa = fopen(argv[1], "ab")) == NULL) {
        fprintf(stderr, "Failed to open %s.", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE)) {
        fprintf(stderr, "Failed to creat output buffer.");
        exit(EXIT_FAILURE);
    }
    for (int i = 2; i < argc; i++) {
        if ((fs = fopen(argv[i], "rb")) == NULL) {
            fprintf(stderr, "Failed to open %s.", argv[i]);
            exit(EXIT_FAILURE);
        }
        if (setvbuf(fs, NULL, _IOFBF, BUFSIZE)) {
            fprintf(stderr, "Failed to creat input buffer.");
            exit(EXIT_FAILURE);
        }
        append(fa, fs);
        if (ferror(fs)) {
            fprintf(stderr, "Failed to read %s.", argv[i]);
        }
        if (ferror(fa)) {
            fprintf(stderr, "Failed to write %s.", argv[1]);
        }
        fclose(fs);
        printf("File %s appended.\n", argv[i]);
    }
    return 0;
}

void append(FILE *dest_file, FILE *source_file) {
    size_t bytes;
    static char temp[BUFSIZE];

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source_file)) > 0){
        fwrite(temp, sizeof(char), bytes, dest_file);
    }
}
