//选择排序初尝试
#include <stdio.h>
#include <string.h>
#define LIM 5
#define SIZE 20

char * s_gets(char Buffer[], int maxCount);
void ststr(char * str[], int num);
int main(void){
    char input[LIM][SIZE];
    char * ptstr[LIM];
    int ct = 0;

    printf("请输入 %d 个字符串，我将为它们排序:\n", LIM);

    while (ct < LIM && s_gets(input[ct], SIZE) != NULL && input[ct][0] != '\0'){
        ptstr[ct] = input[ct];
        ct++;
    }

    ststr(ptstr, ct);

    for (int i = 0; i < ct; i++) {
        puts(ptstr[i]);
    }

    return 0;
}

void ststr(char * str[], int num){
    int top, seek;
    char * temp;
    for (top = 0; top < num - 1; top++) {
        for (seek = top + 1; seek < num; seek++) {
            if (strcmp(str[top], str[seek]) > 0){
                temp = str[top];
                str[top] = str[seek];
                str[seek] = temp;
            }
        }
    }
}

char * s_gets(char Buffer[], int maxCount){
    char * ret_value;
    int i = 0;
    ret_value = fgets(Buffer, maxCount, stdin);
    if (ret_value){
        while (Buffer[i] != '\n' && Buffer[i] != '\0') {
            i++;
        }
        if (Buffer[i] == '\n')
            Buffer[i] = '\0';
        else{
            while (getchar() != '\n');
        }
    }
    return ret_value;
}
