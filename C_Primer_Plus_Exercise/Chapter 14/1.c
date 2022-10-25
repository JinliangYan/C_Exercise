#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct month {
    char month[10];
    char mon[4];
    int tot_days;
    int number;
};

const char search[] = "January,February,March,April,May,June,July,August,September,October,November,December,Q";
int input(const struct month *mp);
int count_days(struct month *mp, int sta);
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
    struct month *mp = months;

    int sta;
    sta = input(mp);

    while (sta != -1) {
        printf("The total days from %s is %d.\n", months[sta].month, count_days(mp, sta));
        sta = input(mp);
    }
    puts("Bye.");

    return 0;
}

int count_days(struct month *mp, int sta) {
    int tot = 0;
    for (int i = sta; i < 12; i++) {
        tot += mp[i].tot_days;
    }
    return tot;
}

int input(const struct month *mp) {
    char choice[10];
    printf("Please enter the start month(q to quit): ");
    while (scanf("%s", (char *)choice) == 1) {
        choice[0] = (char)toupper(choice[0]);
        if (strstr(search, (char *)choice) != NULL)
            break;
        printf("Please enter the correct month(such as Jan or january, q to quit): ");
    }

    for (int i = 0; i < 12; i++) {
        if (strstr(mp[i].month, (char *)choice) != NULL) {
            return i;
        }
    }
    return -1;
}
