#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define  MAXTITLE 40
#define MAXAUTL 40
#define MAXBKS 10
#define FILENAME "library"

inline static void eatline() {
    while (getchar() != '\n') continue;
}
char * s_gets(char * Buffer, int maxCount);

typedef struct {
    char title[MAXTITLE];
    char author[MAXAUTL];
    float value;
    bool isdel;
}BOOK;
static int end = 0;

void read_dat(FILE *dat, BOOK books[]);
void write_dat(FILE *dat, BOOK books[]);
void del(BOOK books[]);
void add(BOOK books[]);
int del_book_index(BOOK books[]);
int menu();
int main(void) {
    BOOK books[MAXBKS];
    FILE *book_dat;
    int choice;
    if ((book_dat = fopen(FILENAME, "r+")) == NULL) {
        fprintf(stderr, "Failed to open %s.\n", FILENAME);
        exit(EXIT_FAILURE);
    }
    while ((choice = menu()) != -1) {
        switch (choice) {
            case 0:
                add(books);
                write_dat(book_dat, books);
                break;
            case 1:
                del(books);
                write_dat(book_dat, books);
                break;
            case 2:
                read_dat(book_dat, books);
                break;
            default:;
        }
    }
    puts("Bey!");
    return 0;
}

int menu() {
    char choice;
    puts("a) Add book          d) Move out a book\n"
         "s) Show all books    q) Quit\n");
    choice = (char)getchar();
    while (strchr("adqs", (char)tolower(choice)) == NULL) {
        printf("Please enter again: ");
        eatline();
        choice = (char)getchar();
    }
    eatline();
    switch (choice) {
        case 'a':
            return 0;
        case 'd':
            return 1;
        case 's':
            return 2;
        default:
            return -1;
    }
}

void read_dat(FILE *dat, BOOK books[]) {
    rewind(dat);

    for (int i = 0; i < MAXBKS; i++) {
        books[i].isdel = true;
    }
    end = 0;
    int ct = 0;
    size_t size = sizeof(BOOK);
    while (end < MAXBKS && fread(&books[ct], size, 1, dat) == 1 && !feof(dat)) {
        books[ct].isdel = false;
        end++, ct++;
    }
    if (ct == 0) {
        printf("No books? too bad!\n");
        return;
    }

    puts("Here are books' information:");
    for (int i = 0; i < end; i++) {
        if (books[i].isdel == false)
            printf("%s by %s($%f)\n", books[i].title, books[i].author, books[i].value);
    }
    rewind(dat);
}

void write_dat(FILE *dat, BOOK books[]) {
    rewind(dat);
    int i;
    for ( i = 0; i < end; i++) {
        if (books[i].isdel == false) {
            fwrite(&books[i], sizeof(BOOK), 1, dat);
        }
    }
    for (int j = i; j < MAXBKS; j++) {
        fwrite("", sizeof(BOOK), 1, dat);
    }
}

void del(BOOK books[]) {
    char deltitle[MAXTITLE];
    printf("Enter the book's title you want to delete: ");
    s_gets(deltitle, MAXTITLE);
    if (deltitle[0] == '\0') return;
    for (int i = 0; i < end; i++) {
        if (strstr(books[i].title, deltitle) != NULL) {
            if (books[i].isdel) {
                printf("No such book.\n");
                return;
            }
            books[i].isdel = true;
            return;
        }
    }
}

void add(BOOK books[]) {
    if (end >= MAXBKS) {
        printf("Can't add book more!");
        return;
    }
    int idx = del_book_index(books);
    if (idx == -1) idx = end, end++;
    printf("Please enter the book title: ");
    s_gets(books[idx].title, MAXTITLE);
    printf("Please enter the author: ");
    s_gets(books[idx].author, MAXAUTL);
    printf("Please enter the value: ");
    while (scanf("%f", &books[idx].value) != 1) {
        printf("Please enter the value again: ");
        eatline();
    }
    books[idx].isdel = false;
}

int del_book_index(BOOK books[]) {
    for (int i = 0; i < MAXBKS; i++) {
        if (books[i].isdel == true)
            return i;
    }
    return -1;
}

char * s_gets(char * Buffer, int maxCount){
    char * ret_value;
    ret_value = fgets(Buffer, maxCount, stdin);
    if (ret_value){
        //替换'\n'为'\0'
        while (*Buffer != '\n' && *Buffer != '\0')
            Buffer++;
        if (*Buffer == '\n')
            *Buffer = '\0';
        else{
            eatline();
        }
    }
    return ret_value;
}
