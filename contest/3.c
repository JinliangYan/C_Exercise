#include <stdio.h>
int mgcd(int a,int b);
int main(void){
    int times, n;
    int max = -1;
    int flag;
    scanf("%d", &times);
    for (int i = 0; i < times; i++) {
        scanf("%d", &n);
        int nums[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &nums[j]);
        }
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (mgcd(nums[j], nums[k]) == 1){
                    max = nums[j] + nums[k] > max ? nums[j] + nums[k] : max;
                }
                if (mgcd(nums[j], nums[j]) == 1)
                    max = nums[j] + nums[j] > max ? nums[j] + nums[j] : max;
            }
            if (j == n)
                break;
        }
        printf("%d\n",max);
        max = -1;
    }
    return 0;
}
//返回值为1则互质
int mgcd(int a,int b)
{
    int t;
    if(a<b)
    {
        t=a;a=b;b=t;
    }
    while(a%b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return b;
}
