//text文本文件
/*
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0
0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define FIL_NAM "text"

void rm_distortion(int rows, int cols, int num[rows][cols]);
int main(void) {
    FILE *text;
    int ch, rows = 0, cols;
    int *pt;
    int ct = 0;
    if ((text = fopen(FIL_NAM, "r")) == NULL) {
        fprintf(stderr, "Failed to open %s!", FIL_NAM);
        exit(EXIT_FAILURE);
    }

    /*计算行列数*/
    while ((ch = getc(text)) != EOF) {
        if (isdigit(ch)) {
            ct++;
        } else if (ch == '\n') {
            rows++;
        }
    }
    rows++;
    cols = ct / rows;
    int num[rows][cols];
    pt = num[0];
    /*文件指针回到开头*/
    rewind(text);

    /*文件中的数字字符。
     * 转换为数字↓*/
    while ((ch = getc(text)) != EOF) {
        if (isdigit(ch)) {
            *pt++ = ch - '0';
        }
    }

    if (fclose(text) == EOF) {
        fprintf(stderr, "Can't close %s.", FIL_NAM);
        exit(EXIT_FAILURE);
    }

    /*消除失真*/
    rm_distortion(rows, cols, num);

    /*打印输出图像↓*/
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            switch (num[i][j]) {
                case 0:
                    putchar(' ');
                    break;
                case 1:
                    putchar('.');
                    break;
                case 3:
                    putchar('_');
                    break;
                case 4:
                    putchar('=');
                    break;
                case 5:
                    putchar('*');
                    break;
                case 6:
                    putchar('%');
                    break;
                case 7:
                    putchar('$');
                    break;
                case 8:
                    putchar('@');
                    break;
                default:
                    putchar('#');
            }
        }
        putchar('\n');
    }
    return 0;
}

void rm_distortion(int rows, int cols, int num[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (abs(num[i][j] - num[i - 1][j]) > 1 && abs(num[i][j] - num[i][j - 1]) > 1 && abs(num[i][j] - num[i][j + 1]) > 1 && abs(num[i][j] - num[i + 1][j]) > 1) {
                num[i][j] = (int)((double)(num[i - 1][j] + num[i][j - 1] + num[i][j + 1] + num[i + 1][j]) / 4 + 0.5);
            }
        }
    }
}
