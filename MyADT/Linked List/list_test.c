#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <time.h>
void print_lots(LIST L, LIST P);
LIST get_overlap(LIST list1, LIST list2);
LIST get_union(LIST list1, LIST list2);
int main(void) {
    srand((unsigned int) time(NULL));
    LIST L, P;
    L = list_initialize();
    P = list_initialize();
    position position_p = list_get_header(P);
    for (int i = 1; i < 10; i+=2) {
        list_insert(i, P, position_p);
        position_p = list_get_next(position_p);
    }
    position_p = list_get_header(L);
    for (int i = 0; i < 10; i++) {
        list_insert(i, L, position_p);
        position_p = list_get_next(position_p);
    }
    LIST list = get_union(L, P);
    print_lots(L, P);
    return 0;
}

void print_lots(LIST L, LIST P) {
    position position_1 = list_get_first(L);
    position position_2 = list_get_first(P);
    int counter = 1;
    while (position_2 != END_POS && position_1 != END_POS) {
        if (list_retrieve(position_2) == counter++) {
            printf("%d ", list_retrieve(position_1));
            position_2 = list_get_next(position_2);
        }
        position_1 = list_get_next(position_1);
    }
}

LIST get_overlap(LIST list1, LIST list2) {
    //    clock_t start = clock();
    LIST overlap_list = list_initialize();
    position p1 = list_get_first(list1);
    position p2 = list_get_first(list2);
    position p3 = list_get_header(overlap_list);
    while (p1 != END_POS && p2 != END_POS) {
        if (list_retrieve(p1) < list_retrieve(p2))
            p1 = list_get_next(p1);
        else if (list_retrieve(p1) < list_retrieve(p2))
            p2 = list_get_next(p2);
        else {
            list_insert(list_retrieve(p1), overlap_list, p3);
            p1 = list_get_next(p1);
            p2 = list_get_next(p2);
            p3 = list_get_next(p3);
        }
    }
/*    element_type tmp;
    while (p1 != END_POS) {
        tmp = list_retrieve(p1);
        while (p2 != END_POS && list_retrieve(p2) != tmp)
            p2 = list_get_next(p2);
        if (p2 == END_POS)
            break;
        list_insert(tmp, overlap_list,p3);
        p1 = list_get_next(p1);
        p3 = list_get_next(p3);
    }*/
//    clock_t finish = clock();
//    printf("Run time: %ld\n", finish - start);
    return overlap_list;
}

LIST get_union(LIST list1, LIST list2) {
    position p1, p2, p3, tmp_p;
    element_type key;
    LIST union_list = list_initialize();
    p1 = list_get_first(list1);
    p2 = list_get_first(list2);
    p3 = list_get_header(union_list);
    while (p1 != END_POS && p2 != END_POS) {
        if (list_retrieve(p1) > list_retrieve(p2)) {
            list_insert(list_retrieve(p2), union_list, p3);
            p2 = list_get_next(p2);
        } else if (list_retrieve(p1) < list_retrieve(p2)) {
            list_insert(list_retrieve(p1), union_list, p3);
            p1 = list_get_next(p1);
        } else {
            list_insert(list_retrieve(p1), union_list, p3);
            p1 = list_get_next(p1);
            p2 = list_get_next(p2);
        }
        p3 = list_get_next(p3);
    }
    /*Flush out remaining list*/
    while (p1 != END_POS) {
        list_insert(list_retrieve(p1), union_list, p3);
        p3 = list_get_next(p3);

        p1 = list_get_next(p1);
    }
    while (p2 != END_POS) {
        list_insert(list_retrieve(p2), union_list, p3);
        p3 = list_get_next(p3);
        p2 = list_get_next(p2);
    }

//    while (p1 != END_POS) {
//        if (p2 != NULL && list_retrieve(p2) < list_retrieve(p1)) {
//            /*Ensure that p1 is smaller*/
//            tmp_p = p1;
//            p1 = p2;
//            p2 = tmp_p;
//        }
//        key = list_retrieve(p1);
//        list_insert(key, union_list, p3);
//        p1 = list_get_next(p1);
//        p2 = list_get_next(p2);
//        p3 = list_get_next(p3);
//    }
    return union_list;
}
