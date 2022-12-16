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
INDEX hash(element_type element, HASH_TABLE hashTable) {
    INDEX index = element % hashTable->table_size, i = 0;
    while (hashTable->the_cells[index].info == legitimate) {
        index += ++i;
        if (index >= hashTable->table_size)
            index -= hashTable->table_size;
    }
    return index;
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

/*ignore the deleted cells*/
position find(element_type element, HASH_TABLE hashTable) {
    INDEX index = element % hashTable->table_size, i = 0;
    while (hashTable->the_cells[index].info != empty && element != hashTable->the_cells[index].element) {
        index += ++i;
        if (index >= hashTable->table_size)
            index -= hashTable->table_size;
    }
    return index;
}

void insert(element_type element, HASH_TABLE hashTable) {
    if (hashTable->table_size < ++hashTable->size) {
        fprintf(stderr, "Max item error!\n");
        return;
    }
    hashTable->the_cells[hash(element, hashTable)].element = element;
    hashTable->the_cells[hash(element, hashTable)].info = legitimate;
}

void delete(element_type element, HASH_TABLE hashTable) {
    INDEX index = find(element, hashTable), i = 0;
    while (hashTable->the_cells[index].info != legitimate || element != hashTable->the_cells[index].element) {
        index += ++i;
        if (index >= hashTable->table_size)
            index -= hashTable->table_size;
    }
    hashTable->the_cells[index].info = deleted;
    hashTable->size--;
}
