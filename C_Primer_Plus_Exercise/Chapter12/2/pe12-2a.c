#include <stdio.h>
#include "pe12-2a.h"

void set_mode(int *mode) {
    int orig_mode = *mode;
    scanf("%d", mode);
    if (*mode == -1)
        return;
    if(*mode != US && *mode != METRIC){
        *mode = orig_mode;
        printf("Invalid mode specified. Mode %s used.\n", *mode == US ? "1(US)" : "0(metric)");
    }
}

void get_info(int mode, double *distance, double *fuel_consume) {
    printf("Enter the distance traveled in kilometers: ");
    scanf("%lf", distance);
    printf("Enter fuel consumption in %s: ", mode == US ? "gallons" : "liters");
    scanf("%lf", fuel_consume);
}

void show_info(int mode, double distance, double fuel_consume){
    double consume_per;
    consume_per = distance / fuel_consume;
    printf("Fuel consumption is %.2f miles per %s.\n", consume_per, mode == US ? "gallons" : "liters");
}
