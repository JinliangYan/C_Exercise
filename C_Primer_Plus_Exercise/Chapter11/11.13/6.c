#include <stdio.h>
#define STLEN 100

int is_within(char ch, char *str);
char * s_gets(char * Buffer, int maxCount);
int main(void){
    char str[STLEN];
    char search_ch;
    puts("Please enter a character(EOF to exit):");
    while ((search_ch = getchar()) != EOF){
        while (getchar() != '\n')
            continue;
        printf("Please enter a string:");
        s_gets(str, STLEN);
        puts("String:");
        puts(str);
        if (is_within(search_ch, str) == 0)
            printf("Not exist %c in the string.\n", search_ch);
        else
            printf("Exist %c in the string.\n", search_ch);
        puts("You can enter a string(EOF to exit):");
    }
    return 0;
}

int is_within(char ch, char *str)
{
    while (*str != '\0')
    {
        if (*str != ch)
        {
            ++str;
        }
        else
        {
            return 1;
        }
    }
    return 0;
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
