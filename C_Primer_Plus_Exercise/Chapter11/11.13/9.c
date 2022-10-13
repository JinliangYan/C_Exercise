#include <stdio.h>
#define STLEN 50

void str_rollback(char * str);
char * s_gets(char * Buffer, int maxCount);

int main(void)
{
    char str[STLEN];
    puts("Please enter a string, I will roll back it(EOF to exit):");
    while (s_gets(str, STLEN))
    {
        str_rollback(str);
        puts("Done!");
        puts(str);
        puts("You can enter another string(EOF to exit):");
    }
    return 0;
}

void str_rollback(char * str)
{
    char *end = str, *start = str;
    char tmp;
    while (*end)
        end++;
    end--;
    do {
        tmp = *start;
        *start = *end;
        *end = tmp;
        end--, start++;
    } while ((end - start) > 0);
}

char * s_gets(char * Buffer, int maxCount){
    char * ret_value;
    ret_value = fgets(Buffer, maxCount, stdin);
    if (ret_value){
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
