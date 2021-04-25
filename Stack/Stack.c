#include "Stack.h"

//Inizializza uno stack
bool init_stack(Stack *stack, int length)
{
    if(length <= LENGTH)
    {
        stack->length = length;
        stack->top = -1;
        return true;
    }
    return false;
}

//Restituisce true se uno stack e' vuoto, false altrimenti
bool empty_stack(Stack *stack)
{
    if(stack->top == -1)
        return true;
    return false;
}

//Restituisce true se uno stack e' pieno, false altrimenti
bool full_stack(Stack *stack)
{
    if(stack->top == (stack->length - 1))
        return true;
    return false;
}

//Inserisce un'elemento in cima a uno stack
bool push_stack(Stack *stack, int item)
{
    if(!full_stack(stack))
    {
        ++stack->top;
        stack->items[stack->top] = item;
        return true;
    }
    return false;
}

//Elimina il primo elemento in cima a uno stack
bool pop_stack(Stack *stack)
{
    if(!empty_stack(stack))
    {
        --stack->top;
        return true;
    }
    return false;
}

//Restituisce il primo elemento in cima a uno stack
int top_stack(Stack *stack)
{
    return stack->items[stack->top];
}

//Restituisce la grandezza di uno stack
int length_stack(Stack *stack)
{
    return stack->length;
}


