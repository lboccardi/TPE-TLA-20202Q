#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

code program;

void initialize()
{
    program.error = false;
}

void add(char *information, bool free)
{
    node *aux = malloc(sizeof(node));
    aux->free = free;
    aux->next = NULL;
    aux->information = information;
    if (program.first == NULL)
    {
        program.first = aux;
    }
    else
    {
        program.last->next = aux;
    }
    program.last = aux;
}

void freeResources(bool error)
{
    node *curr = program.first;

    if (curr == NULL)
    {
        return;
    }

    while (curr->next != NULL)
    {
        node *aux = curr->next;
        if (curr->free)
        {
            free(curr->information);
        }
        free(curr);
        curr = aux;
    }
    if (error)
    {
        if (curr->free)
        {
            free(curr->information);
        }
        free(curr);
        program.error = true;
        program.first = NULL;
        program.last = NULL;
    }
    else
    {
        program.first = curr;
        program.last = curr;
    }
}