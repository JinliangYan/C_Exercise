#include <stdio.h>


double avg_all(int rows, int cols, const double arr[rows][cols]);
double avg_row(int cols, const double arr[cols]);
double max(int rows, int cols, const double arr[rows][cols]);
void show_info(int rows, int cols, const double user_put[rows][cols]);

int main(void){
    int rows, cols;
    printf("几行几列？？：");
    scanf_s("%d%d", &rows, &cols);
    double usr_put[rows][cols];
    printf("请输入：\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf_s("%lf", &usr_put[i][j]);
        }
    }

    show_info(rows, cols, usr_put);

    return 0;
}

double avg_all(int rows, int cols, const double arr[rows][cols]){
    double avg = 0;
    for (int i = 0; i < rows; i++) {
        avg += avg_row(cols, arr[i]);
    }
    return avg / rows;
}

double avg_row(int cols, const double arr[cols]){
    double avg = 0;
    for (int i = 0; i < cols; i++) {
        avg += arr[i];
    }
    avg /= cols;
    return avg;
}

double max(int rows, int cols, const double arr[rows][cols]){
    double * ptr = (double *)arr;
    double max = ptr[0];
    for (int i = 0; i < rows * cols; i++)
        max = ptr[i] > max ? ptr[i] : max;
    return max;
}

void show_info(int rows, int cols, const double user_put[rows][cols]){
    printf("每个数组的平均值：");
    for (int i = 0; i < rows; i++) {
        printf("第 %d 个：%.2f\n", i+1, avg_row(cols, user_put[i]));
    }
    printf("所有数据的平均数：%.2f\n", avg_all(rows, cols, user_put));
    printf("最大值：%.2f\n", max(rows, cols, user_put));
}
