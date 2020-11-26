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

typedef struct var
{
    char *name;
    char type[3]; // %d o %s
    struct var *next;
} var;

typedef struct variables
{
    var *first;
    var *last;

} variables;

void initialize();

void add(char *information, bool free);

void freeResources(bool error);

void addVar(char *name, char *type);
extern code program;
extern variables var_list;
char *printfParser(char *s);

#endif