#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main()
{
    BST *tree = NULL;
    tree = insert_BST(tree, 10);
    tree = insert_BST(tree, 5);
    tree = insert_BST(tree, 14);
    tree = insert_BST(tree, 1);
    BST *node = predecessor_BST(tree, 1);
    if(node)
        printf("%d\n", node->value);
    clear_BST(tree);
    tree = NULL;
    return 0;
}
