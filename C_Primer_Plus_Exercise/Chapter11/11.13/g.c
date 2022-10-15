#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int my_atoi(char str[]);
int main(void){
    int a = my_atoi("-000001281.8");
    printf("%d", a);
    return 0;
}

int my_atoi(char str[]){
    int integer = 0, point_num = 0, i = 0;
    int tmp;
    char * str_start = str;
    bool is_negative = *str == '-' ? true : false;
    if (is_negative)
        str_start = ++str;
    /*跳过前面所有0，
     * 如果直到字符串结尾，则返回0↓*/
    while (*str == '0'){
        if (*str == '\0')
            return 0;
        str++;
    }
/*检查是否有非数字，
 * 小数点只能有一个,
 * 若不满足，返回0↓*/
    while (*str){
        if (*str == '.'){
            str++;
            point_num++;
        }
        else if (!isdigit(*str)|| point_num > 1)
            return 0;
        else
            str++;
    }
    str--;
/*如果有小数点，
 * 则把指针前进至小数点前一位，
 * 便于后面计算整数*/
    if (point_num)
        while (*str-- != '.')
            ;

    while (str >= str_start) {
        tmp = *str-- - '0';
        integer += tmp * (int)pow(10, i++);
    }
    if (is_negative)
        integer = -integer;
    return integer;
}
