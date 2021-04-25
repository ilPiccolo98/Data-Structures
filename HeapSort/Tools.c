#include "Tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//FUNZIONI PRIVATE
//restituisce un int tra min e max, min e max inclusi
int random_number(int min, int max)
{
    return min + rand() % (max + 1 - min);
}

//FUNZIONI PUBBLICHE
//stampa il contenuto di un array di int
void print_array(int array[], int length)
{
    int i;
    for(i = 0; i != length; ++i)
        printf("Number at index %d: %d\n", i, array[i]);
}

//riempe un array di int con dei numeri casuali tra min e max inclusi
void fill_array_random(int array[], int length, int min, int max)
{
    int i;
    for(i = 0; i != length; ++i)
        array[i] = random_number(min, max);
}

//setta tutti i valori di array a value
void fill_array(int array[], int length, int value)
{
    int i;
    for(i = 0; i != length; ++i)
        array[i] = value;
}

//setta il seed per rand
void set_seed(int seed)
{
    srand(seed);
}

//setta come seed l'orario del sistema
void set_seed_clock()
{
    srand(time(NULL));
}

//scambia due interi
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
