#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

typedef struct DLL //Doubly Linked List
{
    struct DLL *previous;
    struct DLL *next;
    int value;
}
DLL;

//Inserisce un elemento in testa alla lista
DLL* push_front_DLL(DLL *head, int value);
//Inserisce un elemento in coda alla lista
DLL* push_back_DLL(DLL *head, int value);
//Stampa una lista
void print_all_DLL(DLL *head);
//Cancella una lista intera
void clear_DLL(DLL *head);
//Cancella il nodo con valore uguale a value se esiste
DLL* erase_DLL(DLL *head, int value);
//Inserisce un elemento nella posizione desiderata
//se index > size(DLL) l'elemento e' inserito alla fine
DLL* insert_DLL(DLL *head, int value, int index);
//Crea una copia di una lista
DLL* copy_DLL(DLL *head);
//Restituisce la lunghezza della lista
int size_DLL(DLL *head);
//Restituisce il valore alla posizione index
//se index > size(DLL) restituisce INT_MIN
int at_DLL(DLL *head, int index);
#endif // DLL_H_INCLUDED
