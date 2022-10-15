#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 1024
#define PRT_ORIG "-p"
#define PRT_UPPER "-u"
#define PRT_LOWER "-l"

char * s_gets(char * Buffer, int maxCount);
void usr_input(char *str, int max_count);
void operate(char **command, char *text);
int main(int argc, char *argv[]){
    if (argc > 2){
        puts("Too many parameters were entered.");
        return 0;
    }
    char text[MAX + 1];
    usr_input(text, MAX);
    operate(argv, text);
    return 0;
}

void usr_input(char *str, int max_count){
    puts("Please enter the text (EOF or blank line to end your entry):");
    int ch, is_blank_line, ct = 0;
    while ((ch = getchar()) != EOF || ct < max_count) {
        if (ch == '\n') {
            if ((is_blank_line = getchar()) == '\n')
                break;
            str[ct++] = (char)ch;
            str[ct++] = (char)is_blank_line;
        } else{
            str[ct++] = (char)ch;
        }
    }
    str[ct] = '\0';
}

void operate(char **command, char *text){
    char *start = text;
    if (command[1] == NULL || !strcmp(PRT_ORIG, command[1])){
        ;
    } else if (!strcmp(PRT_UPPER, command[1])){
        while (*text){
            if (isalpha(*text)){
                *text = toupper(*text);
                text++;
                continue;
            }
            text++;
        }
    } else if (!strcmp(PRT_LOWER, command[1])) {
        while (*text){
            if (isalpha(*text)){
                *text = toupper(*text);
                text++;
                continue;
            }
            text++;
        }
    } else{
        puts("ERROR!");
        return;
    }
    puts(start);
}

/*改进版本
    原来toupper()等遇到非字母会返回原来值的
*/
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int ch;
    int flag = 1;
    char mode = 'p';

    if (argc > 2)
    {
        printf("Usage: %s [-p | -u | -l]\n", argv[0]);
        flag = 0;
    }
    else if (argc == 2)
    {
        if (argv[1][0] != '-')
        {
            printf("Usage: %s [-p | -u | -l]\n", argv[0]);
            flag = 0;
        }
        else
        {
            switch (argv[1][1])
            {
                case 'p':
                case 'u':
                case 'l':
                {
                    mode = argv[1][1];
                    break;
                }
                default:
                {
                    printf("The argument isn't p, u or l, the program start to run with -p way.\n");
                }
            }
        }
    }
    if (flag)
    {
        printf("Please enter some characters (EOF to quit):\n");
        while ((ch = getchar()) != EOF)
        {
            switch (mode)
            {
                case 'p':
                {
                    putchar(ch);
                    break;
                }
                case 'u':
                {
                    putchar(toupper(ch));
                    break;
                }
                case 'l':
                {
                    putchar(tolower(ch));
                    break;
                }
            }
        }
    }
    printf("Done.\n");

    return 0;
}
