#ifndef TREE_H
#define TREE_H

typedef enum stage{
    END,
    EQUAL,
    FUNCTION,
    LEAF,
    TERMINAL
}stage;

typedef struct node{
    char * information;
    struct node * children;
    size_t size;
    struct node * parent;
} node; 

typedef struct code{
    node * root;
    node * curr;
    size_t size;
} code; 

#endif