/*从输入中获取n个字符（包括空白，制表符，换行符），把结果储存在一个数组里，它的地址被传递作为一个参数*/

#include <stdio.h>
#include <string.h>
#define STLEN 15
char * get_str(char str[], int n);

int main(void){
    char str[STLEN + 1];
    get_str(str, STLEN);
    fputs(str, stdout);
    printf("\n\n%llu", strlen(str));
    return 0;
}

char * get_str(char str[], int n){
    int ch;
    char * ret_value = str;
    for (int i = 0; i < n && (ch = getchar()) != ' ' && ch != '\t' && ch != '\n' && ch != EOF; i++) {
        *str++ = (char)ch;
    }
    *str = '\0';
    return ret_value;
}
