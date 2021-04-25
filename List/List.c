#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//HIDDEN FUNCTIONS
//si occupa di inserire in coda un elemento
void push_back_classic(List *head, List *previous, int value)
{
    if(!head)
    {
        head = (List*)malloc(sizeof(List));
        head->value = value;
        head->next = NULL;
        previous->next = head;
    }
    else
        push_back_classic(head->next, head, value);
}

//si occupa della cancellazione di un elemento
void erase_list_classic(List *head, List *previous, int value)
{
    if(head && head->value == value)
    {
        previous->next = head->next;
        free(head);
    }
    else if(head)
        erase_list_classic(head->next, head, value);
}

//si occupa dell'inserimento di un elemento
void insert_list_classic(List *head, List *previous, int value, int index)
{
    if(!head || !index)
    {
        List *node = (List*)malloc(sizeof(List));
        node->value = value;
        node->next = head;
        previous->next = node;
    }
    else
        insert_list_classic(head->next, head, value, index - 1);
}

//VISIBLE FUNCTIONS
//Aggiunge in testa l'elemento value
List* push_front_list(List *head, int value)
{
    List *node = (List*)malloc(sizeof(List));
    node->value = value;
    node->next = head;
    return node;
}

//Aggiunge in coda l'elemento value se la lista non e' null
//altrimenti aggiunge in testa
List* push_back_list(List *head, int value)
{
    if(!head)
        return push_front_list(head, value);
    push_back_classic(head->next, head, value);
    return head;
}

//Elimina tutta la lista
void clear_list(List *head)
{
    if(head)
    {
        List *next = head->next;
        free(head);
        clear_list(next);
    }
}

//Stampa tutta la lista
void print_all_list(List *head)
{
    if(head)
    {
        printf("%d ", head->value);
        print_all_list(head->next);
    }
}

//Cancella il nodo con valore uguale a value se esiste
List* erase_list(List *head, int value)
{
    if(head && head->value == value)
    {
        List *next = head->next;
        free(head);
        return next;
    }
    erase_list_classic(head->next, head, value);
    return head;
}

//Inserisce un elemento nella posizione desiderata
//se index e' piu' di size(lista)
//l'elemento e' inserito alla fine
List* insert_list(List *head, int value, int index)
{
    if(!head || !index)
        return push_front_list(head, value);
    insert_list_classic(head->next, head, value, index - 1);
    return head;
}

//Crea una copia della lista
List* copy_list(List *head)
{
    if(!head)
        return NULL;
    List *node = (List*)malloc(sizeof(List));
    node->value = head->value;
    node->next = copy_list(head->next);
    return node;
}

//Restituisce la lunghezza della lista
int size_list(List *head)
{
    if(!head)
        return 0;
    return 1 + size_list(head->next);
}

//Restituisce il valore alla posizione index
//se index > size(list) restituisce INT_MIN
int at_list(List *head, int index)
{
    if(!head && index)
        return INT_MIN;
    else if(!index)
        return head->value;
    return at_list(head->next, index - 1);
}




