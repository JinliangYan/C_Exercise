#include <stdio.h>
#include <string.h>

typedef struct lens {
    float foclen;
    float fstop;
    char brand[30];
} LENS;
int main(void) {
    LENS lens[10];
    lens[2].foclen = 500;
    lens[2].fstop = (float)2.0;
    strcpy(lens[2].brand, "Remarkata");
    return 0;
}
