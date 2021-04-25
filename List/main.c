#include <stdio.h>
#include <stdlib.h>
#include "List.h"

int main()
{
    List *list = NULL;
    int i;
    for(i = 0; i != 10; ++i)
        list = push_back_list(list, i);
    list = erase_list(list, 0);
    list = insert_list(list, 0, 10);
    print_all_list(list);
    printf("\n%d\n", at_list(list, 100));
    clear_list(list);
    list = NULL;
    return 0;
}
