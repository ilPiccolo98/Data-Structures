#include "Queue.h"

//Inizializza una coda
bool init_queue(Queue *queue, int length)
{
    if(length <= LENGTH)
    {
        queue->length = length;
        queue->head = 0;
        queue->tail = 0;
        queue->cout_items = 0;
        return true;
    }
    return false;
}

//Restituisce true se una coda e' vuota, false altrimenti
bool empty_queue(Queue *queue)
{
    if(!queue->cout_items)
        return true;
    return false;
}

//Restituisce true se una coda e' piena, false altrimenti
bool full_queue(Queue *queue)
{
    if(queue->cout_items == queue->length)
        return true;
    return false;
}

//Restituisce la lunghezza della coda
int length_queue(Queue *queue)
{
    return queue->length;
}

//Aggiunge un elemento in fondo a una coda
bool enqueue(Queue *queue, int item)
{
    if(!full_queue(queue))
    {
        queue->items[queue->head] = item;
        queue->head = (queue->head + 1) % length_queue(queue);
        ++queue->cout_items;
        return true;
    }
    return false;
}

//Elimina il prima elemento di una coda
bool dequeue(Queue *queue)
{
    if(!empty_queue(queue))
    {
        queue->tail = (queue->tail + 1) % length_queue(queue);
        --queue->cout_items;
        return true;
    }
    return false;
}

//Restituisce il primo elemento di una coda
int tail_queue(Queue *queue)
{
    return queue->items[queue->tail];
}


