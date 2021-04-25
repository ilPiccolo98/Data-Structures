#include "HeapSort.h"
#include <limits.h>
#include "Tools.h"
#include <stdio.h>

//FUNZIONI PRIVATE
//ristabilisce le proprieta' dell'heap
void heapify(Heap *heap, int index, int heap_length)
{
    int l = left(heap, index);
    int r = right(heap, index);
    int max = index;
    if(l < heap_length && get_at(heap, l) > get_at(heap, max))
        max = l;
    if(r < heap_length && get_at(heap, r) > get_at(heap, max))
        max = r;
    if(index != max)
    {
        swap(&heap->items[index], &heap->items[max]);
        heapify(heap, max, heap_length);
    }
}

//FUNZIONI PUBBLICHE
//inizializza un'heap
bool init_heap(Heap *heap, int length)
{
    if(length <= MAX)
    {
        heap->length = length;
        return true;
    }
    return false;
}

//ritorna la lunghezza dell'heap
int length_heap(Heap *heap)
{
    return heap->length;
}

//imposta il valore alla posizione index
bool set_at(Heap *heap, int index, int value)
{
    if(index < length_heap(heap))
    {
        heap->items[index] = value;
        return true;
    }
    return false;
}

//ritorna il valore alla posizione index
int get_at(Heap *heap, int index)
{
    if(index < length_heap(heap))
        return heap->items[index];
    return INT_MAX;
}

//ritorna il figlio sinistro
int left(Heap *heap, int index)
{
    return index * 2 + 1;
}

//ritorna il figlio destra
int right(Heap *heap, int index)
{
    return index * 2 + 2;
}

//ritorna il genitore
int parent(Heap *heap, int index)
{
    return (index - 1) / 2;
}

//costruisce l'heap
void build_heap(Heap *heap)
{
    int i;
    for(i = length_heap(heap) / 2 - 1; i >= 0; --i)
        heapify(heap, i, length_heap(heap));
}

//ordina l'heap
void heap_sort(Heap *heap)
{
    build_heap(heap);
    int i;
    for(i = length_heap(heap) - 1; i >= 0; --i)
    {
        swap(&heap->items[0], &heap->items[i]);
        heapify(heap, 0, i);
    }
}

