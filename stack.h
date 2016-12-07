//
// Created by bruno on 1/06/16.
//

#ifndef STACKEXPRESSIONSOLVER_STACK_H
#define STACKEXPRESSIONSOLVER_STACK_H

#include "stdlib.h"
#include "stdio.h"

/** Data type definitions */
typedef struct _node {
    int value;
    struct _node *next;
} _Node;

typedef _Node *Node;
typedef _Node *_Stack;
typedef _Node **Stack;

/** Method prototypes **/
Stack stackinit(Stack s);
void push(Stack s, int v);
Node pop(Stack s);
Node top(Stack s);

int isempty(_Stack s);
int count(_Stack s);

void flushstack(Stack s);
void showall(_Stack s);

/**
	* Initializes a given _Stack
	*/
Stack stackinit(Stack stack){
    *stack = NULL;
    return stack;
}

/**
	* Inserts a node to the stack
	*/
void push(Stack stack, int v)
{
    Node newnode;
    newnode = (Node)malloc(sizeof(_Node));
    newnode->value = v;

    newnode->next = *stack;
    *stack = newnode;
}

Node pop(Stack stack)
{
    if(isempty(*stack)){
        return NULL;
    }
    else
    {
        Node aux = *stack;
        *stack = aux->next;
        return aux;
    }
}

Node top(Stack stack)
{
    return *stack;
}

/**
	* Checks if the stack is empty
	*/
int isempty(_Stack stack)
{
    if(stack == NULL)
    {
        return 1;
    }
    return 0;
}

int count(_Stack stack)
{
    Node aux;
    aux = stack;
    int i = 0;
    while (aux)
    {
        aux = aux->next;
        i++;
    }
    return i;
}

/**
	* Removes all elements in the stack
	*/
void flushstack(Stack stack)
{
    Node node;

    while(*stack)
    {
        node = *stack;
        *stack = node->next;
        free(node);
    }
}

/**
	* Prints to stdout all nodes, indicating its HEX RAM address
	*/
void showall(_Stack stack)
{
    Node node = stack;

    if(isempty(stack))
    {
        printf("Pila vacia\n");
    }
    else
    {
        int i = 0;
        while(node)
        {
            printf("Nodo #%d en RAM{%p}: %d\n", i, node, node->value);
            node = node->next;
            i++;
        }
        printf("\n");
    }
}

#endif //STACKEXPRESSIONSOLVER_STACK_H
