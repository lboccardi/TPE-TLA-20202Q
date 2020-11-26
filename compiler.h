#ifndef COMPILER_H
#define COMPILER_H

extern FILE *yyin; //Set yyin for yacc to parse file

/* Generates Assembly code */
extern void generateIntermediateCodeFile();
#endif