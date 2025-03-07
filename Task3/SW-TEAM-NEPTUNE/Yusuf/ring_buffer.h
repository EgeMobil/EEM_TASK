#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#define QUEUE_EMPTY_CHAR ('\0') 

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// ring_buffer is a circular buffer that holds byte data
// head and tail are array indexes
// num_entries is the current entry count in the buffer, (tail +  1)
// size is the size of the buffer
typedef struct{
	char *values;
	int head, tail, num_entries, size;
}ring_buffer;

void rb_init(ring_buffer *rb, int size );
bool rb_is_empty(const ring_buffer *rb);
bool rb_is_full(const ring_buffer *rb);
void rb_push(ring_buffer *rb, char value);
char rb_pop(ring_buffer *rb);
void rb_destroy(ring_buffer *rb);

#endif