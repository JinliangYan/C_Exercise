#include <stdio.h>

int main(void) {
    FILE *f = fopen("t1", "a+");
    long pos1 = ftell(f);
    printf("pos1 = %ld\n", pos1);
    putc(getchar(), f);
    getchar();
    long pos2 = ftell(f);
    printf("pos2 = %ld\n", pos2);
    rewind(f);
    long pos3 = ftell(f);
    printf("pos3 = %ld\n", pos3);
    putc(getchar(), f);
    getchar();
    long pos4 = ftell(f);
    printf("pos4 = %ld\n", pos4);
    return 0;
}
