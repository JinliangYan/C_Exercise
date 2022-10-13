/*从输入中获取一个单词，忽略前空白和后空白*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define STLEN 15
void get_word(char str[]);

int main(void){
    char str[STLEN + 1];
    get_word(str);
    fputs(str, stdout);
    printf("\n\n%llu", strlen(str));
    return 0;
}

void get_word(char str[]){
    int ch;
    int i = 0;
    while (isspace(ch = getchar()))
        ;
    while (!isspace(ch)){
        str[i] = ch;
        ch = getchar();
        i++;
    }
    str[i] = '\0';
}
