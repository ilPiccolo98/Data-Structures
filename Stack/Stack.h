#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define LENGTH 100
#include <stdbool.h>

typedef struct Stack
{
    int items[LENGTH];
    int length;
    int top;
}
Stack;

//Inizializza uno stack
bool init_stack(Stack *stack, int length);
//Restituisce true se uno stack e' vuoto, false altrimenti
bool empty_stack(Stack *stack);
//Restituisce true se uno stack e' pieno, false altrimenti
bool full_stack(Stack *stack);
//Inserisce un'elemento in cima a uno stack
bool push_stack(Stack *stack, int item);
//Elimina il primo elemento in cima a uno stack
bool pop_stack(Stack *stack);
//Restituisce il primo elemento in cima a uno stack
int top_stack(Stack *stack);
//Restituisce la grandezza di uno stack
int length_stack(Stack *stack);

#endif // STACK_H_INCLUDED
