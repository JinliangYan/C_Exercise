/*
 * player.txt
 *
0 Jessie Joybat 5 2 1 1
1 Mary Json 6 3 7 9
2 Filp Shell 5 3 6 1
3 Francy Card 9 6 1 2
4 Wan cary 8 5 2 1
5 Keassy Coffee 3 3 6 7
0 Jessie Joybat 7 9 8 2
5 Keassy Coffee 4 7 5 8
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20
#define PL_NUM 18
typedef struct
{
    int id;          //球员的编号
    char fname[LEN]; //球员的名;
    char lname[LEN]; //球员的姓;
    int stage_num;   //球员的上场次数;
    int hit_num;     //球员的击中数;
    int base_num;    //球员的走垒数;
    int rbi;         //球员的打点;
    float hit_rate;  //球员的安打率;
} PLAYER;

char * s_gets(char * Buffer, int maxCount);
void read_writ(FILE *info, PLAYER team[]);
void show_info(PLAYER players[], int n);
int main(void) {
    PLAYER team[PL_NUM] = {0};
    char file_name[FILENAME_MAX];
    FILE *player_info;

    printf("Please enter the file name: ");
    s_gets(file_name, FILENAME_MAX);
    if ((player_info = fopen(file_name, "rb")) == NULL) {
        fprintf(stderr, "Failed to open %s.\n", file_name);
        exit(EXIT_FAILURE);
    }
    read_writ(player_info, team);
    show_info(team, 6);
    return 0;
}

void read_writ(FILE *info, PLAYER team[]) {
    int id;
    char fname[LEN];
    char lname[LEN];
    int stage_num;
    int hit_num;
    int base_num;
    int rbi;
    int status;
    while ((status = fscanf(info, "%d %s %s %d %d %d %d", &id, fname, lname, &stage_num, &hit_num, &base_num, &rbi)) != EOF \
    && status == 7 )
    {
        team[id].id = id, team[id].stage_num += stage_num, team[id].base_num += base_num, team[id].hit_num += hit_num, team[id].rbi += rbi;
        if (team[id].fname[0] == '\0') {
            strcpy(team[id].fname, fname);
            strcpy(team[id].lname, lname);
        }
    }
    /*计算命中率↓*/
    for (int i = 0; i < PL_NUM; i++) {
        team[i].hit_rate = (float)team[i].hit_num / (float)team[i].stage_num;
    }
}

void show_info(PLAYER players[], int n) {
    int i;

    if (0 == n) {
        printf("No datas!\n");
    } else {
        printf("Datas for all players:\n");
        printf("Id   First_name   Last_name   Stage   Hit_rate   Base_num   RBI   Hit_rate\n");
        for (i = 0; i < n; i++) {
            printf("%-4d %-12s %-10s %5d %7d %11d %8d %8.2f\n",
                   players[i].id, players[i].fname, players[i].lname,
                   players[i].stage_num, players[i].hit_num, players[i].base_num,
                   players[i].rbi, players[i].hit_rate);
        }
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
