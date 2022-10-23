#include <stdio.h>
#include <string.h>

typedef struct lens {
    float foclen;
    float fstop;
    char brand[30];
} LENS;
int main(void) {
    LENS lens[10] = {
            [2] = {
            500,
            (float)2.0,
            "Remarkata"
            }
        };
    return 0;
}
