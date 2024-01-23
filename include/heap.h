#ifndef __HEAP__
#define __HEAP__
#include "../libs/linked_list/include/list.h"

typedef struct {
    void *address;
    int priority;
}heap_chunk_t;

list_t* create_heap_register(void);
heap_chunk_t* create_heap_chunk(void* chunk, int priority);
int register_heap_chunk(list_t** heap_register, void *chunk, int priority);
void* free_chunck(void* item);
void free_heap_chunk(list_t** heap_register, int chunk_id);
void flush_heap(list_t** heap_register);

#endif
