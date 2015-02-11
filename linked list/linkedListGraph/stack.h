#include "bool.h"
#ifndef STACK_H
#define STACK_H

typedef struct SNODE {
	int          data;
	struct SNODE *next;
} snode;

typedef struct STACK {
	snode *head;
} stack;

extern void initializeStack(stack *stackP);
extern void pushStack(stack *stackP, int data);
extern bool popStack(stack *stackP, int *pData);
extern void printListStack(stack *stackP);
extern bool isEmptyStack(stack *stackP);
#endif // STACK_H
