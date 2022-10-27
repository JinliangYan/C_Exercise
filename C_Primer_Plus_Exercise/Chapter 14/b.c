#include <stdio.h>
#include <math.h>
void transform(double source[], double target[], int size, double (*fp)(double));
int main(void) {
    double source[5] = {1,2,3,4,5};
    double target[5];
    transform(source, target, 5, sin);
    return 0;
}

void transform(double source[], double target[], int size, double (*fp)(double)) {
    for (int i = 0; i < size; i++) {
        target[i] = (*fp)(source[i]);
    }
}
