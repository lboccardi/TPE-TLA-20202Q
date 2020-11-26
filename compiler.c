/* El compiler recibe una dirección donde está el archivo para leer el programa (file.clux)
    fopen
    read (file.clux)
    genera C como lenguaje intermedio
    que con compiler.asm lo convierto en asm y genero el ejecutable
    Proveer un mecanismo de entrada de datos: STDIN.
    Proveer un mecanismo de salida de datos:  STDOUT.
 */
#include "compiler.h"
#include <stdlib.h>
#include "y.tab.h"
#include "tree.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        fprintf(stderr, "Please enter the file to compile");
    }

    char *input_file_path = argv[1];

    FILE *clux_file = fopen(input_file_path, "r"); //Read clux file
    if (clux_file == NULL)
    {
        perror("Error opening clux file");
        exit(1);
    }

    yyin = clux_file;

    yyparse(); //Parse clux file
    if (!program.error)
    {
        freeResources(false);
        FILE *intermediate_file = fopen("intermediate.c", "w"); //Write intermediate code file
        if (intermediate_file == NULL)
        {
            perror("Error creating intermediate code file");
            exit(1);
        }
        generateIntermediateCodeFile(intermediate_file);
        compile();
        fclose(intermediate_file);
    }

    fclose(yyin);

    return 0;
}

void generateIntermediateCodeFile(FILE *intermediate_file)
{
    fprintf(intermediate_file, "#include <stdio.h> \n %s", program.first->information);
}

void compile()
{
    char generateAsm[100];
    sprintf(generateAsm, "gcc -S intermediate.c -o intermediate.s"); //generate Asm

    if (system(generateAsm) != 0)
    {
        fprintf(stderr, "Error while generatig Assembler code from intermediate file");
        exit(1);
    }

    char compileAsm[100];
    sprintf(compileAsm, "gcc -c intermediate.s -o compiled"); //compiled file generated
    if (system(compileAsm) != 0)
    {
        fprintf(stderr, "Error while compiling intermediate file");
        exit(1);
    }
    char executableAsm[100];
    sprintf(executableAsm, "gcc compiled.o -o compiled"); //executable file generated
    if (system(executableAsm) != 0)
    {
        fprintf(stderr, "Error while exec intermediate file");
        exit(1);
    }
}
