#include <stdio.h>
#define STLEN 50

char * string_in(char * s1, char * s2);
char * s_gets(char * Buffer, int maxCount);
int main(void)
{
    char str1[STLEN], str2[STLEN];
    char * find_it;
    puts("Please enter the string you want to find(EOF to exit):");
    while (s_gets(str2, STLEN) != NULL)
    {
        puts("Then, please enter source string:");
        s_gets(str1, STLEN);
        find_it = string_in(str1, str2);
        puts("Done!");
        puts("String:");
        puts(str1);
        if (find_it)
            printf("\"%s\" is exist in the string.\n", str2);
        else
            printf("\"%s\" is not exist in the string.\n", str2);
        puts("---------------------------------------------");
        puts("You can find string again,please enterPlease enter the string you want to find(EOF to exit):");
    }
    return 0;
}

char * string_in(char * s1, char * s2)
{
    char * ret_val = NULL;
    char * s2_orig = s2;
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1++ == *s2++)
        {
            for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
            {
                if (s1[i] != s2[i])
                    break;
                ret_val = s1 - 1;
            }
        }
        s2 = s2_orig;
    }
    return ret_val;
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
