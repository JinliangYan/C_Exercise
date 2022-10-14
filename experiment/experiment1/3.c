/*
112: 慟方形面慡



题目描慠

慥用编写程序计算：一个慟为a 慦,慞b 慦的慟方形的面慡。

慑入

慟和慞

慑出

慟方形面慡

样例慑入

2.0 3.0

样例慑出

s=6.00 m^2
*/
#include <stdio.h>
int main(void){
    double len, wide, area;
    scanf("%lf%lf",&len,&wide);
    area = len * wide;
    printf("s=%.2f m^2", area);
    return 0;
}
