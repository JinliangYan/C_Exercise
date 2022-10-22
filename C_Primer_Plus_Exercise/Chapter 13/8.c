#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_info(char seek, char *file_name);
int main(int argc, char *argv[]) {
    if (argc < 2 || strlen(argv[1]) != 1) {
        fprintf(stderr, "Usage: %s a_character [file]", argv[0]);
        exit(EXIT_FAILURE);
    }
    int ch, ct = 0;
    char seek = argv[1][0];
    int status;
    /*0表示程序从标准输入读取，
     * 1表示从文件读取↓*/
    status = argc == 2 ? 0 : 1;
    if (status) {
        for (int i = 2; i < argc; i++) {
            show_info(seek, argv[i]);
        }
    } else {
        ch = getchar();
        while (ch != EOF) {
            if (ch == seek) {
                ct++;
            }
            ch = getc(stdin);
        }
        printf("There are %d %c in your entry.\n", ct, seek);
    }
}

void show_info(char seek, char *file_name) {
    FILE *fp;
    int ch;
    int ct = 0;
    if ((fp = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "Failed to open %s", file_name);
        exit(EXIT_FAILURE);
    }
    ch = getc(fp);
    while (ch != EOF) {
        if (ch == seek) {
            ct++;
        }
        ch = getc(fp);
    }
    printf("There are %d %c in %s.\n", ct, seek, file_name);
}
