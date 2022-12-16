//
// Created by Kokomi on 2022/12/15.
//
#include "closed_hash.h"
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

static INDEX hash(element_type element, HASH_TABLE hashTable) {
    return element % hashTable->table_size;
}

/*find the next empty spot(to insert) or element's position(to delete)*/
static position find(element_type element, HASH_TABLE hashTable) {
    position current_pos = hash(element, hashTable), i = 0;
    while (hashTable->the_cells[current_pos].info != empty && element != hashTable->the_cells[current_pos].element) {
        current_pos += ++i * 2 - 1;
        if (current_pos >= hashTable->table_size)
            current_pos -= hashTable->table_size;
    }
    return current_pos;
}

HASH_TABLE initialized_table(unsigned int table_size) {
    table_size = next_primer(table_size);
    if (table_size < MIN_TABLE_SIZE) {
        return initialized_failed; //defined as NULL
    }
    HASH_TABLE hashTable = (HASH_TABLE)malloc(sizeof(cell*) + sizeof(unsigned int));
    cell *the_cells = (cell *) malloc(table_size * sizeof(cell));
    if (hashTable == NULL || the_cells == NULL) {
        fprintf(stderr, "Out of space!\n");
        return initialized_failed;
    }
    hashTable->table_size = table_size;
    hashTable->the_cells = the_cells;
    hashTable->size = 0;
    for (int i = 0; i < table_size; ++i)
        the_cells[i].info = empty;
    return hashTable;
}

void insert(element_type element, HASH_TABLE hashTable) {
    if (hashTable->table_size < ++hashTable->size) {
        fprintf(stderr, "Max item error!\n");
        return;
    }
    position current_pos = find(element, hashTable);
    hashTable->the_cells[current_pos].element = element;
    hashTable->the_cells[current_pos].info = legitimate;
}

void delete(element_type element, HASH_TABLE hashTable) {
    position current_pos = find(element, hashTable), i = 0;
    while (hashTable->the_cells[current_pos].info != legitimate || element != hashTable->the_cells[current_pos].element) {
        current_pos += ++i * 2 - 1;
        if (current_pos >= hashTable->table_size)
            current_pos -= hashTable->table_size;
    }
    hashTable->the_cells[current_pos].info = deleted;
    hashTable->size--;
}
