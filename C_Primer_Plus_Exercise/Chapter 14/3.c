#include <stdio.h>
#include <string.h>
char * s_gets(char * Buffer, int maxCount);
#define MAXTITLE 40
#define MAXAUTL 40
#define MAXBKS 2
struct book {
    char title[MAXTITLE];
    char author[MAXAUTL];
    float value;
};
typedef struct book BOOK;
static int book_num = 0;

int add_book(BOOK *book_list);
void show_info(BOOK *book[]);
int main(void) {
    BOOK book_list[MAXBKS];
    BOOK *books_pt[MAXBKS];
    while (add_book(book_list))
        ;
    printf("Enter done.\n");
    /*指针数组指向BOOK所有结构*/
    for (int i = 0; i < MAXBKS; i++) {
        books_pt[i] = &book_list[i];
    }
    /*Output in input order*/
    puts("/*Output in input order*/");
    show_info(books_pt);
    /*Output in alphabetical order of the book title*/
    puts("/*Output in alphabetical order of the book title*/");
    BOOK *tmp1;
    for (int i = 0; i < book_num - 1; i++) {
        for (int j = i; j < book_num; j++) {
            if (strcmp(books_pt[i]->title, books_pt[j]->title) > 0) {
                tmp1 = books_pt[i];
                books_pt[i] = books_pt[j];
                books_pt[j] = tmp1;
            }
        }
    }
    show_info(books_pt);
    /*Output in ascending order of price*/
    puts("/*Output in ascending order of price*/");
    float tmp2;
    for (int i = 0; i < book_num - 1; i++) {
        for (int j = i; j < book_num; j++) {
            if (books_pt[i]->value < books_pt[j]->value) {
                tmp2 = books_pt[i]->value;
                books_pt[i]->value = books_pt[j]->value;
                books_pt[j]->value = tmp2;
            }
        }
    }
    show_info(books_pt);
    return 0;
}

int add_book(BOOK *book_list) {
    char title[MAXTITLE];
    char author[MAXAUTL];
    /*用户要结束输入时返回0↓*/
    int status = 0;
    float value;
    if (book_num >= MAXBKS) {
        printf("It cannot be added more!\n");
        return 0;
    }
    printf("Please enter the book title(Empty line to quit): ");
    if (s_gets(title, MAXTITLE) != NULL && title[0] != '\0') {
        printf("Then enter the author: ");
        s_gets(author, MAXAUTL);
        printf("Now, enter the value: ");
        while (scanf("%f", &value) != 1) {
            printf("Please enter the correct price: ");
            while (getchar() != '\n') continue;
        }
        while (getchar() != '\n') continue;
        strcpy(book_list[book_num].title, title);
        strcpy(book_list[book_num].author, author);
        book_list[book_num].value = value;
        book_num++;
        status = 1;
    }
    return status;
}

void show_info(BOOK *book[]) {
    if (book_num > 0) {
        for (int i = 0; i < book_num; i++) {
            printf("%s by %s: ￥%f\n", book[i]->title, book[i]->author, book[i]->value);
        }
    } else {
        puts("No books? too bad.");
    }
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
            while (getchar() != '\n');
        }
    }
    return ret_value;
}



