#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    double x, y;
    char * end_ptr;
    x = strtof(argv[1],&end_ptr);
    y = strtof(argv[2],&end_ptr);
    printf("%.4f", pow(x, y));
    return 0;
}
