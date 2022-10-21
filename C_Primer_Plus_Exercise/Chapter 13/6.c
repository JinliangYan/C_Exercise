#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 81

char * s_gets(char * Buffer, int maxCount);
int main(void) {
    char in_name[LEN], out_name[LEN];
    int ch;
    size_t ct = 0;
    FILE *in, *out;
    printf("Enter the file name and I will compress it: ");
    s_gets(in_name, LEN);
    if ((in = fopen(in_name, "r")) == NULL) {
        fprintf(stderr, "Failed to open %s", in_name);
        exit(EXIT_FAILURE);
    }
    strncpy(out_name, in_name,LEN - 5);
    out_name[LEN - 5] = '\0';
    strcat(out_name,".red");
    if ((out = fopen(out_name, "w")) == NULL) {
        fprintf(stderr, "Failed to creat %s", out_name);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(in)) != EOF) {
        if (ct % 3 == 0) {
            putc(ch, out);
        }
        ct++;
    }
    return 0;
}

char * s_gets(char * Buffer, int maxCount){
    char * ret_value;
    ret_value = fgets(Buffer, maxCount, stdin);
    if (ret_value){
        while (*Buffer != '\n' && *Buffer != '\0')
            Buffer++;
        if (*Buffer == '\n')
            *Buffer = '\0';
        else{
            while (getchar() != '\n');
        }
    }
    return ret_value;
}
