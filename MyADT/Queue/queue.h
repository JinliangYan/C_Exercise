//
// Created by JavaC on 2022/10/29.
//

#ifndef TEST_C_QUEUE_H
#define TEST_C_QUEUE_H
#include <stdbool.h>

typedef int Item;

#define MAXQUEUE 10

typedef struct node {
    Item item;
    struct node * next;
} Node;

typedef struct queue {
    Node * front;
    Node * rear;
    int items;
} Queue;

void InitializedQueue(Queue * pq);

bool QueueIsFull(const Queue * pq);

bool QueueIsEmpty(const Queue * pq);

int QueueItemCount(const Queue *pq);

bool EnQueue(Item item, Queue * pq);

bool DeQueue(Item *pitem, Queue * pq);

void EmptyTheQueue(Queue *pq);
#endif //TEST_C_QUEUE_H
