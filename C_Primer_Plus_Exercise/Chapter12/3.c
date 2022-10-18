#include <stdio.h>

void test();
int main(void){
    int status, choose;
    printf("Enter 1 to call the function, 0 to quit: ");

    while ((status = scanf("%d", &choose)) != 1 || (choose != 1 && choose != 0)){
        scanf("%*s");
        printf("Please enter 1 or 0: ");
    }
    while (choose){
        test();
        printf("Enter 1 to call the function, 0 to quit: ");
        while ((status = scanf("%d", &choose)) != 1 || (choose != 1 && choose != 0)){
            scanf("%*s");
            printf("Please enter 1 or 0: ");
        }
    }
    return 0;
}

void test(){
    static int count = 0;
    count++;
    printf("Function is called %d time(s).\n", count);
}
