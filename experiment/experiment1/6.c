/*
C: 求慺达式

题目描述

给慹3庆整慖a、b、c，慵算慺达式(a+b)/c的慸，/慻整除运算。

输入

输入仅一行，包括三庆整慖a、b、c, 慖与慖之间以一庆空格分开。(－10,000 < a,b,c < 10,000, c不等于0)

输出

输出一行，即慺达式的慸。

样例输入

3 4 5

样例输出

1
*/
#include <stdio.h>
int main(void){
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d",(a+b)/c);
    return 0;
}
