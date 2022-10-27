#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define FNAME_MAX 20
#define LNAME_MAX 20
#define SIT_NUM 12

inline static void eatline() {
    while (getchar() != '\n') continue;
}
struct site {
    int number;
    bool isbooked;
    char fname[FNAME_MAX];
    char lname[LNAME_MAX];
};
char get_first(char *str);
char menu();
int show_empty_seat(struct site plane[]);
void show_empty_seat_list(struct site plane[]);
void show_alp_list(struct site plane[]);
void delete_assign(struct site plane[]);
void assign(struct site plane[]);

int main(void) {
    struct site plane[12];
    for (int i = 0; i < SIT_NUM; i++) {
        plane[i].isbooked = false;
        plane[i].number = i + 1;
    }
    char option;
    while ((option = menu()) != 'f') {
        switch (option) {
            case 'a':
                show_empty_seat(plane);
                break;
            case 'b':
                show_empty_seat_list(plane);
                break;
            case 'c':
                show_alp_list(plane);
                break;
            case 'd':
                assign(plane);
                break;
            case 'e':
                delete_assign(plane);
                break;
            default:;
        }
    }
    return 0;
}

char menu(){
    puts("====================================================");
    puts("To choose a function, enter its letter label: ");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) quit");
    puts("====================================================");
    return get_first("abcdef");
}

int show_empty_seat(struct site plane[]) {
    int count = 0;
    for (int i = 0; i < SIT_NUM; i++) {
        if (plane[i].isbooked == false) count++;
    }
    if (count)
        printf("%d seat(s) are empty.\n", count);
    else
        printf("No seat is empty.\n");
    return count;
}

void show_empty_seat_list(struct site plane[]) {
    int empty_seats[SIT_NUM] = {0};
    int *pInt = empty_seats;
    int ct = 0;
    for (int i = 0; i < SIT_NUM; i++) {
        if (plane[i].isbooked == false) {
            *pInt++ = plane[i].number;
            ct++;
        }
    }
    if (ct) {
        for (int i = 0; i < ct; i++) {
            if (i == 0) {
                printf("Empty seats:");
            }
            printf(" %d", empty_seats[i]);
        }
        putchar('\n');
    }
    else
        printf("No seat is empty.\n");
}

void show_alp_list(struct site plane[]) {
    struct site *pSite[SIT_NUM];
    struct site *temp;
    int ct = 0;
    for (int i = 0; i < SIT_NUM; i++) {
        if (plane[i].isbooked)
            pSite[ct++] = &plane[i];
    }
    if (show_empty_seat(plane) == SIT_NUM) {
        printf("All seats is empty.\n");
        return;
    }
    for (int i = 0; i < ct - 1; i++) {
        for (int j = i + 1; j < ct; j++) {
            if (strcmp(pSite[i]->fname, pSite[j]->fname) > 0) {
                temp = pSite[i];
                pSite[i] = pSite[j];
                pSite[j] = temp;
            }
        }
    }

    for (int i = 0; i < ct; i++) {
        printf("Seat %d: %s, %s\n", pSite[i]->number, pSite[i]->lname, pSite[i]->fname);
    }
}

void delete_assign(struct site plane[]) {
    int id;
    printf("Enter the seat number you want to delete: ");
    while (scanf("%d", &id) != 1 || id <= 0 || id > SIT_NUM || !plane[id - 1].isbooked) {
        printf("Please enter again: ");
        eatline();
    }
    eatline();
    printf("%s %s, are you sure to delete it? (Y or N):", plane[id-1].fname, plane[id-1].lname);
    if (get_first("yn") == 'y') {
        plane[id - 1].isbooked = false;
        printf("Good bye~\n");
    } else {
        puts("Operation canceled.");
    }
}

void assign(struct site plane[]) {
    struct site copy;
    int id;
    printf("Enter the seat number you want to assign");
    while (scanf("%d", &id) != 1 && id > 0 && id <= SIT_NUM &&!plane[id - 1].isbooked) {
        printf("Please enter again: ");
        eatline();
    }
    eatline();
    copy = plane[id-1];
    printf("Enter you name please: ");
    while (scanf("%s %s", copy.fname, copy.lname) != 2) {
        printf("Please enter again: ");
        eatline();
    }
    eatline();
    printf("Press Y to sure your assignment, N to quit: ");
    if (get_first("yn") == 'y') {
        plane[id - 1] = copy;
        printf("%s %s, welcome!\n", copy.fname, copy.lname);
        plane[id - 1].isbooked = true;
    } else {
        printf("Good bye~\n");
    }
}

char get_first(char *str) {
    int ch;
    while ((ch = tolower(getchar())) != EOF && strchr(str, (char)ch) == NULL) {
        printf("Please enter again: ");
        eatline();
    }
    eatline();
    return (char)ch;
}
