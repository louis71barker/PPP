#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void initializeQueue(queue *queueP)
{
// initialise the linked list
	queueP->head = NULL;
	queueP->tail = NULL;
}

qnode *createNewQNode(int data)
{
	qnode *tmp;
	tmp = (qnode *)malloc(sizeof(qnode));
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

void printQueue(queue *queueP)
{
	qnode *tmp = queueP->head;
	printf("[");
	while(tmp!=NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("]\n");
}


void addToQueue(queue *queueP, int data)
{
	qnode *tmp = createNewQNode(data);
	if(queueP->head == NULL)
	{
		queueP->head = tmp;
		queueP->tail = tmp;
	}
	else
	{
		queueP->tail->next = tmp;
		queueP->tail = tmp;
	}
}

bool deleteFromQueue(queue *queueP, int *pData)
{
	if(queueP->head == NULL)
	{
		return false;
	}
	qnode *tmp= queueP->head;
	queueP->head = queueP->head->next;
	*pData = tmp->data;
	free(tmp);
	return true;
}

bool isEmptyQueue(queue *queueP)
{
	if(queueP->head == NULL)
		return true;
	else
		return false;
}