#include "stack.h"

stackNode *head;

void initializeStack()
{
    head = NULL;
}

stackNode *createNewStackNode(treeNode *pnt, Operations type)
{
    stackNode *tmp;
    tmp = (stackNode *)malloc(sizeof(stackNode));
    tmp->type = type;
    tmp->pnt = pnt;
    tmp->next = NULL;
    return tmp;
}

bool isStackEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

void push(treeNode *pnt, Operations type)
{
    stackNode *tmp = createNewStackNode(pnt,type);
    tmp->next = head;
    head = tmp;
}

void pop(treeNode **ppnt, Operations *pType)
{
     if (isStackEmpty())
     {
         printf("The queue is empty\n");
         return false;
     }
     stackNode *tmp = head;
     head = head->next;
     *ppnt = tmp->pnt;
     *pType = tmp->type;

     free(tmp);
     return true;
}
