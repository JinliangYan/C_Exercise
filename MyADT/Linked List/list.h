//
// Created by Kokomi on 2022/12/17.
//

#ifndef EXERCISE_LIST_H
#define EXERCISE_LIST_H
#include <stdbool.h>
typedef int element_type;

struct node {
    element_type element;
    struct node* next;
};
typedef struct node *node_ptr;
typedef node_ptr LIST;
typedef node_ptr cell;
typedef node_ptr position;/*header's position is -1*/

LIST list_initialize();
element_type list_retrieve(position p);
bool list_is_empty(LIST list);
bool list_is_last(position position, LIST list);
bool list_is_initialized(LIST list);
position list_find(element_type element, LIST list);
void list_delete(element_type element, LIST list);
position list_find_previous(element_type element, LIST list);
void list_insert(element_type element, LIST list, position p);
void delete_list(LIST *list);
size_t list_get_size(LIST list);
position list_get_header(LIST list);
position list_get_first(LIST list);
position list_get_next(position p);
position list_nget_next(position p, unsigned int n);
position list_get_previous(position p, LIST list);
#endif //EXERCISE_LIST_H
