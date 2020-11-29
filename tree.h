#ifndef TREE_H
#define TREE_H
#include <stdbool.h>

/********************************************************
** STRUCTURES
*********************************************************/

/* Structure for GENERAL data types */
typedef enum KIND
{
    KIND_STRING,
    KIND_INT,
    KIND_CHAR,
    KIND_ARRAY_INT,
    KIND_ARRAY_STRING,
    KIND_ARRAY_CHAR
} KIND;

/* Structure for SPECIFIC data types */
typedef enum DATA_TYPE
{
    DATA_TYPE_NONE,
    UNDECLARED_VAR,
    STRING_LITERAL,
    INT_LITERAL,
    CHAR_LITERAL,
    STRING_VAR,
    INT_VAR,
    CHAR_VAR,
    ARRAY_INT_VAR,
    ARRAY_CHAR_VAR,
    ARRAY_STRING_VAR,
} DATA_TYPE;

/* Node structure for storing information */
typedef struct node
{
    char *information;
    struct node *next;
    bool free;

} node;

/* Main structure for storing nodes, saves first and last in order to insert */
typedef struct code
{
    node *first;
    node *last;
    bool error;
} code;

/* Auxiliary strcutre for storing var info */
typedef struct var
{
    char *name;
    char type[3]; // %d o %s
    KIND kind;
    int amount;
    bool constant;

    struct var *next;
    struct var *prev;
} var;

/* Structure for acting like a Symbol Table */
typedef struct variables
{
    var *first;
    var *last;

} variables;

/* Auxiliary strcutre for storing functions info */
typedef struct funct
{
    char *name;
    KIND kind;
    KIND args[50];
    int args_count;
    struct funct *next;
    bool defined;
} funct;

/* Structure for acting like a Functions Symbol Table */
typedef struct functions
{
    funct *first;
    funct *last;

} functions;

/********************************************************
** VARIABLES
*********************************************************/

/* Auxiliary variables, corresponding to program */
extern code program;
extern variables var_list;
extern functions function_list;

/********************************************************
** FUNCTIONS
*********************************************************/

/* Starts list for program */
void initialize();

/* Adds a new node to the program */
void add(char *information, bool free);

/* Frees all allocked resources */
void freeResources(bool error);

/* Declares a new variable and its type */
void addVar(char *name, KIND kind, int size,bool constant);

/* Adds a new function, its return type and arguments */
void addFunction(char *name, KIND kind, char *args);

/* Declares a new function, its return type and arguments */
void declareFunction(char *name, KIND kind, char *args);

/* Parses data input por printf() format */
char *printfParser(char *s);

/* Checks if given array has enough space */
bool enoughSpace(const char *str, int amount);

/* Checks if initialization of array has more than required elements */
bool array_is_incorrect(const char *str, int amount);

/* Returns true if variable belongs to a certain type */
bool isOfKind(char *s, KIND kind);

/* Uses starting symbols in order to guess the data type */
unsigned int guess_data_type(char *s);

/* Checks if given parameters are comparable for operators */
bool are_comparable(char *s1, char *s2);

/* Checks function return type */
bool functionReturnsKind(char *s, KIND kind);

/* Checks if the called variable was previously declared */
bool checkIfVarExists(char *name);

/* Checks if the called function was previously declared */
bool checkIfFunctionExists(char *name);

/* Checks if given arguments for function are OK */
bool checkArgsOk(char *name, char *args);

/* Free allocked resourced for variables */
void freeVars(bool finished);

/* Checks if return type accords to given KIND */
bool checkReturnType(char *program, KIND kind);

/* Check if two arrays are compatible */
bool compatibleArray(char *v1, char *v2, int number);

/* Check if variable is array of a certain type and length */
bool correctArray(char *name, KIND kind, int size);

/* Checks if variable is an array */
bool isAnArray(char * name);

/* Checks if two arrays are of the same type in order to do a[i] = a[kj] */
bool compatibleArrayAssignment(char *v1, char *v2, int n1, int n2);

/* Checks if an alpha is actually a constant*/
bool isConstant(char *name);
#endif