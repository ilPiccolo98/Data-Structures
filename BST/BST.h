#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

typedef struct BST
{
    int value;
    struct BST *left;
    struct BST *right;
}
BST;

//Aggiunge un nuovo elemento al BST
BST* insert_BST(BST *root, int value);
//Esegue una visita dell'albero pre-order
void pre_order_BST(BST *root);
//Esegue una visita dell'albero post-order
void post_order_BST(BST *root);
//Esegue una visita dell'albero in-order
void in_order_BST(BST *root);
//Dealloca l'albero
//assegnare il puntatore a NULL dopo l'uso
void clear_BST(BST *root);
//Restituisce un puntatore al nodo con valore uguale a value
//restituisce NULL altrimenti
BST* search_BST(BST *root, int value);
//Restituisce un puntatore al minimo valore contenuto in un albero
BST* minimum(BST *root);
//Restituisce un puntatore al massimo valore contenuto in un albero
BST* maximum(BST *root);
//Cancella il nodo con lo stesso valore di value
BST* erase_BST(BST *root, int value);
//Restituisce l'altezza dell'albero
int get_height_BST(BST *root);
//Visita in ampiezza l'albero
void breadth_visit_BST(BST *root);
//Restituisce il successore di value
BST* successor_BST(BST *root, int value);
//Restituisce il predecessore di value
BST *predecessor_BST(BST *root, int value);
#endif // BST_H_INCLUDED
