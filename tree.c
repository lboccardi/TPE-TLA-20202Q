#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    var_list.first = NULL;
    var_list.last = NULL;
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

void addVar(char *name, KIND kind, int size)
{
    var *aux = malloc(sizeof(var));
    /** save type **/
    char *aux_type;
    if (kind == KIND_INT || kind == KIND_ARRAY_INT)
    {
        aux_type = "%d";
    }
    else if (kind == KIND_STRING || kind == KIND_ARRAY_STRING)
    {
        aux_type = "%s";
    }
    else
    {
        aux_type = "%c";
    }

    strcpy(aux->type, aux_type);
    /** save name and kind**/
    aux->name = name;
    aux->kind = kind;
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

void addArgs(funct *f, char *args)
{
    int curr_amount = 0;
    if (*args == 0)
    {
        f->args_count = 0;
        return;
    }
    char * curr = args;
    while (curr != NULL){
        if(strncmp(args,"int",strlen("int"))==0){
            f->args[curr_amount++] = KIND_INT;
        }else if(strncmp(args,"char *",strlen("char *"))==0){
            f->args[curr_amount++] = KIND_STRING;
        }
        else
        {
            f->args[curr_amount++] = KIND_CHAR;
        }
        curr = strchr(args, ',');
        args = curr + 2;
    }
    f->args_count = curr_amount;
}

void addFunction(char *name, KIND kind, char *args)
{
    funct *aux = malloc(sizeof(funct));
    /** save name and kind**/
    aux->name = name;
    aux->kind = kind;
    addArgs(aux, args);

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
    bool var_flag = false;
    char var_name[strlen(s)];
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
                if (s[i] == '_')
                {
                    /* Salteo el '_' */
                    i++;
                    array_index = 0;
                    /* Apertura */
                    name[k++] = '[';
                    /* Me guardo los digits */
                    if (isdigit(s[i]))
                    {
                        while (isdigit(s[i]))
                        {
                            name[k++] = s[i];
                            array_index = 10 * array_index + s[i++] - '0';
                        }
                    }
                    else
                    {
                        int var_index = 0;
                        while (s[i] != '\'')
                        {
                            name[k++] = s[i];
                            var_name[var_index++] = s[i++];
                        }
                        var_name[var_index] = '\0';
                        var_flag = true;
                    }

                    /* Cierre */
                    name[k++] = ']';
                }
                else
                {
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
                if (strcmp(curr->name, name + pointer) == 0)
                {
                    if (curr->kind == KIND_ARRAY_CHAR)
                    {
                        strcpy(ans + j, "%s");
                    }
                    else
                    {
                        strcpy(ans + j, curr->type);
                    }
                    j += 2;
                    flag = false;
                }
                else
                {
                    /* Si falla, es porque estoy en un caso arr[N] chequear el strtok */
                    int token_aux_len = strlen(name + pointer) + 1;
                    char token_aux[token_aux_len];
                    strcpy(token_aux, name + pointer);
                    char * token = strtok(token_aux, "[");
                    if (token != NULL) {
                        if (strcmp(curr->name, token) == 0 && (curr->kind == KIND_ARRAY_INT ||curr->kind == KIND_ARRAY_STRING || curr->kind == KIND_ARRAY_CHAR)) {
                            if (var_flag == false) {
                                if (array_index >= curr->amount && curr->amount!=-1) {
                                    free(ans);
                                    return NULL;
                                }
                            }
                            else
                            {
                                if (!checkIfVarExists(var_name) || !isOfKind(var_name, KIND_INT))
                                {
                                    free(ans);
                                    return NULL;
                                }
                            }

                            strcpy(ans + j, curr->type);
                            j += 2;
                            flag = false;
                        }
                    }
                }
                curr = curr->next;
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

bool isOfKind(char *s, KIND kind)
{
    var *curr = var_list.first;
    while (curr != NULL)
    {
        if (strcmp(curr->name, s) == 0)
        {
            if (curr->kind == kind)
            {
                return true;
            }
            return false;
        }
        curr = curr->next;
    }
    return false;
}

unsigned int guess_data_type(char *s)
{
    switch (*s)
    {
    /* Si el primer caracter indica que es un String */
    case '\'':
        return CHAR_LITERAL; // HERE
    case '\"':
        return STRING_LITERAL;
    /* Si el primer caracter es un dígito */
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return INT_LITERAL;
    case '(':
        return DATA_TYPE_NONE;
    /* Si no, era una variable o era otra comparación del estilo "(? ? ?)" */
    default:
        if (checkIfVarExists(s))
        {
            if (isOfKind(s, KIND_STRING))
            {
                return STRING_VAR;
            }
            if (isOfKind(s, KIND_INT))
            {
                return INT_VAR;
            }
            if (isOfKind(s, KIND_CHAR))
            {
                return CHAR_VAR;
            }
        }
        return UNDECLARED_VAR;
    }
}

bool are_comparable(char *s1, char *s2)
{
    unsigned int v1, v2;
    /* Si ambas variables eran tipos de dato atómicos */
    v1 = guess_data_type(s1);
    v2 = guess_data_type(s2);

    if (v1 == UNDECLARED_VAR || v2 == UNDECLARED_VAR)
    {
        return false;
    }

    if (v1 != DATA_TYPE_NONE && v2 != DATA_TYPE_NONE)
    {
        switch (v1)
        {
        /* String se comapra a String */
        case STRING_LITERAL:
        case STRING_VAR:
            return (v2 == STRING_LITERAL || v2 == STRING_VAR);
        /* Int se compara con Int */
        case INT_LITERAL:
        case INT_VAR:
            return (v2 == INT_LITERAL || v2 == INT_VAR);
        case CHAR_VAR:
        case CHAR_LITERAL:
            return (v2 == CHAR_VAR || v2 == CHAR_LITERAL);
        }
        /* Code Unreachable */
        return false;
    }

    /* Si llega acá, alguna de las dos era una comparación, por ende son comparables */
    return true;
}

bool array_is_incorrect(const char *str, int amount)
{
    char *curr = strchr(str, ',');
    int curr_amount = 0;
    while (curr != NULL)
    {
        curr_amount++;
        if (curr_amount > amount)
        {
            return true;
        }
        curr = strchr(curr + 1, ',');
    }

    if ((curr_amount + 1) != amount)
    {
        return true;
    }

    return false;
}
bool enoughSpace(const char *s, int amount)
{
    var *curr = var_list.first;
    while (curr != NULL)
    {
        if (strcmp(curr->name, s) == 0)
        {
            if (curr->amount > amount || curr->amount == -1)
            {
                return true;
            }
            return false;
        }
        curr = curr->next;
    }
    return false;
}

bool functionReturnsKind(char *s, KIND kind)
{

    char string[strlen(s) + 1];
    strcpy(string, s);

    char *p = strchr(string, '(');
    *p = 0;
    funct *curr = function_list.first;
    while (curr != NULL)
    {
        if (strcmp(curr->name, string) == 0)
        {
            if (curr->kind == kind)
            {
                return true;
            }
            return false;
        }
        curr = curr->next;
    }
    return false;
}

bool checkIfVarExists(char *name)
{
    var *curr = var_list.first;
    while (curr != NULL)
    {

        if (strcmp(curr->name, name) == 0)
        {
            return true;
        }

        curr = curr->next;
    }
    return false;
}
bool checkIfFunctionExists(char *name)
{
    funct *curr = function_list.first;
    while (curr != NULL)
    {

        if (strcmp(curr->name, name) == 0)
        {
            return true;
        }

        curr = curr->next;
    }
    return false;
}
bool checkArgsOk(char *name, char *args)
{
    funct *curr = function_list.first;
    while (curr != NULL)
    {
        if (strcmp(curr->name, name) == 0)
        {
            char *p2 = strchr(args, ',');
            if (p2 != NULL && curr->args_count == 0)
            {
                return false;
            }
            char *p1 = args;
            int i;
            for (i = 0; i < curr->args_count; i++)
            {
                if (*p1 == 0)
                {
                    return false;
                }
                if (p2 == NULL)
                {
                    p2 = strchr(p1, 0);
                }
                int copy_size = p2 - p1;
                char aux[strlen(args) + 1];
                strncpy(aux, p1, copy_size);
                aux[copy_size] = 0;
                unsigned int type = guess_data_type(aux);
                if (type == UNDECLARED_VAR || type == DATA_TYPE_NONE)
                {
                    return false;
                }
                if ((type == INT_LITERAL || type == INT_VAR) && curr->args[i] != KIND_INT)
                {
                    return false;
                }
                if ((type == STRING_LITERAL || type == STRING_VAR) && curr->args[i] != KIND_STRING)
                {
                    return false;
                }
                if ((type == CHAR_VAR || type == CHAR_LITERAL) && curr->args[i] != KIND_CHAR)
                {
                    return false;
                }

                if (*p2 == 0)
                {
                    p1 = p2;
                }
                else
                {
                    p1 = p2 + 1;
                    p2 = strchr(p1, ',');
                }
            }
            if (i == curr->args_count && *p1 == 0)
            {
                return true;
            }
            return false;
        }
        curr = curr->next;
    }
    return false;
}
bool checkReturnType(char *program, KIND kind)
{
    int size = strlen("return ");
    char *p = strstr(program, "return");
    while (p != NULL)
    {
        char *c = p + size;
        char *c2 = strchr(c, ';');
        int copy_size = c2 - c;
        char aux[copy_size + 1];
        strncpy(aux, c, copy_size);
        aux[copy_size] = 0;
        unsigned int type = guess_data_type(aux);
        if (type == UNDECLARED_VAR)
        {
            return false;
        }
        if ((type == INT_LITERAL || type == INT_VAR) && kind != KIND_INT)
        {
            return false;
        }
        if ((type == STRING_LITERAL || type == STRING_VAR) && kind != KIND_STRING)
        {
            return false;
        }
        if ((type == CHAR_VAR || type == CHAR_LITERAL) && kind != KIND_CHAR)
        {
            return false;
        }
        p = strstr(c, "return");
    }
    return true;
}
bool compatibleArray(char *v1, char *v2, int number)
{

    if (number != 0 && !enoughSpace(v2, number))
    {
        return false;
    }
    if (isOfKind(v2, KIND_ARRAY_INT) && isOfKind(v1, KIND_INT))
    {
        return true;
    }
    if (isOfKind(v2, KIND_ARRAY_STRING) && isOfKind(v1, KIND_STRING))
    {
        return true;
    }
    if (isOfKind(v2, KIND_ARRAY_CHAR) && isOfKind(v1, KIND_CHAR))
    {
        return true;
    }
    return false;
}

bool compatibleArrayAssignment(char *v1, char *v2, int n1, int n2)
{

    if (!enoughSpace(v2, n2) || !enoughSpace(v1, n1))
    {
        return false;
    }

    if (isOfKind(v2, KIND_ARRAY_INT) && isOfKind(v1, KIND_ARRAY_INT))
    {
        return true;
    }
    if (isOfKind(v2, KIND_ARRAY_STRING) && isOfKind(v1, KIND_ARRAY_STRING))
    {
        return true;
    }
    if (isOfKind(v2, KIND_ARRAY_CHAR) && isOfKind(v1, KIND_ARRAY_CHAR))
    {
        return true;
    }
    return false;
}

bool correctArray(char *name, KIND kind, int size)
{
    var *v = var_list.first;
    while (v != NULL)
    {
        if (strcmp(v->name, name) == 0)
        {
            if (v->kind == kind && v->amount > size)
            {
                return true;
            }
            return false;
        }
        v = v->next;
    }
    return false;
}