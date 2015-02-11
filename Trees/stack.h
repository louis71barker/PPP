#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "treesort.h"

typedef enum {VISIT, SUBTREE} OPERATIONS;

typedef struct STACKNODE {
    Operations          type;
    treeNode            *pnt;
    struct STACKNODE    *next;

}stackNode;

typedef enum {false, true} bool;

extern void initializeStack();
extern void push(treeNode *pnt, Operations type);
extern bool pop(treeNode **ppnt, Operations *pType);
extern bool isStackEmpty();

#endif
