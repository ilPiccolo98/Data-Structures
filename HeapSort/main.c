#include <stdio.h>
#include <stdlib.h>
#include "HeapSort.h"
#include "Tools.h"

int main()
{
    Heap heap;
    init_heap(&heap, 10);
    int i;
    for(i = 0; i != length_heap(&heap); ++i)
        set_at(&heap, i, i);
    puts("Array originario:");
    print_array(heap.items, length_heap(&heap));
    heap_sort(&heap);
    puts("Heap ordinato:");
    print_array(heap.items, length_heap(&heap));
    return 0;
}
