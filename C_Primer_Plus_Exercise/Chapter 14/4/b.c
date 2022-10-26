#include <stdio.h>
#define MAX 20
#define MAXMEM 5
struct info {
    char name[MAX];
    char middle_name[MAX];
    char last_name[MAX];
};
struct member {
    long social_security_number;
    struct info name;
};

void show_info(struct member member);
int main(void) {
    struct member members[MAXMEM] = {
            {10086, {"Jinliang", "Liangliang", "Yan"}},
            {10087, {"Jinliang", "XiaoWang", "Wang"}},
            10088, {"Huiming", "XiaoZhang", "Zhang"},
            10086, {"Lei", "", "Yan"},
            10086, {"Yaojin", "Dingding", "Zhang"}
    };
    int ct = 0;
    while (members[ct].social_security_number != 0 && ct < MAXMEM) {
        show_info(members[ct]);
        ct++;
    }
    return 0;
}

void show_info(struct member member) {
        /*如果有中间名，就打印中间名首字母↓*/
        if (member.name.middle_name[0] != '\0')
            printf("%s, %s %c. -- %ld\n", \
            member.name.name, member.name.last_name, \
            member.name.middle_name[0], member.social_security_number);
        else
            printf("%s, %s -- %ld\n", \
            member.name.name, member.name.last_name, \
            member.social_security_number);
}
