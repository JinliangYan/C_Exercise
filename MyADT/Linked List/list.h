//
// Created by Kokomi on 2022/12/17.
//

#ifndef EXERCISE_LIST_H
#define EXERCISE_LIST_H
#define END_POS NULL
#define NOT_FOUND NULL
#include <stdbool.h>
typedef int element_type;
struct node {
    element_type element;
    struct node* next;
};
typedef struct node *node_ptr;
typedef node_ptr POLYNOMIAL;
typedef node_ptr cell;
typedef node_ptr position;/*header's position is -1*/

POLYNOMIAL list_initialize();
element_type list_retrieve(position p);
bool list_is_empty(POLYNOMIAL list);
bool list_is_last(position position, POLYNOMIAL list);
bool list_is_initialized(POLYNOMIAL list);
position list_find(element_type element, POLYNOMIAL list);
void list_delete(element_type element, POLYNOMIAL list);
position list_find_previous(element_type element, POLYNOMIAL list);
void list_insert(element_type element, POLYNOMIAL list, position p);
void delete_list(POLYNOMIAL *list);
size_t list_get_size(POLYNOMIAL list);
position list_get_header(POLYNOMIAL list);
position list_get_first(POLYNOMIAL list);
position list_get_next(position p);
position list_nget_next(position p, unsigned int n);
position list_jump_to(POLYNOMIAL list, unsigned int n);
position list_get_previous(position p, POLYNOMIAL list);
#endif //EXERCISE_LIST_H
