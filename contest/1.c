#include <stdio.h>
int main(void)
{
    int times;
    int nums[3];
    int sum;
    int k;
    scanf("%d", &times);
    char out[times];
    for (k = 0; k < times; k++) {
        for (int i = 0; i < 3; i++) {
            scanf("%d", &nums[i]);
        }
        for (int i = 0; i < 3; i++) {
            sum = nums[i];
            if (sum == nums[1] + nums[2] || sum == nums[0] + nums[2] || sum == nums[0] + nums[1]) {
                out[k] = 1;
                break;
            }
            else
                out[k] = 0;
        }
    }
    for (int i = 0; i < times; i++) {
        if (out[i])
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
