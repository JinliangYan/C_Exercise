#include <stdio.h>
#define STLEN 100

char * mystrchr(char *str, char ch);
char * s_gets(char * Buffer, int maxCount);
int main(void){
    char str[STLEN];
    char search_ch;
    puts("Please enter a string(EOF to exit):");
    while (s_gets(str, STLEN) != NULL){
        printf("Please enter a char you want to search from the string(EOF to exit):");
        search_ch = getchar();
        while (getchar() != '\n')
            continue;
        puts("String:");
        puts(str);
        if (mystrchr(str, search_ch) == NULL)
            printf("Not exist %c in the string.\n", search_ch);
        else
            printf("Exist %c in the string.\n", search_ch);
        puts("You can enter a string(EOF to exit):");
    }
    return 0;
}

char *mystrchr(char *str, char ch)
{
    while (*str != '\0')
    {
        if (*str != ch)
        {
            ++str;
        }
        else
        {
            return str;
        }
    }
    return NULL;
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
