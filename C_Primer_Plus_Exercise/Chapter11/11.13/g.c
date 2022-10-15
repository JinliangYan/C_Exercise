#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int my_atoi(char str[]);
int main(void){
    int a = my_atoi("3");
    printf("%d", a);
    return 0;
}

int my_atoi(char str[]){
    int integer = 0;
    int ct = 0;
    int point_num = 0;
    bool is_negative = *str == '-' ? true : false;
    /*跳过前面所有0，
     * 如果直到字符串结尾，则返回0↓*/
    while (*str++ == '0'){
        if (*str == '\0')
            return 0;
    }
    str--;
/*检查是否有非数字，
 * 小数点只能有一个,
 * 并且记录数字个数↓*/
    while (str[ct]){
        if (str[ct] == '.'){
            str++; //           NUGNUGUNOKNFoak' sdgoisdp 我日 bug原因 在这！！！！！！！！！！！！！！！！！！！！！！
            point_num++;
        }
        else if (!isdigit(str[ct])|| point_num > 1){
            return 0;
        }
        else{
            if (point_num < 1)
                ++ct;
        }
    }
    /*前面为了跳过小数点，指针+1，
     * 现在-1复位*/
    --str;
    while (ct > 0){
        integer += (str[ct - 1] - '0') * (int)pow(10, ct);
        ct--;
    }
    if (is_negative)
        integer = -integer;
    return integer;
}
