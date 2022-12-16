//
// Created by Kokomi on 2022/12/16.
//
#include "open_hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

static unsigned int next_primer(unsigned size) {
    unsigned int v_next = size;
    while (true) {
        unsigned int v_next_sqrt = (unsigned int) sqrt(v_next);
        bool is_odd = true;
        for (unsigned int v_dv = 2; v_dv < v_next_sqrt + 1; v_dv++) {
            if (v_next % v_dv == 0) {
                is_odd = false;
                break;
            }
        }
        if (is_odd)
            return v_next;
        v_next++;
    }
}

static unsigned int hash(element_type element, HASH_TABLE hash_table) {
    return element % hash_table->table_size;
}

position hash_find(element_type element, HASH_TABLE hash_table) {
    LIST list = hash_table->the_lists[hash(element, hash_table)];
    position p = list->next;
    while (p != NULL && p->element != element)
        p = p->next;
    return p;
}


HASH_TABLE hash_initialized(unsigned table_size) {
    HASH_TABLE hash_table;
    table_size = next_primer(table_size);
    hash_table = (HASH_TABLE) malloc(sizeof(unsigned int) + sizeof(LIST*));
    hash_table->the_lists = (LIST *) malloc(sizeof(LIST) * table_size);
    if (hash_table == NULL || hash_table->the_lists == NULL) {
        fprintf(stderr, "Out of space!\n");
        return NULL; //initialized failed!
    }
    for (int i = 0; i < table_size; ++i) {
        hash_table->the_lists[i] = (node_ptr) malloc(sizeof(struct list_node));
        hash_table->the_lists[i]->next = NULL;
    }
    hash_table->table_size = table_size;
    return hash_table;
}

void hash_insert(element_type element, HASH_TABLE hash_table) {
    LIST list;
    position p = hash_find(element, hash_table);
    if (p == NULL) {
    /*Isn't find element*/
        list = hash_table->the_lists[hash(element, hash_table)];
        node_ptr new_cell = (node_ptr)malloc(sizeof(struct list_node));
        if (new_cell == NULL) {
            fprintf(stderr, "Out of space!\n");
            return;
        }
        new_cell->next = list->next;
        new_cell->element = element;
        list->next = new_cell;
    }
    /*here do nothing*/
}

void hash_delete(element_type element, HASH_TABLE hash_table) {
    node_ptr to_delete = hash_find(element, hash_table);
    if (to_delete != NULL) {
        position parent = hash_table->the_lists[hash(element, hash_table)];
        while (parent->next != to_delete) //find to_delete's parent.
            parent = parent->next;
        parent->next = to_delete->next;
        free(to_delete);
    }
}
