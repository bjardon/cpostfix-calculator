//
// Created by bruno on 1/06/16.
//

#ifndef STACKEXPRESSIONSOLVER_VARLIST_H_H
#define STACKEXPRESSIONSOLVER_VARLIST_H_H

#include "string.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct _variable
{
    char symbol;
    int value;
    struct _variable * next;
} _Variable;
typedef _Variable * Variable;

typedef struct _list
{
    struct _variable * first;
} _VarList;

typedef _VarList * VarList;

// Function declarations
void add(VarList list, char name, int age);
Variable seek(VarList list, char name);
int has(VarList list, char symbol);
int listisempty(VarList list);

void add(VarList list, char name, int age)
{
    Variable element;
    element = (Variable)malloc(sizeof(_Variable));
    element->symbol = name;
    element->value = age;
    if(!listisempty(list))
    {
        Variable aux;
        aux = list->first;
        while(aux->next)
            aux = aux->next;
        element->next = aux->next;
        aux->next = element;
    } else {
        element->next = list->first;
        list->first = element;
    }
}

Variable seek(VarList list, char name)
{
    Variable aux = list->first;
    int i = 0;
    while(aux)
    {
        if(aux->symbol == name)
            return aux;
        i++;
        aux = aux->next;
    }
    return NULL;
}

int has(VarList list, char symbol)
{
    if(seek(list, symbol))
        return 1;
    return 0;
}

int listisempty(VarList list)
{
    if(list->first != NULL)
        return 0;
    return 1;
}

#endif //STACKEXPRESSIONSOLVER_VARLIST_H_H
