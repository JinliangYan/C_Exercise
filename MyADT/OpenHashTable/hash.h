//
// Created by Kokomi on 2022/12/16.
//

#ifndef EXERCISE_OPEN_HASH_H
#define EXERCISE_OPEN_HASH_H
typedef struct list_node *node_ptr;
typedef int element_type;

struct list_node {
    element_type element;
    node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

struct hash_tbl {
    unsigned int table_size;
    LIST *the_lists; //Will be an array of lists(use headers)
};

typedef struct hash_tbl *HASH_TABLE;

HASH_TABLE hash_initialized(unsigned table_size);
void hash_insert(element_type element, HASH_TABLE hash_table);
void hash_delete(element_type element, HASH_TABLE hash_table);
position hash_find(element_type element, HASH_TABLE hash_table);
#endif //EXERCISE_OPEN_HASH_H
