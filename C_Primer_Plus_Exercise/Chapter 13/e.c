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
#define ROWS 20
#define COLS 30
#define LEVELS 10
const char trans[LEVELS + 1] = " .':~*=&%#"; //存储需要转换的字符;
char * s_gets(char * Buffer, int maxCount);
int clean_distortion(int (*num)[COLS], int x, int y);
void change(int (*num)[COLS]);
int main(void) {
    FILE *f;
    int num[ROWS][COLS];
    char file_name[FILENAME_MAX];
    printf("Please enter the file name: ");
    s_gets(file_name, FILENAME_MAX);
    if ((f = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "Failed to open %s!", file_name);
        exit(EXIT_FAILURE);
    }
    /*将文本转换成数字↓*/
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(f, "%d", &num[i][j]);
        }
    }
    if (ferror(f)) {
        fprintf(stderr, "Error! Exiting...\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            num[i][j] = clean_distortion(num, i, j);
        }
    }

    change(num);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            putchar(num[i][j]);
        }
        putchar('\n');
    }

    if (fclose(f) == EOF) {
        fprintf(stderr, "Can't close %s.", file_name);
        exit(EXIT_FAILURE);
    }

    return 0;
}

int clean_distortion(int (*num)[COLS], int x, int y) {
    int d[4][2] = {{1,0},
                   {0,1},
                   {-1,0},
                   {0,-1}};
    int sum = 0, cnt = 0;
    int status = cnt;
    int dx, dy;
    for (int i = 0; i < 4; i++) {
        dx = x + d[i][0];
        dy = y + d[i][1];
        if (dx < 0 || dx > ROWS - 1 || dy < 0 || dy > COLS - 1) continue;
        status++;
        if (abs(num[dx][dy] - num[x][y]) > 1) {
            sum += num[dx][dy];
            cnt++;
        }
    }
    if (status != cnt)
        return num[x][y];
    return (int)((double)sum / cnt + 0.5);
}

void change(int (*num)[COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            num[i][j] = (int)trans[num[i][j]];
        }
    }
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
