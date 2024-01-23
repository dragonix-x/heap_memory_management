#include <stdio.h>
#include <stdlib.h>
#include "../libs/linked_list/include/list.h"
#include "../include/heap.h"

int main(void){
    list_t* heap_register = create_heap_register();
    char *string = (char*)calloc(5, sizeof(char));
    register_heap_chunk(&heap_register, string, 1);
    flush_heap(&heap_register);
}
