/*J: 求多项式



题目描述

慿慾多项式f(x) = ax^3 + bx^2 + cx + d 和给定的 x, a, b, c, d, 计算f(x)的值。



慑慙

慑慙仅一行，包含5个实数，分别是x，及系数a、b、c、d的值，每个数都是绝慿值不超过100的双精度浮点数。数与数之憀以一个空格分开。



慑出

慑出一个实数，即f(x)的值，慧留慽小数点后5位。



样例慑慙

5.0 0.0 1.0 2.0 1.0

样例慑出

36.00000*/
#include <stdio.h>
#include <math.h>
int main(void){
    double x, a, b, c, d;
    scanf("%lf%lf%lf%lf%lf", &x, &a, &b, &c, &d);
    printf("%.5f", a * pow(x, 3) + b * pow(x, 2) + c * x + d);
    return 0;
}
