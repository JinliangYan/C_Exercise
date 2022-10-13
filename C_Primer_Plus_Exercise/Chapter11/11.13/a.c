#include <stdio.h>
#include <ctype.h>
#define STLEN 50

char * s_gets(char * Buffer, int maxCount);
void del_str_space(char * str);
int main(void)
{
    char str[STLEN];
    puts("Please enter a string,I will delete all space(empty line or EOF to exit):");
    while (s_gets(str, STLEN))
    {
        del_str_space(str);
        puts("Done!");
        puts(str);
        puts("--------------------------------------------------------------------------------");
        puts("Please enter a string,I will delete all space(empty line or EOF to exit):");
    }
    puts("Bye");
    return 0;
}

void del_str_space(char * str)
{
    char * pstr = str;
    while (*pstr)
    {
        if (! isspace(*pstr))
            *str++ = *pstr++;
        else
            pstr++;
    }
    *str = '\0';
}
//↓可改进如上↑
/*
void del_str_space(char * str)
{
    char tmp[STLEN];
    char * ptmp = tmp;
    char * pstr = str;
    while (*pstr)
    {
        if (! isspace(*pstr))
            *ptmp++ = *pstr++;
        else
            pstr++;
    }
    ptmp = tmp;
    while (*ptmp)
    {
        *str++ = *ptmp++;
    }
    *str = '\0';
}
*/

char * s_gets(char * Buffer, int maxCount)
{
    char * ret_value;
    ret_value = fgets(Buffer, maxCount, stdin);
    if (Buffer[0] == '\n')
        ret_value = NULL;
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
