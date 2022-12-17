//
// Created by Kokomi on 2022/12/15.
//
#include <stdio.h>
#ifndef EXERCISE_CLOSED_HASH_H
#define EXERCISE_CLOSED_HASH_H
#define MIN_TABLE_SIZE 10
#define initialized_failed NULL
enum kind_of_entry {legitimate, empty, deleted};
typedef long long element_type;
struct hash_entry {
    element_type element;
    enum kind_of_entry info;
};
typedef unsigned int INDEX;
typedef INDEX position;
typedef struct hash_entry cell;
struct hash_tbl {
    unsigned int table_size;
    unsigned int size;
    cell *the_cells;
};
typedef struct hash_tbl *HASH_TABLE;
HASH_TABLE hash_initialized(unsigned int table_size);
HASH_TABLE hash_insert(element_type element, HASH_TABLE hashTable);
HASH_TABLE hash_delete(element_type element, HASH_TABLE hashTable);
position hash_find(element_type element, HASH_TABLE hashTable);
#endif //EXERCISE_CLOSED_HASH_Hx
