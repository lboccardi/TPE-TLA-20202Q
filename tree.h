#ifndef TREE_H
#define TREE_H
#include <stdbool.h>

typedef struct node
{
    char *information;
    struct node *next;
    bool free;

} node;

typedef struct code
{
    node *first;
    node *last;
    bool error;
} code;

void initialize();

void add(char *information, bool free);

void freeResources(bool error);

extern code program;

#endif