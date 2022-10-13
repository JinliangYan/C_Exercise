#include <stdio.h>
#include <string.h>
#define STLEN 50

char * mystrncpy(char * s1, char * s2, int count);
char * s_gets(char * Buffer, int maxCount);
int main(void){
    char s1[STLEN], s2[STLEN];
    int count, flag;
    puts("Please enter a string you want me to copy(EOF to exit)：");
    while (s_gets(s2, STLEN) != NULL)
    {
        printf("Then,enter how much character you want to copy:");
        flag = scanf("%d", &count);
        while (getchar() != '\n')
            ;
        while (flag != 1)
        {
            printf("Error,please enter one integer again:");
            flag = scanf("%d", &count);
            while (getchar() != '\n')
                ;
        }
        mystrncpy(s1, s2, count);
        printf("String you copied to s1:\n%s\n", s1);
        puts("-----------------------------------------");
        puts("You can copy again:");
    }
    puts("bye!");
    return 0;
}

char * mystrncpy(char * s1, char * s2, int count)
{
    while (*s2 != 0 && count > 0)
    {
        *s1++ = *s2++;
        count--;
    }
    *s1 = '\0';
    return s1;
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
