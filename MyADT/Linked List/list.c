#include "list.h"
#include <stdlib.h>

static void CopyToNode(Item item, Node * pnode) {
    pnode->item = item;
}

void InitializeList(List * pList) {
    *pList = NULL;
}

bool ListIsEmpty(const List * pList) {
    if (!pList) {
        return true;
    }
    return false;
}

bool ListIsFull(const List * pList) {
    Node *pnode;
    if ((pnode = malloc(sizeof(Node))) == NULL) {
        return true;
    }
    free(pnode);
    return false;
}

unsigned int ListItemCount(const List * pList) {
    Node *pnode = *pList;
    unsigned int count = 0;
    while (pnode) {
        count++;
        pnode = pnode->next;
    }
    return count;
}

bool AddItem(Item item, List * pList) {
    Node *scan = *pList;
    Node *pnew;
    if ((pnew = (Node *) malloc(sizeof(Node))) == NULL) {
        return false;
    }
    CopyToNode(item, pnew);
    pnew->next = NULL;
    if (pList == NULL) {
        *pList = pnew;
    } else {
        while (scan->next) {
            scan = scan->next;
        }
        scan->next = pnew;
    }
    return true;
}

void Traverse(const List *pList, void(*pfun)(Item item)) {
    Node * current = *pList;
    while (current) {
        (*pfun)(current->item);
        current = current->next;
    }
}

void EmptyTheList(List *pList) {
    Node * psave;
    while (*pList) {
        psave = (*pList)->next;
        free(*pList);
        *pList = psave;
    }
}
