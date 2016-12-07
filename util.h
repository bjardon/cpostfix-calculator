//
// Created by bruno on 1/06/16.
//

#ifndef STACKEXPRESSIONSOLVER_UTIL_H
#define STACKEXPRESSIONSOLVER_UTIL_H

#include <ctype.h>
#include "stdio.h"
#include "stdlib.h"
#include "stdio_ext.h"
#include "stack.h"
#include "varlist.h"

typedef char * String;

void string(String * s);
void removespaces(String s);

void openfile(FILE ** file, String filename);
void getinput(FILE ** file, String * input);
void getvalues(String expr, _VarList *list);
void process(Stack stack, String expr, _VarList * list);
int operate(int a, int b, char op);

void string(String * s)
{
    *s = (String)malloc(sizeof(String) * 255);
}

void removespaces(String s) {
    String a;
    string(&a);
    int i, count = 0;
    for (i = 0; i < strlen(s); i++) {
        if (*(s + i) == 32)
            count++;
        else
            *(a + i - count) = *(s + i);
    }
    *(a + i) = 0;
    strcpy(s, a);
}

void openfile(FILE ** file, String filename)
{
    *file = fopen(filename, "r+");
    if(!(*file))
    {
        printf("\n   ERROR!:\n   Ocurrió un error al intentar leer el archivo. El archivo '%s' no se encontró o no se cuenta con suficientes permisos para abrirlo. Asegúrese de que incluyó la extensión del archivo.\n\n", filename);
        exit(-1);
    }
}

void getinput(FILE ** file, String * input)
{
    __fpurge(stdin);
    fgets(*input, 1000, *file);
    removespaces(*input);
}

void getvalues(String expr, _VarList *list)
{
    int i, var;
    char c;
    printf("\nIndique el valor de las siguientes variables:\n");
    for (i = 0; i < strlen(expr); i++) {
        c = *(expr + i);
        if(isalpha(c)) {
            if(!has(list, c)) {
                printf("   %c: > ", c);
                __fpurge(stdin);
                scanf("%d", &var);
                add(list, c, var);
            }
        }
    }
}

void process(Stack stack, String expr, _VarList * list)
{
    int i;
    int a, b;
    char e;
    for (i = 0; i < strlen(expr); ++i) {
        e = *(expr + i);
        if(isalpha(e)) {
            push(stack, seek(list, e)->value);
        }
        else
        {
            b = pop(stack)->value;
            a = pop(stack)->value;
            push(stack, operate(a, b, e));
        }
    }
}

int operate(int a, int b, char op)
{
    switch (op){
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;

    }
}

#endif //STACKEXPRESSIONSOLVER_UTIL_H
