#include <stdio.h>
#define STLEN 15
char * get_str(char str[], int n);

int main(void){
    char str[1];
    get_str(str, STLEN);
    fputs(str, stdout);
    return 0;
}

char * get_str(char str[], int n){
    char ch;
    char * ret_value = str;
    for (int i = 0; i < n - 1; i++) {
        *str++ = getchar();
    }
    *str = '\0';
    return ret_value;
}
