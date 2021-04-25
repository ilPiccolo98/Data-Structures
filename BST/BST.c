#include "BST.h"
#include <stdlib.h>
#include <stdio.h>

//HIDDEN FUNCTIONS
//Si occupa dell'inserimento del nodo
void insert_node_BST(BST *current, BST *parent, int value)
{
    if(!current)
    {
        BST *node = (BST*)malloc(sizeof(BST));
        node->left = NULL;
        node->right = NULL;
        node->value = value;
        if(value > parent->value)
            parent->right = node;
        else
            parent->left = node;
    }
    else if(value < current->value)
        insert_node_BST(current->left, current, value);
    else
        insert_node_BST(current->right, current, value);
}

//Stacca il nodo con valore minimo dall'albero
BST* get_minimum(BST *current, BST *parent)
{
    if(!current)
        return NULL;
    else if(!current->left && current == parent->left)
    {
        parent->left = current->right;
        return current;
    }
    else if(!current->left && current == parent->right)
    {
        parent->right = current->right;
        return current;
    }
    return get_minimum(current->left, current);
}

//Cancella la radice di un albero
BST* erase_root_BST(BST *root)
{
    if(!root)
        return NULL;
    else if(!root->left && !root->right)
    {
        free(root);
        return NULL;
    }
    else if(!root->left)
    {
        BST *right = root->right;
        free(root);
        return right;
    }
    else if(!root->right)
    {
        BST *left = root->left;
        free(root);
        return left;
    }
    BST *tmp = get_minimum(root->right, root);
    root->value = tmp->value;
    free(tmp);
    return root;
}

//Si occupa della cancellazione di un nodo
void erase_node_BST(BST *current, BST *parent, int value)
{
    if(current && current->value == value)
    {
        if(value < parent->value)
            parent->left = erase_root_BST(current);
        else
            parent->right = erase_root_BST(current);
    }
    else if(current && value < current->value)
        erase_node_BST(current->left, current, value);
    else
        erase_node_BST(current->right, current, value);
}

//Visita i nodi ad altezza height
void visit_height_BST(BST *root, int height)
{
    if(!height && root)
        printf("%d ", root->value);
    else if(root)
    {
        visit_height_BST(root->left, height - 1);
        visit_height_BST(root->right, height - 1);
    }
}

//VISIBLE FUNCTIONS
//Aggiunge un nuovo elemento al BST
BST *insert_BST(BST *root, int value)
{
    if(!root)
    {
        BST *node = (BST*)malloc(sizeof(BST));
        node->left = NULL;
        node->right = NULL;
        node->value = value;
        return node;
    }
    else if(value < root->value)
        insert_node_BST(root->left, root, value);
    else if(value > root->value)
        insert_node_BST(root->right, root, value);
    return root;
}

//Esegue una visita dell'albero pre-order
void pre_order_BST(BST *root)
{
    if(root)
    {
        printf("%d ", root->value);
        pre_order_BST(root->left);
        pre_order_BST(root->right);
    }
}

//Esegue una visita dell'albero post-order
void post_order_BST(BST *root)
{
    if(root)
    {
        post_order_BST(root->left);
        post_order_BST(root->right);
        printf("%d ", root->value);
    }
}

//Esegue una visita dell'albero in-order
void in_order_BST(BST *root)
{
    if(root)
    {
        in_order_BST(root->left);
        printf("%d ", root->value);
        in_order_BST(root->right);
    }
}

//Dealloca l'albero
void clear_BST(BST *root)
{
    if(root)
    {
        clear_BST(root->left);
        clear_BST(root->right);
        free(root);
    }
}

//Restituisce un puntatore al nodo con valore uguale a value
//restituisce NULL altrimenti
BST* search_BST(BST *root, int value)
{
    if(!root)
        return NULL;
    else if(root->value == value)
        return root;
    else if(value < root->value)
        return search_BST(root->left, value);
    return search_BST(root->right, value);
}

//Restituisce un puntatore al minimo valore contenuto in un albero
BST* minimum(BST *root)
{
    if(!root)
        return NULL;
    else if(!root->left)
        return root;
    return minimum(root->left);
}

//Restituisce un puntatore al massimo valore contenuto in un albero
BST* maximum(BST *root)
{
    if(!root)
        return NULL;
    else if(!root->right)
        return root;
    return maximum(root->right);
}

//Cancella il nodo con lo stesso valore di value
BST* erase_BST(BST *root, int value)
{
    if(!root)
        return NULL;
    else if(root->value == value)
        return erase_root_BST(root);
    else if(value < root->value)
    {
        erase_node_BST(root->left, root, value);
        return root;
    }
    erase_node_BST(root->right, root, value);
    return root;
}

//Restituisce l'altezza dell'albero
int get_height_BST(BST *root)
{
    if(!root)
        return -1;
    int left = get_height_BST(root->left);
    int right = get_height_BST(root->right);
    int max = (left >= right) ? left : right;
    return max + 1;
}

//Visita in ampiezza l'albero
void breadth_visit_BST(BST *root)
{
    int height = get_height_BST(root);
    int i;
    for(i = 0; i <= height; ++i)
        visit_height_BST(root, i);
}

//Restituisce il successore di value
BST* successor_BST(BST *root, int value)
{
    if(!root)
        return NULL;
    else if(root->value == value && root->right)
        return minimum(root->right);
    else if(root->value == value && !root->right)
        return NULL;
    else if(value > root->value)
        return successor_BST(root->right, value);
    BST *tmp = successor_BST(root->left, value);
    if(!tmp)
        tmp = root;
    return tmp;
}

//Restituisce il predecessore di value
BST *predecessor_BST(BST *root, int value)
{
    if(!root)
        return NULL;
    else if(root->value == value && root->left)
        return maximum(root->left);
    else if(root->value == value && !root->right)
        return NULL;
    else if(value < root->value)
        return predecessor_BST(root->left, value);
    BST *tmp = predecessor_BST(root->right, value);
    if(!tmp)
        tmp = root;
    return tmp;
}


