//
// Created by Kokomi on 2022/12/15.
//
#include "hash.h"
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
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

static INDEX hash(element_type element, HASH_TABLE hash_table) {
    return element % hash_table->table_size;
}

static HASH_TABLE rehashing(HASH_TABLE hash_table_old) {
    HASH_TABLE hash_table_new = hash_initialized(2 * hash_table_old->table_size);
    for (int i = 0; i < hash_table_old->size; ++i) {
        if (hash_table_old->the_cells[i].info == legitimate) {
            hash_insert(hash_table_old->the_cells[i].element, hash_table_new);
            hash_table_old->the_cells[i].info = legitimate;
        } else {
            hash_table_old->the_cells[i].info = empty;
        }
    }
    hash_table_new->size = hash_table_old->size;
    free(hash_table_old->the_cells);
    free(hash_table_old);
    return hash_table_new;
}
/*find the next empty spot(to hash_insert) or element's position(to hash_delete)*/
position hash_find(element_type element, HASH_TABLE hash_table) {
    position current_pos = hash(element, hash_table), i = 0;
    while (hash_table->the_cells[current_pos].info != empty && element != hash_table->the_cells[current_pos].element) {
        current_pos += ++i;
        if (current_pos >= hash_table->table_size)
            current_pos -= hash_table->table_size;
    }
    return current_pos;
}

HASH_TABLE hash_initialized(unsigned int table_size) {
    table_size = next_primer(table_size);
    if (table_size < MIN_TABLE_SIZE) {
        return initialized_failed; //defined as NULL
    }
    HASH_TABLE hash_table = (HASH_TABLE)malloc(sizeof(cell*) + sizeof(unsigned int) * 2);
    cell *the_cells = (cell *) malloc(table_size * sizeof(cell));
    if (hash_table == NULL || the_cells == NULL) {
        fprintf(stderr, "Out of space!\n");
        return initialized_failed;
    }
    hash_table->table_size = table_size;
    hash_table->the_cells = the_cells;
    hash_table->size = 0;
    for (int i = 0; i < table_size; ++i)
        the_cells[i].info = empty;
    return hash_table;
}

/*the rehashing may change the value of hash_table,
 * but this hash_table just a real hash_table's copy(different memory address but same value),
 * thus the hash_table's value must be updated using "=".
 * usage: hash_table = hash_insert(element, hash_table)
 * */
HASH_TABLE hash_insert(element_type element, HASH_TABLE hash_table) {
    float alpha = (float)(hash_table->size) / (float)(hash_table->table_size);
    if (alpha >= 0.5) {
        hash_table = rehashing(hash_table);
    }
    position current_pos = find(element, hash_table);
    hash_table->the_cells[current_pos].element = element;
    hash_table->the_cells[current_pos].info = legitimate;
    hash_table->size++;
    return hash_table;
}

HASH_TABLE hash_delete(element_type element, HASH_TABLE hash_table) {
    position current_pos = find(element, hash_table), i = 0;
    while (hash_table->the_cells[current_pos].info != legitimate || element != hash_table->the_cells[current_pos].element) {
        current_pos += ++i;
        if (current_pos >= hash_table->table_size)
            current_pos -= hash_table->table_size;
    }
    hash_table->the_cells[current_pos].info = deleted;
    hash_table->size--;
    return hash_table;
}
