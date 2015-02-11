#ifndef BINARYTREESORT_H
#define BINARYTREESORT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
    int         data;
    struct NODE *left;
    struct NODE *right;
}node;

typedef enum {false, true} bool;

#endif
