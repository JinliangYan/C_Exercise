#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3 || strlen(argv[1]) != 1) {
        fprintf(stderr, "Usage: %s a_character [file]", argv[0]);
        exit(EXIT_FAILURE);
    }
    int ch, ct = 0;
    char seek = argv[1][0];
    int status;
    FILE *fp;
    /*0表示程序从标准输入读取，
     * 1表示从文件读取↓*/
    status = argc == 2 ? 0 : 1;
    if (status) {
        if ((fp = fopen(argv[2], "r")) == NULL) {
            fprintf(stderr, "Failed to open %s", argv[2]);
            exit(EXIT_FAILURE);
        }
        ch = getc(fp);
    } else {
        ch = getchar();
    }

    while (ch != EOF) {
        if (ch == seek) {
            ct++;
        }
        ch = status ? getc(fp) : getc(stdin);
    }
    printf("There are %d %c.", ct, seek);
}
