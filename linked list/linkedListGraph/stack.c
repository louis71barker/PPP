#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initializeStack(stack *stackP)
{
	stackP->head = NULL;
}

snode *createNewSNode(int data)
{
	snode *tmp;
	tmp = (snode *)malloc(sizeof(snode));
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

void pushStack(stack *stackP, int data)
{
	snode *tmp = createNewSNode(data);
	tmp->next = stackP->head;
	stackP->head = tmp;
}

bool popStack(stack *stackP, int *pData)
{
	if(stackP->head == NULL)
	{
		return false;
	}
	snode *tmp= stackP->head;
	stackP->head = stackP->head->next;
	*pData = tmp->data;
	free(tmp);
	return true;
}

void printListStack(stack *stackP)
{
	snode *tmp = stackP->head;
	printf("[");
	while(tmp!=NULL)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("]\n");
}

bool isEmptyStack(stack *stackP)
{
	if(stackP->head == NULL)
		return true;
	else
		return false;
}