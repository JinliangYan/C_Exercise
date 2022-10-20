#include <stdio.h>
#include <stdlib.h>
#define SLEN  260

int main(void) {
    int ch;
    FILE *fp;
    char file_name[SLEN];
    char BUFFER[3000];
    unsigned long count = 0;
    printf("Please enter the file name: ");
    scanf("%s", file_name);
    if ((fp = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "Failed to open file.");
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters.\n", file_name, count);
    return 0;
}
