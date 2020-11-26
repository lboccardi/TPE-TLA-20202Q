#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

code coding;

void initialize(){
    coding.root = malloc(sizeof(node));  
    coding.curr = coding.root;  
    coding.curr->size = 0;
}
void add(char * information, stage s){
    switch (s)
    {
    case TERMINAL: /* Build branch */
        coding.curr->size++;
        coding.curr->children = realloc(coding.curr->children, coding.curr->size * sizeof(node));
        coding.curr->children[coding.curr->size-1].parent = coding.curr;
        coding.curr = &coding.curr->children[coding.curr->size-1];
        strcpy(coding.curr->information,information);
        coding.curr->size = 0; 
        break;
    case EQUAL: /* Assign */
        coding.curr->children = realloc(coding.curr->children, coding.curr->size * sizeof(node));
    default:
        break;
    }
}