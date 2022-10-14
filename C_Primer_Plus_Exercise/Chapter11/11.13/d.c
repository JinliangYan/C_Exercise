#include <stdio.h>
#include <ctype.h>
#define STLEN 100

int input(char str[]);
void count_and_prt(const char str[]);
int main(void){
    char str[STLEN];
    int input_num;
    puts("请输入文本(键入空行退出)：");
    input_num = input(str);
    while (input_num != -1){
        count_and_prt(str);
        puts("请输入文本(键入空行退出)：");
        input_num = input(str);
    }
    puts("BEY~");
    return 0;
}
/*读取用户输入
 * 返回值：越界或键入空行返回-1，成功输入返回输入字符个数
 * */
int input(char str[]){
    int count = 0;
    int ch;
    //跳过开头的非数字字母和空格
    if ((ch = getchar()) == '\n'){
        return -1;
    }
    while (!isalnum(ch));
    while (ch != EOF) {
        str[count++] = (char) ch;
        if (count > STLEN - 1) {
            puts("ERROR!");
            return -1;
        }
        ch = getchar();
    }
    str[count] = '\0';
    return count;
}

void count_and_prt(const char str[]){
    int word = 0, upper = 0, lower = 0, punct = 0, digit = 0;
    int i = -1;
    while (str[++i]) {
        if (isalnum(str[i])) {
            if (isupper(str[i])) {
                upper++;
            }
            else if (islower(str[i])) {
                lower++;
            }
            else {
                digit++;
            }
        }
        else if (ispunct(str[i])){
            punct++;
        }
        else if (isspace(str[i]))
        {
            word++;
            while (!isspace(str[i])){
                i++;
                if (str[i] == '\0'){
                    word++;
                    break;
                }
            }
            //Jump extra spaces↑
        }
    }
    printf("单词：%d    大写字母：%d    小写字母：%d     标点符号：%d     数字：%d\n", word, upper, lower, punct, digit);
}
