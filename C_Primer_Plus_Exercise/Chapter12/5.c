#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define NUM 1000

int main(void){
    int rand_num[10] = {0};
    int num;
    srand(time(NULL));
    for (int i = 0; i < NUM; i++) {
        num = rand() % 10 + 1;
        switch (num) {
            case 1:
                rand_num[0]++;
                break;
            case 2:
                rand_num[1]++;
                break;
            case 3:
                rand_num[2]++;
                break;
            case 4:
                rand_num[3]++;
                break;
            case 5:
                rand_num[4]++;
                break;
            case 6:
                rand_num[5]++;
                break;
            case 7:
                rand_num[6]++;
                break;
            case 8:
                rand_num[7]++;
                break;
            case 9:
                rand_num[8]++;
                break;
            default:
                rand_num[9]++;
        }
    }
    for (int j = 0; j < 10; j++) {
        printf("%-1d : %d times\n", j + 1, rand_num[j]);
    }
    return 0;
}
