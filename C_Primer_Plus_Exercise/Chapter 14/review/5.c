#include <stdio.h>

struct month {
    char month[10];
    char mon[4];
    int tot_days;
    int number;
};
int count_days(struct month *month, int sta);
void input_int(int *sta);
int main(void) {
    const struct month months[12] = {
            {
                "January",
                "Jan",
                31,
                1
            },
            {
                "February",
                "Feb",
                28,
                2
            },
            {
                "March",
                "Mar",
                31,
                3
            },
            {
                "April",
                "Apr",
                30,
                4
            },
            {
                "May",
                "May",
                31,
                5
            },
            {
                "June",
                "Jun",
                30,
                6
            },
            {
                "July",
                "Jul",
                31,
                7
            },
            {
                "August",
                "Aug",
                31,
                8
            },
            {
                "September",
                "Sep",
                30,
                9
            },
            {
                "October",
                "Oct",
                31,
                10
            },
            {
                "November",
                "Nov",
                30,
                11
            },
            {
                "December",
                "Dec",
                31,
                12
            }
    };
    printf("Please enter a start month(0 to quit): ");
    int sta;
    input_int(&sta);

    while (sta != 0) {
        while (sta > 12 || sta < 0) {
            printf("Out of range, please enter again: ");
            input_int(&sta);
        }
        printf("The total number of days since %s is: %d.\n", months[sta].month, count_days(months, sta));
        printf("You can enter a month again: ");
        input_int(&sta);
    }
    puts("Bye.");

    return 0;
}

int count_days(struct month *month, int sta) {
    int tot = 0;
    for (int i = sta - 1; i < 12; i++) {
        tot += month -> tot_days;
    }
    return tot;
}

void input_int(int *sta) {
    while (scanf("%d", sta) != 1 && *sta != 0) {
        printf("Please enter a month number, such as 2 (0 to quit): ");
        while (getchar() != '\n') continue;
    }
}
