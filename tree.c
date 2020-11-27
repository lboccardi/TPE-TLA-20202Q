#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

code program;
variables var_list;
functions function_list; 

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
void freeFuncts()
{
    funct *curr = function_list.first;
    while (curr != NULL)
    {
        funct *aux = curr->next;
        free(curr);
        curr = aux;
    }
}
void freeResources(bool error)
{
    node *curr = program.first;
    freeVars();
    freeFuncts();
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

void addVar(char *name, KIND kind,int size)
{
    var *aux = malloc(sizeof(var));
    /** save type **/
    char *aux_type;
    if (kind == KIND_INT || kind == KIND_ARRAY_INT)
    {
        aux_type = "%d";
    }
    else
    {
        aux_type = "%s";
    }
    strcpy(aux->type, aux_type);
    /** save name and kind**/
    aux->name = name;
    aux->kind=kind;
    aux->amount = size;
    
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
// void addArgs(funct * f, char * args){
//     char *curr = strchr(args,',');
//     int curr_amount = 0;
//     while (curr != NULL){
//         if(strncmp(args,"int",3)==0){
//             f->args[curr_amount++] = KIND_INT;
//         }else{
//             f->args[curr_amount++] = KIND_STRING;
//         }
//         curr = strchr(curr+1,',');
//     }
    
//     if ((curr_amount+1) != amount ) {
//         return true;
//     }

//     return false;
// }
void addFunction(char *name, KIND kind,int size){
    funct *aux = malloc(sizeof(funct));
    /** save name and kind**/
    aux->name = name;
    aux->kind=kind; 
    //addArgs(aux,args);
    
    if (function_list.first == NULL)
    {
        function_list.first = aux;
    }
    else
    {
        function_list.last->next = aux;
    }
    function_list.last = aux;
    aux->next = NULL;
}

char *printfParser(char *s)
{ /** hola ''a12b5'' como estas --> \"hola %d como estas\",a12b5  **/

    char *ans = malloc(strlen(s) * 2 + 5);

    ans[0] = '\"';

    int i = 0, j = 1, k = 0, array_index = 0;
    char name[strlen(s)];
    name[0] = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '[' || s[i] == ']')
        {
            i++;
        }
        else if (s[i] != '\'')
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
                /* Si la variable era un array */
                if (s[i] == '_') {
                    /* Salteo el '_' */
                    i++;
                    array_index = 0;
                    /* Apertura */
                    name[k++] = '[';
                    /* Me guardo los digits */
                    while(s[i] >= '0' && s[i] <= '9') {
                        name[k++] = s[i];
                        array_index = 10*array_index + s[i++] - '0'; 
                    }
                    /* Cierre */
                    name[k++] = ']';
                } else {
                    /* Si no es un array */
                    name[k++] = s[i++];
                }
            }
            i++;
            name[k] = 0;
            var *curr = var_list.first;
            bool flag = true;
            while (curr != NULL && flag)
            {
                var *aux = curr->next;

                if (strcmp(curr->name, name + pointer) == 0)
                {
                    strcpy(ans + j, curr->type);
                    j += 2;
                    flag = false;
                } else {
                  /* Si falla, es porque estoy en un caso arr[N] chequear el strtok */
                    int token_aux_len = strlen(name + pointer)+1;
                    char token_aux[token_aux_len];
                    strcpy(token_aux, name + pointer);
                    char * token = strtok(token_aux, "[");
                    if (token != NULL) {
                        if (strcmp(curr->name, token) == 0 && (curr->kind == KIND_ARRAY_INT ||curr->kind == KIND_ARRAY_STRING)) {
                            if (array_index >= curr->amount) {
                                free(ans);
                                return NULL;
                            }
                            strcpy(ans + j, curr->type);
                            j += 2;
                            flag = false;
                        }  
                    } 
                }
                curr = aux;
            }
            if (flag)
            {
                free(ans);
                return NULL;
            }
        }
    }
    ans[j] = 0;
    sprintf(ans + j, "\"");
    if (name[0] != 0)
        sprintf(ans + j, "\",%s", name);

    return ans;
}

bool isOfKind(char *s,KIND kind)
{
    var *curr = var_list.first;
    while (curr != NULL)
    {
        var *aux = curr->next;

        if (strcmp(curr->name, s) == 0)
        {
            if (curr->kind == kind)
            {
                return true;
            }
            return false;
        }
        curr = aux;
    }
    return false;
}

unsigned int guess_data_type(char * s) {
    switch(*s) {
        /* Si el primer caracter indica que es un String */
        case '\'':
        case '\"':
            return STRING_LITERAL;
        /* Si el primer caracter es un dígito */    
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            return INT_LITERAL;
        /* Si no, era una variable o era otra comparación del estilo "(? ? ?)" */
        default:
            if(isOfKind(s, KIND_STRING))    { return STRING_VAR; }
            if(isOfKind(s, KIND_INT))       { return INT_VAR; }
            return DATA_TYPE_NONE;
    }
}

bool are_comparable(unsigned int v1, unsigned int v2) {
    switch(v1) {
        case STRING_LITERAL:
        case STRING_VAR:
            return (v2 == STRING_LITERAL || v2 == STRING_VAR);
        case INT_LITERAL:
        case INT_VAR:
            return (v2 == INT_LITERAL || v2 == INT_VAR);
        default:
            break;    
    }
    return false;
}

bool array_is_incorrect (const char* str, int amount) {
    char *curr = strchr(str,',');
    int curr_amount = 0;
    while (curr != NULL){
        curr_amount++;
        if (curr_amount > amount) {
            return true;
        }
        curr = strchr(curr+1,',');
    }
    
    if ((curr_amount+1) != amount ) {
        return true;
    }

    return false;
}
bool enoughSpace(const char* s, int amount){
     var *curr = var_list.first;
    while (curr != NULL)
    {
        var *aux = curr->next;

        if (strcmp(curr->name, s) == 0)
        {
            if (curr->amount > amount)
            {
                return true;
            }
            return false;
        }
        curr = aux;
    }
    return false;
}

bool functionReturnsKind(char * s, KIND kind){
    
    char string[strlen(s)+1];
    strcpy(string,s);

    char * p = strchr(string,'(');
    *p = 0;
    funct *curr = function_list.first;
    while (curr != NULL)
    {
        funct *aux = curr->next;

        if (strcmp(curr->name, string) == 0)
        {
            if (curr->kind == kind)
            {
                return true;
            }
            return false;
        }
        curr = aux;
    }
    return false;
}