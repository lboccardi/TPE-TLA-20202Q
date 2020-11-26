#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

code program;
variables var_list;

void initialize()
{
    program.error = false;
    var_list.first = NULL;
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

void freeVars()
{
    var *curr = var_list.first;
    while (curr != NULL)
    {
        var *aux = curr->next;
        free(curr);
        curr = aux;
    }
}

void freeResources(bool error)
{
    node *curr = program.first;
    freeVars();
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
void addVar(char *name, char *type)
{
    var *aux = malloc(sizeof(var));
    /** save type **/
    char *aux_type;
    if (strcmp(type, "i$") == 0)
    {
        aux_type = "%d";
    }
    else
    {
        aux_type = "%s";
    }
    strcpy(aux->type, aux_type);
    /** save name **/
    aux->name = name;
    if (var_list.first == NULL)
    {
        var_list.first = aux;
    }
    else
    {
        var_list.last->next = aux;
    }
    var_list.last = aux;
    aux->next = NULL;
}

char *printfParser(char *s)
{ /** hola ''a12b5'' como estas --> \"hola %d como estas\",a12b5  **/
    /** hola ''a12b5' como estas --> \"hola %d como estas\",a12b5  **/
    char *ans = malloc(strlen(s) * 2 + 5);
    //ans[0] = '\\';
    ans[0] = '\"';

    int i = 0, j = 1, k = 0;
    char name[strlen(s)];
    name[0] = 0;
    while (s[i] != '\0')
    {

        if (s[i] != '\'')
        {
            ans[j++] = s[i++];
        }
        else if (s[i + 1] == '\'')
        {
            ans[j++] = s[i];
            i += 2;
        }
        else
        {
            i++; //found a ' --> skip it

            if (k != 0)
            { //NO primera vez que encuentro una variable
                name[k++] = ',';
            }
            int pointer = k;
            while (s[i] != '\'' && s[i] != '\0')
            {
                name[k++] = s[i++];
            }
            name[k] = 0;
            var *curr = var_list.first;
            while (curr != NULL)
            {
                var *aux = curr->next;

                if (strcmp(curr->name, name + pointer) == 0)
                {
                    strcpy(ans + j, curr->type);
                    j += 2;
                }
                curr = aux;
            }
            if (curr == NULL)
            {
                sprintf(ans, "\"%s\"", s);
                printf("%s", ans);
                return ans;
            }
        }
    }
    ans[j] = 0;
    sprintf(ans + j, "\"");
    if (name[0] != 0)
        sprintf(ans + j, "\",%s", name);

    printf("\n%s\n", ans);
    return ans;
}