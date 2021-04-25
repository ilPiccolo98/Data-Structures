#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED
#include <stdbool.h>
#define MAX 100

typedef struct Heap
{
    int items[MAX];
    int length;
}
Heap;

bool init_heap(Heap *heap, int length);//inizializza un'heap
int length_heap(Heap *heap);//ritorna la lunghezza dell'heap
bool set_at(Heap *heap, int index, int value);//imposta il valore alla posizione index
int get_at(Heap *heap, int index);//ritorna il valore alla posizione index
int right(Heap *heap, int index);//ritorna il figlio destra
int left(Heap *heap, int index);//ritorna il figlio sinistro
int parent(Heap *heap, int index);//ritorna il genitore
void build_heap(Heap *heap);//costruisce l'heap
void heap_sort(Heap *heap);//ordina l'heap

#endif // HEAPSORT_H_INCLUDED
