#include "ring_buffer.h"


// rb_init initializes given ring buffer with given size
void rb_init(ring_buffer *rb, int size ){
	rb->size = size;
	rb->values = malloc(sizeof(char) * rb->size);
	if (rb->values == NULL){
		fprintf(stderr, "Insufficient memory for buffer\n");
		exit(-1);
	}

	rb->num_entries = 0;
	rb->head = 0;
	rb->tail = 0;
}

// adds data at the end (tail) of the queue, overrides existing data
void rb_push(ring_buffer *rb, char value){
	rb->values[rb->tail % rb->size] = value;
	rb->num_entries = (rb->num_entries + 1) % rb->size;
	rb->tail = (rb->tail + 1) % rb->size;
}

// rb_pop returns the value at the head index (FIFO)
// if buffer is empty, null character is returned
char rb_pop(ring_buffer *rb){
	char result;
	if(rb_is_empty(rb)){
		fprintf(stderr, "buffer is empty\n");
		return QUEUE_EMPTY_CHAR;
	}

	result = rb->values[rb->head];
	rb->num_entries--;
	rb->head = (rb->head + 1) % rb->size;

	return result;
}


bool rb_is_empty(const ring_buffer *rb){
	return rb->num_entries == 0; 
}

bool rb_is_full(const ring_buffer *rb){
	return rb->num_entries == rb->size; 
}

// rb_free , frees the memory allocated by the buffer
void rb_destroy(ring_buffer *rb){
	free(rb->values);
}