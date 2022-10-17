#include <stdio.h>
#include "pe12-2a.h"

int main(void){
    int mode;
    double distance;
    double fuel_consume;

    printf("Enter 0 for metric mode, 1 for US mode: ");
    set_mode(&mode);
    while (mode >= 0) {
        get_info(mode, &distance, &fuel_consume);
        show_info(mode, distance, fuel_consume);
        printf("Enter 0 for metric mode, 1 for US mode ");
        printf("(-1 to quit): ");
        set_mode(&mode);
    }
    printf("Done!\n");
    return 0;
}
