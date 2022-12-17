//
// Created by Kokomi on 2022/12/17.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"
#include "fatal.h"
#define INITIALIZED 1
static bool initialize_test(LIST list) {
    if (false == list_is_initialized(list)) {
        error("The list haven't been initialized!\n");
        return false;
    }
    return true;
}

LIST list_initialize() {
    LIST list = NULL;
    cell header = (cell) malloc(sizeof(struct node));
    if (header == NULL)
        fatal_error("Out of space!\n");
    header->next = NULL;
    header->element = INITIALIZED;
    list = header;
    return list;
}

bool list_is_empty(LIST list) {
    if (initialize_test(list))
        return list->next ? true : false;
    return false;
}
bool list_is_last(position position, LIST list) {
    if (initialize_test(list))
        return position->next ? true : false;
    return false;
}
bool list_is_initialized(LIST list) {
    if (list == NULL || list->element != INITIALIZED)
        return false;
    return true;
}
/**
 * Find the element's position in the list(is pointer).
 * @param element
 * @param list
 * @return NULL if not found.
 */
position list_find(element_type element, LIST list) {
    if (initialize_test(list)) {
        position current_pos = list->next;
        while (current_pos != NULL && current_pos->element != element)
            current_pos = current_pos->next;
        if (current_pos == NULL)
            error("Not found!\n");
        return current_pos;
    }
    return NULL;
}
/**
 * Remove this element from the list.
 * @param element
 * @param list
 */
void list_delete(element_type element, LIST list) {
    position to_delete = list_find(element, list); /*here have an initialized test*/
    if (to_delete != NULL) {
        position previous = list_find_previous(element, list);
        previous->next = to_delete->next;
        free(to_delete);
    }
}

position list_find_previous(element_type element, LIST list) {
    position next = list_find(element, list); /*here have an initialized test*/
    position previous = list;

    while (previous != NULL && previous->next != next)
        previous = previous->next;
    return previous;
}
/**
 * Insert the element in the list (after the position p).
 * @param element
 * @param list
 * @param p NULL do nothing.
 */
void list_insert(element_type element, LIST list, position p) {
    if (initialize_test(list)) {
        if (p != NULL) {
            node_ptr new_cell = (node_ptr) malloc(sizeof(struct node));
            if (new_cell == NULL)
                fatal_error("Out of space!\n");
            new_cell->element = element;
            new_cell->next = p->next;
            p->next = new_cell;
        } else
            error("Position is NULL!\n");
    }
}
/**
 * Delete the list and set the value to NULL.
 * @param list the pointer of a list.
 */
void delete_list(LIST *list) {
    if (*list != NULL) {
        cell tem_cell = NULL;
        cell now = *list;
        while (now != NULL) {
            tem_cell = now;
            now = now->next;
            free(tem_cell);
        }
        *list = NULL;
    }
}
position list_get_header(LIST list) {
    if (initialize_test(list))
        return list;
    return NULL;
}
position list_get_first(LIST list) {
    if (initialize_test(list))
        return list->next;
    return NULL;
}
position list_get_next(position p) {
    if (p != NULL)
        return p->next;
    error("The position is NULL!\n");
    return NULL;
}
/**
 * @param p Can be NULL.
 * @param list
 * @return The previous position of p. The last position if p is NULL.
 */
position list_get_previous(position p, LIST list) {
    if (initialize_test(list)) {
        position previous = list;
        while (previous != NULL && previous->next != p)
            previous = previous->next;
        return previous;
    }
    return NULL;
}
