/* El compiler recibe una dirección donde está el archivo para leer el programa (file.clux)
    fopen
    read (file.clux)
    genera C como lenguaje intermedio
    que con compiler.asm lo convierto en asm y genero el ejecutable
    Proveer un mecanismo de entrada de datos: STDIN.
    Proveer un mecanismo de salida de datos:  STDOUT.
 */
#include "compiler.h"
#include <stdio.h>
#include "y.tab.h"

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

    FILE *intermediate_file = fopen("intermediate.c", "w"); //Write intermediate code file
    if (intermediate_file == NULL)
    {
        perror("Error creating intermediate code file");
        exit(1);
    }

    yyparse(); //Parse clux file

    generateIntermediateCodeFile();

    fclose(clux_file);
    fclose(yyin);
    fclose(intermediate_file);

    return 0;
}

extern void generateIntermediateCodeFile()
{

    //fprintf("intermdiate.c", "#include <stdio.h>");
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
}
