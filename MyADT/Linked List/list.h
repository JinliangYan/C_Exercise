//
// Created by JavaC on 2022/10/29.
//

#ifndef TEST_C_LIST_H
#define TEST_C_LIST_H

#endif //TEST_C_LIST_H

#include <stdbool.h>

/*A program-specific declaration*/

#define TSIZE 45 //储存电影名的数组大小
struct film {
    char title[TSIZE];
    int rating;
};

/*General type definition*/

typedef struct film Item;

typedef struct node {
    Item item;
    struct node *next;
} Node;

typedef Node * List;

/*Function prototype*/

/**
 * Initialize a linked list
 * @param pList The linked list's pointer to be initialized
 * The linked list is initialized empty.
 */
void InitializeList(List * pList);

/**
 * Determine if a linked list is empty.
 * @param pList points to an initialized linked list you want to judge.
 * @return If the list is empty, return true, else return false.
 */
bool ListIsEmpty(const List * pList);

/**
 * Determine if a linked list is full
 * @param pList points to an initialized linked list you want to judge.
 * @return If the list is full return true, else return false.
 */
bool ListIsFull(const List * pList);

/**
 *Determine the number of items in the linked list
 * @param pList points to an initialized linked list you want to count.
 * @return The number of items in the linked list.
 */
unsigned int ListItemCount(const List * pList);

/**
 *Add an item at the end of the linked list.
 * @param item
 * @param pList An initialized linked list.
 * @return If the addition is successful, it returns true, else return false.
 */
bool AddItem(Item item, List * pList);

/**
 * Apply the function to each item in the linked list.
 * @param pList An pointer to the initialized linked list.
 * @param pfun The function accepts an argument of type item and has no return value.
 */
void Traverse(const List *pList, void(*pfun)(Item item));

/**
 * Free allocated memory.
 * @param pList An pointer to the initialized linked list.
 */
void EmptyTheList(List *pList);

static void CopyToNode(Item item, Node * pnode);
