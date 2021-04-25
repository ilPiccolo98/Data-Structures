#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define LENGTH 100
#include <stdbool.h>

typedef struct Queue
{
    int items[LENGTH];
    int head;
    int tail;
    int length;
    int cout_items;
}
Queue;

//Inizializza una queue
bool init_queue(Queue *queue, int length);
//Restituisce true se una coda e' vuota, false altrimenti
bool empty_queue(Queue *queue);
//Restituisce true se una coda e' piena, false altrimenti
bool full_queue(Queue *queue);
//Restituisce la lunghezza della coda
int length_queue(Queue *queue);
//Aggiunge un elemento in fondo a una coda
bool enqueue(Queue *queue, int item);
//Elimina il prima elemento di una coda
bool dequeue(Queue *queue);
//Restituisce il primo elemento di una coda
int tail_queue(Queue *queue);

#endif // QUEUE_H_INCLUDED
