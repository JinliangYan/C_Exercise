#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10
#define FILE_NAME "library.dat"

inline static void eatline() {
    while (getchar() != '\n') continue;
}

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};
struct pack
{
    struct book books;
    bool canceled;
};
char * s_gets(char * Buffer, int maxCount);
int search_title(char *title, struct pack items[]);
char get_first(char *str);
void update(struct pack items[]);
void modify(struct pack items[]);
void add_book(struct pack items[]);
char menu();
int main(void) {
    struct pack items[MAXBKS];
    FILE *fp;
    int book_count = 0;
    /*载入book数据↓*/
    if ((fp = fopen(FILE_NAME, "rb")) == NULL) {
        fprintf(stderr, "Failed to open %s.\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }
    while (1 == fread(&items[book_count].books, sizeof(struct book), 1, fp) && book_count < MAXBKS) {
        items[book_count].canceled = false;//表示该书籍存在
        book_count++;
    }
    /*没有储存书籍的空间标记已删除*/
    for (int i = book_count; i < MAXBKS; i++) {
        items[i].canceled = true;
    }
    /*关闭文件*/
    if (fclose(fp) == EOF) {
        fprintf(stderr, "Failed to close %s.\n", FILE_NAME);
        exit(EXIT_FAILURE);
    }
    /*以上准备工作完成↑*/
    char option;
    while ((option = menu()) != 'q') {
        switch (option) {
            case 's':
                if (book_count == 0) {
                    puts("No books? Too bad!");
                    break;
                }
                for (int i = 0; i < MAXBKS; i++) {
                    if (i == 0) {
                        puts("Current contents of "FILE_NAME":");
                    }
                    if (items[i].canceled) continue;
                    printf("%s by %s: $%.2f\n", items[i].books.title,items[i].books.author, items[i].books.value);
                }
                break;
            case 'a':
                add_book(items);
                break;
            case 'm':
                modify(items);
                break;
            default:;
        }
    }

    return 0;
}

char menu() {
    puts("=========================================================");
    puts("s) Show all the books              a) Add new book\n"
             "m)Modify the book                  q) quit");
    puts("=========================================================");
    char option = get_first("samq");
    return option;
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
/*更新文本文件
 * 使用该函数，未储存书籍的空间必须标记为已删除！
 * fp必须是w模式打开！↓*/
void update(struct pack items[]) {
    FILE *save;
    if ((save = fopen(FILE_NAME, "wb")) == NULL) {
        fprintf(stderr, "Failed to save!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < MAXBKS; i++) {
        if (items[i].canceled == false) {
            fwrite(&items[i].books, sizeof(struct book), 1, save);
        }
    }
    if (fclose(save) == EOF) {
        fprintf(stderr, "Sorry, the date may not be saved\n");
        exit(EXIT_FAILURE);
    }
    printf("Update succeed!\n");
}

/*使用该函数，未储存书籍的空间必须标记为已删除！*/
void modify(struct pack items[]) {
    /*检查是否有可修改的书籍并列出可修改的书籍*/
    int del_book_num = 0;
    int index;
    struct pack copy;
    char dest_book[MAXTITL];
    for (int i = 0; i < MAXBKS; i++) {
        if (items[i].canceled)
            del_book_num++;
        else {
            puts("=============================================================");
            printf("%s by %s: $%.2f\n", items[i].books.title, items[i].books.author, items[i].books.value);
            puts("=============================================================");
        }

    }
    if (del_book_num == MAXBKS) {
        printf("No books? Too bad!\n");
        return;         //没有书籍可修改直接返回
    }
    printf("Which book do you want to modify?\n"
               "Please enter the title: ");
    /*找到目标书籍下标index↓*/
    while (s_gets(dest_book, MAXTITL) != NULL && (index = search_title(dest_book, items) == -1)) {
        printf("Do not have the book, please re-enter: ");
    }
    /*操作目标书籍的副本，便于修改↓*/
    copy = items[index];
    /*获得用户选择↓*/
    char option;
    puts("What information you want to modify to the book: ");
    puts("========================================================");
    printf("t) title              a) author\n");
    printf("v) value              d) delete it\n");
    printf("s) save and quit      q) quit without save\n");
    puts("========================================================");
    while ((option = get_first("tavdqs")) != 'q') {
        switch (option) {
            case 't':
                printf("Please enter the new title: ");
                s_gets(copy.books.title, MAXTITL);
                break;
            case 'a':
                printf("Please enter the new author: ");
                s_gets(copy.books.author, MAXAUTL);
                break;
            case 'v':
                printf("Please enter the new value: ");
                /*处理错误输入*/
                while (scanf("%f", &copy.books.value) != 1) {
                    printf("Please enter a value number(such as 52.5): ");
                    eatline();
                }
                break;
            case 'd':
                printf("Are you sure? Y or N: ");
                if (get_first("yn") == 'y') {
                    copy.canceled = true;
                }
                break;
            case 's':
                items[index] = copy;
                update(items);
                return;
            default:;
        }
        puts("What information you want to modify to the book: ");
        puts("========================================================");
        printf("t) title              a) author\n");
        printf("v) value              d) delete it\n");
        printf("s) save and quit      q) quit without save\n");
        puts("========================================================");
    }
    puts("Done!");
}
void add_book(struct pack items[]) {
    int index;
    for (index = 0; index < MAXBKS; index++) {
        if (items[index].canceled) break;
    }
    if (index == MAXBKS) {
        printf("Have no available place to add new book.\n");
        return;
    }
    printf("Please enter the new title: ");
    s_gets(items[index].books.title, MAXTITL);
    printf("Please enter the new author: ");
    s_gets(items[index].books.author, MAXAUTL);
    printf("Please enter the new value: ");
    /*处理错误输入*/
    while (scanf("%f", &items[index].books.value) != 1) {
        printf("Please enter a value number(such as 52.5): ");
        eatline();
    }
    items[index].canceled = false; //保存成功
    eatline();
    update(items);
}
/*按标题搜索书籍，并返回下标
 * 没有该书籍则返回-1*/
int search_title(char *title, struct pack items[]) {
    for (int i = 0; i < MAXBKS; i++) {
        if (strcmp(title, items[i].books.title) == 0 && items[i].canceled == false) {
            return i;
        }
    }
    /*没有该书籍返回-1*/
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
            while (getchar() != '\n');
        }
    }
    return ret_value;
}
