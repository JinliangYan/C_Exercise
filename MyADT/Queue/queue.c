#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
static void CopyToNode(Item item, Node * node) {
    node->item = item;
}
static void CopyToItem(Node *node, Item *item) {
    *item = node->item;
}

void InitializedQueue(Queue * pq) {
    pq->items = 0;
    pq->front = NULL;
    pq->rear = NULL;
}

bool QueueIsFull(const Queue * pq) {
    Node * node;
    if ((node = (Node *)malloc(sizeof(Node))) == NULL) {
        return true;
    }
    free(node);
    return false;
}

bool QueueIsEmpty(const Queue * pq) {
    if (pq->items == 0)
        return true;
    return false;
}

int QueueItemCount(const Queue *pq) {
    return pq->items;
}

bool EnQueue(Item item, Queue * pq) {
    Node *new_n;
    if (QueueIsFull(pq))
        return false;
    new_n = (Node *)malloc(sizeof(Item));
    if (new_n == NULL) {
        fprintf(stderr, "Unable to allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    CopyToNode(item, new_n);
    new_n->next = NULL;
    if (QueueIsEmpty(pq)) {
        pq->front = new_n;
    } else {
        pq->rear->next = new_n;
    }
    pq->rear = new_n;
    pq->items++;
    return true;
}

bool DeQueue(Item *pitem, Queue * pq) {
    if (QueueIsEmpty(pq))
        return false;
    Node *pt = pq->front;

    pq->front = pq->front->next;
    free(pt);
    pq->items--;
    if (pq->items == 0) {
        pq->rear = NULL;
    }
    return true;
}
