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

    FILE *clux_file = fopen(input_file_path, "r");          //Read clux file
    FILE *intermediate_file = fopen("intermediate.c", "w"); //Write intermediate code file

    if (clux_file == NULL)
    {
        perror("Error opening clux file");
        exit(1);
    }

    if (intermediate_file == NULL)
    {
        perror("Error creating intermediate code file");
        exit(1);
    }

    yyparse(); //Parse clux file

    generateIntermediateCodeFile();

    fclose(clux_file);
    fclose(intermediate_file);

    return 0;
}

extern void generateIntermediateCodeFile()
{
    //generate C code to compile with gcc and obtain .out
    //fprintf("intermdiate.c", "#include <stdio.h>");
    char buffer[50];
    sprintf(buffer, "gcc -S intermediate.c -o intermediate.s"); //generate Asm

    if (system(buffer) != 0)
    {
        fprintf(stderr, "Error while compiling intermediate file");
        exit(1);
    }

    // sprintf(buffer, "gcc -c intermediate.s -o compiled"); //compiled file generated
