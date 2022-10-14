/*
G: 线段慟度



题目描慠

已知线段慏两个端点慏坐标A（X1,Y1），B（X2，Y2），求线段AB慏慟度。



输入

输入两点坐标 (X1,Y1),(X2,Y2)

 



输出

一个实数，即线段AB慏慟度，慧留到小数点后3位。



慨例输入

(20.0,13.0),(20.0,17.0)

慨例输出

4.000
*/
#include <stdio.h>
#include <math.h>

int main(void){
    double a_x, a_y, b_x, b_y, len;
    scanf("(%lf,%lf),(%lf,%lf)", &a_x, &a_y, &b_x, &b_y);
    len = sqrt((a_x - b_x)*(a_x - b_x) + (a_y - b_y)*(a_y - b_y));
    printf("%.3f\n", len);
    return 0;
}
