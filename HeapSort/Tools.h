#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

void print_array(int array[], int length);//stampa il contenuto di un array di int
void fill_array_random(int array[], int length, int min, int max);//riempe un array di int con dei numeri casuali tra min e max inclusi
void fill_array(int array[], int length, int value);//setta tutti i valori di array a value
void set_seed(int seed);//setta il seed per rand
void set_seed_clock();//setta come seed l'orario del sistema
void swap(int *a, int *b);//scambia due interi

#endif // TOOLS_H_INCLUDED
