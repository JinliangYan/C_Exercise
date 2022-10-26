#include <stdio.h>
#define NAME_LEN 20
#define CSIZE 4
struct name {
    char fr_name[NAME_LEN];
    char la_name[NAME_LEN];
};
struct student{
    struct name stu_name;
    float grade[3];
    float avg_grade;
};
void get_info(struct student *student);
void show_info(struct student *student);
int main(void) {
    struct student students[CSIZE] = {
            {{"Jinliang", "Yan"}},
            {{"Lei", "Yan"}},
            {{"Hongliang", "Liu"}},
            {{"Yaojin", "Zhang"}}
    };

    for (int i = 0; i < CSIZE; i++) {
        get_info(&students[i]);
    }
    for (int i = 0; i < CSIZE; i++) {
        show_info(&students[i]);
    }
    return 0;
}

void get_info(struct student *student) {
    printf("Please enter Please enter %s %s's grade grade(such as 80.5/90.5/100): ", \
    student->stu_name.la_name, student->stu_name.fr_name);
    while (scanf("%f/%f/%f/", &student->grade[0], &student->grade[1], &student->grade[2]) != 3) {
        printf("The input format is incorrect.\n"
               "lease enter Please enter %s %s's grade grade(such as 80.5/90.5/100):",
               student->stu_name.la_name, student->stu_name.fr_name);
    }
    student->avg_grade = (student->grade[0] + student->grade[1] + student->grade[2]) / 3;
}

void show_info(struct student *student) {
    puts("-----------------------------------------------------------");
    printf("Name: %s %s\n", student->stu_name.la_name, student->stu_name.fr_name);
    printf("Math: %.1f\n", student->grade[0]);
    printf("Chinese: %.1f\n", student->grade[1]);
    printf("English: %.1f\n", student->grade[2]);
    printf("Average grade: %.1f\n", student->avg_grade);
};
