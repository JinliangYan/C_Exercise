#include <stdio.h>
#include <string.h>
#define LIM 2
#define STLEN 100
#define EXIT 5
#define STARS "********************************************************************"

int usr_input(char * strings[]);
int menu();
void prt_strings(char strings[][STLEN], int num);
void a_ord(char * strings[], int num);
void len_ord(char * strings[], int num);
void fist_word_len_ord(char * strings[], int num);
char * s_gets(char * Buffer, int maxCount);
int main(void)
{
    int choose, num;
    char usr_strings[LIM + 1][STLEN];
    char *strings[LIM + 1];
    for (int i = 0; i < LIM; i++)
    {
        strings[i] = usr_strings[i];
    }
    num = usr_input(strings);
    while ((choose = menu()) != EXIT)
    {
        switch (choose)
        {
            case 1:
                prt_strings(usr_strings, num);
                break;
            case 2:
                a_ord(strings, num);
                break;
            case 3:
                len_ord(strings, num);
                break;
            case 4:
                fist_word_len_ord(strings, num);
            default:
                ;
        }
    }
    return 0;
}

int menu()
{
    puts(STARS);
    int choose;
    puts("1)Print a list of source strings        2)Prints the strings in order in ASCII");
    puts("3)Prints strings in increasing length   4)Prints the string in increasing order of the first word length");
    puts("5)Exit");
    while ((scanf("%d", &choose)) != 1 && choose > 0 && choose < 5)
    {
        puts("Please enter a number of the potion");
    }
    return choose;
}

int usr_input(char * strings[])
{
    puts(STARS);
    int ct = 0;
    printf("Please enter some strings,not more than %d.\n", LIM);
    while (s_gets(strings[ct], STLEN))
    {
        ct++;
        if (ct >= LIM)
            break;
    }
    puts("Entry is complete.");
    return ct;
}

void prt_strings(char strings[][STLEN], int num)
{

    puts(STARS);
    for (int i = 0; i < num; i++)
    {
        puts(strings[i]);
    }
}

void a_ord(char * strings[], int num)
{
    puts(STARS);
    char * tmp;
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i+1; j < num; j++)
        {
            if (strcmp(strings[i], strings[j]) > 0)
            {
                tmp = strings[i];
                strings[i] = strings[j];
                strings[j] = tmp;
            }
        }
    }
    for (int i = 0; i < num; i++) {
        puts(strings[i]);
    }
}

void len_ord(char * strings[], int num)
{
    char * tmp;
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i+1; j < num; j++)
        {
            if (strlen(strings[i]) > strlen(strings[j]))
            {
                tmp = strings[i];
                strings[i] = strings[j];
                strings[j] = tmp;
            }
        }
    }
    for (int i = 0; i < num; i++) {
        puts(strings[i]);
    }
}

void fist_word_len_ord(char * strings[], int num)
{
    char * tmp;
    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++) {
            if ((strchr(strings[i], ' ') - strings[i]) > (strchr(strings[j], ' ') - strings[j]))
            {
                tmp = strings[i];
                strings[i] = strings[j];
                strings[j] = tmp;
            }
        }
    }
    for (int i = 0; i < num; i++) {
        puts(strings[i]);
    }
}


char * s_gets(char Buffer[], int maxCount){
    char * ret_value;
    int i = 0;
    ret_value = fgets(Buffer, maxCount, stdin);
    if (ret_value){
        //替换'\n'为'\0'
        while (Buffer[i] != '\n' && Buffer[i] != '\0') {
            i++;
        }
        if (Buffer[i] == '\n')
            Buffer[i] = '\0';
        else{
            while (getchar() != '\n');
        }
    }
    return ret_value;
}
