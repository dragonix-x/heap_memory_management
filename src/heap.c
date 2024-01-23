#include <stdio.h>
#include <stdlib.h>
#include "../libs/linked_list/include/list.h"
#include "../include/heap.h"

list_t* create_heap_register(void){
    list_t* heap = create_list();
    return heap;
}

heap_chunk_t* create_heap_chunk(void* chunk, int priority){
    heap_chunk_t* heap_chunk = (heap_chunk_t*)calloc(1, sizeof(heap_chunk_t));
    if(heap_chunk == NULL)
        exit(EXIT_FAILURE);
    heap_chunk->address = chunk;
    heap_chunk->priority = priority;
    return heap_chunk;
}

int register_heap_chunk(list_t** heap_register, void *chunk, int priority){
    push_list(heap_register, create_node(create_heap_chunk(chunk, priority)));
    return (*heap_register)->count - 1;
}

void* free_chunck(void* item){
    heap_chunk_t *chunk = (heap_chunk_t*)item;
    free(chunk->address);
    chunk->address = NULL;
    free(chunk);
    chunk = NULL;
    return chunk;
}

void free_heap_chunk(list_t** heap_register, int chunk_id){
    node_t* current_node = (*heap_register)->start;
    remove_list_node(heap_register, chunk_id, 1, free_chunck);
}

void flush_heap(list_t** heap_register){
    node_t* current_node = (*heap_register)->start;
    int priority = 0;
    int chunk_id = 0;

    while((*heap_register)->count != 0){
        node_t* next_node = current_node->next;
        if(((heap_chunk_t *)current_node->item)->priority == priority)
            remove_list_node(heap_register, chunk_id, 1, free_chunck);
        
        current_node = next_node;
        chunk_id++;
        if(current_node == NULL){
            current_node = (*heap_register)->start;
            chunk_id = 0;
            priority++;
        }
        (*heap_register)->count--;
    }
    free_list(heap_register, free_chunck);
}

