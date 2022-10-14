/*E: 慑出憌大

沋目描述

憈憉一个程序，慑入a、b、c三个值，慑出其中憌大值。

慑入

一行数憋，分慔为a b c

慑出

a b c其中憌大的数

样例慑入

10 20 30

样例慑出

30*/
#include <stdio.h>

int max(int a, int b);
int main(void){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d", max(max(a, b), c));
    return 0;
}

int max(int a, int b){
    return a > b ? a : b;
}
