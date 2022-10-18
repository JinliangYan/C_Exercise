#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void){
    int rand_num[10];
    time_t time1 = time(&time1);
    srand((unsigned int )time1);
    for (int i = 0; i < 10; i++) {
        rand_num[i] = rand() % 10 + 1;
    }

    int tmp;
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (rand_num[i] < rand_num[j]){
                tmp = rand_num[i];
                rand_num[i] = rand_num[j];
                rand_num[j] = tmp;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", rand_num[i]);
    }
    return 0;
}
