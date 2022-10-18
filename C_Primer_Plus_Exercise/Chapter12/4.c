#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUM 100

int main(void){
    int rand_num[NUM];
    time_t time1 = time(&time1);
    srand((unsigned int )time1);
    for (int i = 0; i < NUM; i++) {
        rand_num[i] = rand() % 10 + 1;
    }

    int tmp;
    for (int i = 0; i < NUM - 1; i++) {
        for (int j = i + 1; j < NUM; j++) {
            if (rand_num[i] < rand_num[j]){
                tmp = rand_num[i];
                rand_num[i] = rand_num[j];
                rand_num[j] = tmp;
            }
        }
    }

    for (int i = 0; i < NUM; i++) {
        printf("%d ", rand_num[i]);
    }
    return 0;
}
