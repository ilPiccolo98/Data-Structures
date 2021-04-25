#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main()
{
    Queue queue;
    if(!init_queue(&queue, 10))
        puts("False");
    int i;
    for(i = 0; i != (length_queue(&queue) + 1); ++i)
        if(!enqueue(&queue, i))
            puts("Coda piena");
    for(i = 0; i != (length_queue(&queue) + 1); ++i)
    {
        if(!empty_queue(&queue))
        {
            printf("%d\n", tail_queue(&queue));
            dequeue(&queue);
        }
        else
            puts("Coda vuota");
    }
    return 0;
}
