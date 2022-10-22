#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 41
#define FIL_NAME "Words.txt"

int main(void) {
    FILE *fp;
    char word[MAX];
    int ct = 0;
    int ch;
    if ((fp = fopen(FIL_NAME, "r+")) == NULL) {
        fprintf(stderr, "failed to open %s.", FIL_NAME);
        exit(EXIT_FAILURE);
    }

    /*根据换行符数量，
     * 得出现在的单词数↓*/
    while ((ch = getc(fp)) != EOF) {
        if (ch == '\n') {
            ct++;
        }
    }

    printf("Enter words to add to the file; press the # key at the beginning of a line to terminate.\n");
    while (scanf("%40s", word) == 1 && word[0] != '#') {
        fprintf(fp, "[%d]%s\n", ct + 1, word);
        ct++;
    }

    /*输入写入数据*/
    rewind(fp);
    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
    }

    if (fclose(fp) == EOF) {
        fprintf(stderr, "Failed to close %s!", FIL_NAME);
        exit(EXIT_FAILURE);
    }
}
