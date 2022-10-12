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
    char ch;
    char * ret_value = str;
    for (int i = 0; i < n; i++) {
        *str++ = getchar();
    }
    *str = '\0';
    return ret_value;
}
