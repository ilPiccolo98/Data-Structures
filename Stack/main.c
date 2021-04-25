#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
    Stack s;
    init_stack(&s, 10);
    int i;
    for(i = 0; i != (length_stack(&s) + 1); ++i)
        if(!push_stack(&s, i))
            puts("Stack pieno");
    for(i = 0; i != (length_stack(&s) + 1); ++i)
    {
        if(!empty_stack(&s))
        {
            printf("Valore in cima allo stack: %d\n", top_stack(&s));
            pop_stack(&s);
        }
        else
            puts("Stack vuoto");
    }
    return 0;
}
