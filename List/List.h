#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct List
{
    int value;
    struct List *next;
}
List;

//Aggiunge in testa l'elemento value
List* push_front_list(List *head, int value);
//Aggiunge in coda l'elemento value se la lista non e' null, altrimenti aggiunge in testa
List* push_back_list(List *head, int value);
//Elimina tutta la lista, assegnare alla lista NULL dopo l'uso
void clear_list(List *head);
//Stampa tutta la lista
void print_all_list(List *head);
//Cancella il nodo con valore uguale a value se esiste
List* erase_list(List *head, int value);
//Inserisce un elemento nella posizione desiderata
//se index > size(lista) l'elemento e' inserito alla fine
List* insert_list(List *head, int value, int index);
//Crea una copia di una lista
List* copy_list(List *head);
//Restituisce la lunghezza della lista
int size_list(List *head);
//Restituisce il valore alla posizione index
//se index > size(list) restituisce INT_MIN
int at_list(List *head, int index);

#endif // LIST_H_INCLUDED
