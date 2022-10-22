#include <stdio.h>
#include <stdlib.h>
#define MAX 41

static long max_pos;
char * s_gets(char * Buffer, int maxCount);
int main(void) {
    FILE *f;
    char file_name[MAX];
    int ch;
    long pos;
    printf("Please enter the file name: ");
    s_gets(file_name, MAX);
    if ((f = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "Failed to open %s!", file_name);
        exit(EXIT_FAILURE);
    }
    /*计算最大文件位置↓*/
    fseek(f, 0L, SEEK_END);
    max_pos = ftell(f);
    rewind(f);

    printf("Please enter a file position: ");
    /*处理错误输入*/
    while (scanf("%ld", &pos) != 1) {
        printf("Please enter a integer: ");
        scanf("%*s");
    }
    while (pos >= 0) {
        while (pos > max_pos) {
            printf("Out of range, please enter again: ");
            while (scanf("%ld", &pos) != 1) {
                printf("Please enter a integer: ");
                scanf("%*s");
            }
        }
        fseek(f, pos, SEEK_SET);
        while ((ch = getc(f)) != EOF && ch != '\n') {
            putchar(ch);
        }
        putchar('\n');
        printf("Please enter a file position(< 0 to quit): ");
        while (scanf("%ld", &pos) != 1) {
            printf("Please enter a integer: ");
            scanf("%*s");
        }
    }
    puts("Bye.");

    return 0;
}

char * s_gets(char * Buffer, int maxCount){
    char * ret_value;
    ret_value = fgets(Buffer, maxCount, stdin);
    if (ret_value){
        //替换'\n'为'\0'
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
