#include "DLL.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//HIDDEN FUNCTIONS
//Si occupa di inserire un elemento in fondo a una lista
void push_back_node_DLL(DLL *current, DLL *previous, int value)
{
    if(!current)
    {
        DLL *node = (DLL*)malloc(sizeof(DLL));
        node->value = value;
        node->next = NULL;
        node->previous = previous;
        previous->next = node;
    }
    else
        push_back_node_DLL(current->next, current, value);
}

//Si occupa della cancellazione di un nodo della lista con valore uguale a value
void erase_node_DLL(DLL *current, int value)
{
    if(current && current->value == value)
    {
        current->previous->next = current->next;
        if(current->next)
            current->next->previous = current->previous;
        free(current);
    }
    else if(current)
        erase_node_DLL(current->next, value);
}

//Si occupa dell'inserimento di un elemento nella lista di un nodo alla posizione index
void insert_node_DLL(DLL *current, DLL *previous, int value, int index)
{
    if(!current || !index)
    {
        DLL *node = (DLL*)malloc(sizeof(DLL));
        node->value = value;
        node->next = current;
        node->previous = previous;
        previous->next = node;
        if(node->next)
            node->next->previous = node;
    }
    else
        insert_node_DLL(current->next, current, value, index - 1);
}

//VISIBLE FUNCTIONS
//Inserisce un elemento in testa alla lista
DLL* push_front_DLL(DLL *head, int value)
{
    DLL *node = (DLL*)malloc(sizeof(DLL));
    node->previous = NULL;
    node->value = value;
    node->next = head;
    if(head)
        head->previous = node;
    return node;
}

//Inserisce un elemento in coda alla lista
DLL* push_back_DLL(DLL *head, int value)
{
    if(!head)
        return push_front_DLL(head, value);
    push_back_node_DLL(head->next, head, value);
    return head;
}

//Stampa una lista
void print_all_DLL(DLL *head)
{
    if(head)
    {
        printf("%d ", head->value);
        print_all_DLL(head->next);
    }
}

//Cancella una lista intera
void clear_DLL(DLL *head)
{
    if(head)
    {
        DLL *next = head->next;
        free(head);
        clear_DLL(next);
    }
}

//Cancella il nodo con valore uguale a value se esiste
DLL* erase_DLL(DLL *head, int value)
{
    if(!head)
        return NULL;
    else if(head->value == value)
    {
        DLL *next = head->next;
        free(head);
        next->previous = NULL;
        return next;
    }
    erase_node_DLL(head->next, value);
    return head;
}

//Inserisce un elemento nella posizione desiderata
//se index > size(DLL) l'elemento e' inserito alla fine
DLL* insert_DLL(DLL *head, int value, int index)
{
    if(!head || !index)
        return push_front_DLL(head, value);
    insert_node_DLL(head->next, head, value, index - 1);
    return head;
}

//Crea una copia di una lista
DLL* copy_DLL(DLL *head)
{
    if(!head)
        return NULL;
    DLL *node = (DLL*)malloc(sizeof(DLL));
    node->value = head->value;
    node->previous = NULL;
    node->next = copy_DLL(head->next);
    if(node->next)
        node->next->previous = node;
    return node;
}

//Restituisce la lunghezza della lista
int size_DLL(DLL *head)
{
    if(!head)
        return 0;
    return 1 + size_DLL(head->next);
}

//Restituisce il valore alla posizione index
//se index > size(DLL) restituisce INT_MIN
int at_DLL(DLL *head, int index)
{
    if(!head && index)
        return INT_MIN;
    else if(!index)
        return head->value;
    return at_DLL(head->next, index - 1);
}


