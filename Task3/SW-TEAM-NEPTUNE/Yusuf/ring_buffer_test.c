#include <time.h>
#include "ring_buffer.h"

#define BUFFER_SIZE 8

int main(void) {
    ring_buffer rb;
    int i, totalPushes = 12;  // Push more than the buffer size to test overwrite
    char value;

    // Initialize random number generator
    srand((unsigned int)time(NULL));

    // Initialize ring buffer
    rb_init(&rb, BUFFER_SIZE);
    printf("Ring buffer of size %d created.\n", BUFFER_SIZE);

    // Push random characters into the ring buffer
    printf("\nPushing %d random characters into the buffer:\n", totalPushes);
    for(i = 0; i < totalPushes; i++){
        value = 'A' + (rand() % 26);  // random uppercase letter
        printf("Pushing '%c' into the buffer\n", value);
        rb_push(&rb, value);
    }

    // Pop all elements from the buffer
    printf("\nPopping all elements from the buffer:\n");
    while(!rb_is_empty(&rb)) {
        char popped = rb_pop(&rb);
        printf("Popped: '%c'\n", popped);
    }

    // Attempt to pop from an empty buffer to show error message
    printf("\nAttempting to pop from an empty buffer:\n");
    char popped = rb_pop(&rb);
    if(popped == QUEUE_EMPTY_CHAR) {
        printf("Received empty buffer signal: '%c'\n", popped);
    }

    // Clean up
    rb_destroy(&rb);
    return 0;
}