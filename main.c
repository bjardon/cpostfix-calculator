#include <string.h>
#include "util.h"
#include "stack.h"

int main(int argc, const char * argv[])
{
    String filename, input;
    string(&filename);
    string(&input);
    FILE * file;
    Stack stack = (Stack)malloc(sizeof(Stack));
    VarList list = (_VarList *)malloc(sizeof(_VarList));

    if(argc > 1) strcpy(filename, argv[1]);
    else
    {
        printf("\nIndique el nombre del archivo a leer \n(por favor incluya la extensión)\n   > ");
        __fpurge(stdin);
        scanf("%[^\n]s", filename);
    }

    openfile(&file, filename);
    getinput(&file, &input);
    printf("\nExpresion a evaluar: %s\n", input);
    getvalues(input, list);
    process(stack, input, list);
    printf("\nEvaluacion terminada\n   El resultado de la operacion es: %d\n", pop(stack)->value);
}