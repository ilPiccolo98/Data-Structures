#include <stdio.h>
#include <stdlib.h>
#include "Insertion_sort.h"
#include "Tools.h"
#define LENGTH 100

int main()
{
    int array[LENGTH] = { 0 };
    set_seed_clock();
    fill_array_random(array, LENGTH, 0, 1000);
    puts("Array prima:");
    print_array(array, LENGTH);
    insertion_sort(array, LENGTH);
    puts("Array dopo:");
    print_array(array, LENGTH);
    return 0;
}
