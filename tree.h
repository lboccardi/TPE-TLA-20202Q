#ifndef TREE_H
#define TREE_H
#include <stdbool.h>

typedef enum KIND{
    KIND_STRING,
    KIND_INT,
    KIND_CHAR,
    KIND_ARRAY_INT,
    KIND_ARRAY_STRING,
    KIND_ARRAY_CHAR
}KIND;

typedef enum DATA_TYPE {
    DATA_TYPE_NONE,
    UNDECLARED_VAR,
    STRING_LITERAL,
    INT_LITERAL,
    CHAR_LITERAL,
    STRING_VAR,
    INT_VAR, 
    CHAR_VAR
} DATA_TYPE;

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
    KIND kind;
    int amount;

    struct var *next;
} var;

typedef struct variables
{
    var *first;
    var *last;

} variables;

typedef struct funct
{
    char *name;
    KIND kind;
    KIND args[50];
    int args_count;
    struct funct *next;
} funct;

typedef struct functions
{
    funct *first;
    funct *last;

} functions;
extern code program;
extern variables var_list;
extern functions function_list;


void initialize();

void add(char *information, bool free);

void freeResources(bool error);

void addVar(char *name, KIND kind,int size);

void addFunction(char *name, KIND kind,char * args);

char *printfParser(char *s);

bool enoughSpace(const char* str, int amount);

bool array_is_incorrect (const char* str, int amount);

bool isOfKind(char *s,KIND kind);

unsigned int guess_data_type(char * s);

bool are_comparable(char * s1, char * s2);

bool functionReturnsKind(char * s, KIND kind);

bool checkIfVarExists(char * name); 
bool checkIfFunctionExists(char * name); 
bool checkArgsOk(char*name,char*args);
void freeVars();
bool checkReturnType(char * program, KIND kind);
bool compatibleArray(char * v1,char * v2,int number);
bool correctArray(char * name,KIND kind,int size);
#endif