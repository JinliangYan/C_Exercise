#include <stdio.h>
void range(int nums[], int n);
int main(void){
    int times;
    int n;
    int flag;
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        scanf("%d", &n);
        int nums[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &nums[j]);
        }
        range(nums, n);
        for (int j = 1; j < n; j++) {
            if (nums[j] - nums[j - 1])
                flag = 0;
        }
        if (flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}

void range(int nums[], int n){
    int tmp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] > nums[j]){
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
        }
    }
}
