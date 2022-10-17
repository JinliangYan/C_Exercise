#include <stdio.h>
#include "pe12-2a.h"

static int mode;
static double distance;
static double fuel_consume;

void set_mode(int mo) {
    int orig_mode = mode;
    if(mo != US && mo != METRIC){
        mode = orig_mode;
        printf("Invalid mode specified. Mode %s used.\n", mode == US ? "1(US)" : "0(metric)");
    } else {
        mode = mo;
    }
}

void get_info() {
    printf("Enter the distance traveled in kilometers: ");
    scanf("%lf", &distance);
    printf("Enter fuel consumption in %s: ", mode == US ? "gallons" : "liters");
    scanf("%lf", &fuel_consume);
}

void show_info(){
    double consume_per;
    consume_per = distance / fuel_consume;
    printf("Fuel consumption is %.2f miles per %s.\n", consume_per, mode == US ? "gallons" : "liters");
}
