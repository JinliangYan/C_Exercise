#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct month {
    char month[10];
    char mon[4];
    int tot_days;
    int number;
};

const char search[] = "January,February,March,April,May,June,July,August,September,October,November,December,Q";
struct month months[12] = {{"January","Jan",31,1},{"February","Feb",28,2},
        {"March","Mar",31,3},{"April","Apr",30,4},
        {"May","May",31,5},{"June","Jun",30,6},
        {"July","Jul",31,7},{"August","Aug",31,8},
        {"September","Sep",30,9},{"October","Oct",31,10},
        {"November","Nov",30,11},{"December","Dec",31,12}};
int input_year();
int input_month();
int input_day(int month);
int count_days(int month, int day);
int main(void) {
    int year;
    int month, end_mon;
    int day, end_day;
    int tot;
    year = input_year();
    while (year != -1) {
        month = input_month();
        day = input_day(month);
        printf("Then enter the end month.\n");
        end_mon = input_month();
        printf("Enter the end day.\n");
        end_day = input_day(end_mon);
        tot = count_days(month, day) - count_days(end_mon, end_day);
        while (tot < 0) {
            printf("The end time must be greater than the start time. Please enter again.\n");
            end_mon = input_month();
            end_day = input_day(end_mon);
            tot = count_days(month, day) - count_days(end_mon, end_day);
        }
        printf("The total days from %d %s %d to %d %s %d is %d.\n",\
        day, months[month].month, year, end_day, months[end_mon].month, year, tot + 1);//tot +1 contains end day.
        year = input_year();
    }
    puts("Bye.");
    return 0;
}

int count_days(int month, int day) {
    int tot = 0;
    for (int i = month; i < 12; i++) {
        tot += months[i].tot_days;
    }
    tot -= day;
    return tot;
}

int input_year() {
    int year;
    printf("Please enter the year(-1 to quit): ");
    while (scanf("%d", &year) != 1 || year < -1) {
        printf("Please enter the correct year(-1 to quit): ");
        while (getchar() != '\n') continue;
    }
    /*如果时闰年，二月份再加一天*/
    if( ((0 == year%4)&&(0 != year%100)) ||(0 == year %400) ) {
        months[1].tot_days++;
    }
    return year;
}

int input_month() {
    int ret_val = -1;
    char choice[10];
    printf("Please enter the month: ");
    while (scanf("%s", (char *)choice) == 1) {
        /*当输入是月份数字时*/
        char *end;
        if ((ret_val = strtol(choice, &end, 10)) != 0 && ret_val < 13 && ret_val > 0) {
            return ret_val - 1;
        }
        choice[0] = (char)toupper(choice[0]);
        if (strstr(search, (char *)choice) != NULL)
            break;
        printf("Please enter the correct month(such as Jan or january or 1): ");
    }

    int i;
    for (i = 0; i < 12; i++) {
        if (strstr(months[i].month, (char *)choice) != NULL) {
            break;
        }
    }
    return i;
}

int input_day(int month) {
    int day;
    printf("Please enter the day: ");
    while (scanf("%d", &day) != 1 || day <= 0 || day > months[month].tot_days) {
        printf("Please enter the correct number of days in %s: ", months[month].month);
        while (getchar() != '\n') continue;
    }
    return day;
}
