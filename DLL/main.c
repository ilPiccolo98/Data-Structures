#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"

int main()
{
    DLL *dll = NULL;
    int i;
    for(i = 0; i != 10; ++i)
        dll = push_back_DLL(dll, i);
    dll = insert_DLL(dll, 100, 1000);
    print_all_DLL(dll);
    puts("");
    DLL *copy = copy_DLL(dll);
    copy = erase_DLL(copy, 3);
    print_all_DLL(copy);
    puts("");
    printf("size of copy: %d\n", size_DLL(copy));
    printf("Value a position %d of copy: %d\n", 5, at_DLL(copy, 5));
    clear_DLL(dll);
    clear_DLL(copy);
    return 0;
}
