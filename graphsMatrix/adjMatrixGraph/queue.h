#include "bool.h"
#ifndef QUEUE_H
#define QUEUE_H

typedef struct QNODE {
	int          data;
	struct QNODE *next;
} qnode;

typedef struct QUEUE {
	qnode *head;
	qnode *tail;
} queue;

extern void initializeQueue(queue *queueP);
extern void addToQueue(queue *queueP, int data);
extern bool deleteFromQueue(queue *queueP, int *pData);
extern void printQueue(queue *queueP);
extern bool isEmptyQueue(queue *queueP);
#endif // QUEUE_H
