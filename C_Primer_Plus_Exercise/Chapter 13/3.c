#include <stdio.h>
#include <ctype.h>

int main(void){
    FILE *fp1;
    char file_name[81];
    int ch;
    printf("Please enter the file name: ");
    scanf("%80s", file_name);
    if ((fp1 = fopen(file_name, "r+")) == NULL) {
        fprintf(stderr, "Failed to open %s.", file_name);
    }
    while ((ch = getc(fp1)) != EOF) {
        fseek(fp1, -1L, SEEK_CUR);
        putc(toupper(ch), fp1);
        fseek(fp1, 0L, SEEK_CUR);
    }
    fclose(fp1);
    return 0;
}
