#ifndef QUEUE_H_
#define QUEUE_H_

#include "gtypes.h"

//linked-list like queue
typedef struct StructOfAQueueNode {
    char nip[20];
    char nama[50];
    char gender;
    char gol[5];
    struct StructOfAQueueNode* next;
} QueueNode;

QueueNode* constructQueue(CONSTR nip, CONSTR nama, char gender, CONSTR gol);
void enqueue(QueueNode** front, CONSTR nip, CONSTR nama, char gender, CONSTR gol);
QueueNode dequeue(QueueNode** front);
QueueNode queuePeek(const QueueNode* front);
//ll-like queue has no definite size, too.

#endif