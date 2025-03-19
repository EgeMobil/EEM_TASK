/**
 * @file RingBuffer.c
 * @brief Implementation file for the Ring Buffer module.
 * 
 * This file provides the implementation of a circular ring buffer (FIFO buffer).
 * The ring buffer is designed for efficient data storage and retrieval in a 
 * cyclic manner, making it suitable for embedded systems and real-time applications.
 * 
 * Key functionalities include:
 * - Initializing the ring buffer with an external memory space.
 * - Adding (pushing) data into the buffer.
 * - Removing (popping) data from the buffer.
 * - Checking whether the buffer is full or empty.
 * 
 * The implementation ensures proper handling of data overwrites and buffer 
 * boundary conditions using a power-of-two buffer size approach.
 * 
 * @author e.yigit
 * @date 08.03.2025
 */
#include "ringBuffer.h"

/**
 * @brief Checks if the ring buffer is empty.
 * 
 * This function checks whether the ring buffer has any data in it. 
 * It returns true if the buffer is empty, and false otherwise.
 * 
 * @param buffer Pointer to the ring buffer structure.
 * @return bool Returns true if the buffer is empty, false otherwise.
 */
static bool rb_is_empty(ty_ringBuffer* buffer);


/**
 * @brief Checks if the ring buffer is full.
 * 
 * This function checks whether the ring buffer has reached its maximum capacity. 
 * It returns true if the buffer is full, and false otherwise.
 * 
 * @param buffer Pointer to the ring buffer structure.
 * @return bool Returns true if the buffer is full, false otherwise.
 */
static bool rb_is_full (ty_ringBuffer* buffer);


/**
 * @brief Initializes a ring buffer with the specified buffer and size.
 * 
 * This function initializes a ring buffer by linking it to an external buffer 
 * and setting the size, head, and tail indices. It checks for invalid inputs 
 * such as a null buffer or zero size and returns an error status if any are found.
 * 
 * @param buffer Pointer to the ring buffer structure to initialize.
 * @param buf Pointer to the external buffer that will be used for storage.
 * @param sizeOfRingBuffer The size of the external buffer.
 * @return rb_status Returns RB_OK if the buffer is successfully initialized, 
 *         or RB_ERROR if there is an error (e.g., null buffer or zero size).
 */
rb_status rb_init(ty_ringBuffer* buffer, char* buf, size_t sizeOfRingBuffer)
{

    if(buf == NULL)
        return RB_ERROR;

    if (sizeOfRingBuffer == 0)
        return RB_ERROR;

    buffer->buffer = buf;
    buffer->sizeOfBuffer = sizeOfRingBuffer - 1;
    buffer->indexOfHead = 0;
    buffer->indexOfTail = 0;

    return RB_OK;
}


/**
 * @brief Pushes data into the ring buffer.
 * 
 * This function writes data to the ring buffer at the current write position 
 * (head). If the buffer is full, it overwrites the oldest data (tail) and 
 * updates the tail index. The function returns an appropriate status code 
 * based on the outcome of the operation.
 * 
 * @param buffer Pointer to the ring buffer structure.
 * @param data The data to write into the buffer.
 * @return rb_status Returns:
 *         - RB_OK if the data is successfully written,
 *         - RB_FULL if the buffer is full and the oldest data is overwritten.
 */
rb_status rb_push(ty_ringBuffer* buffer, char data)
{
    rb_status status = RB_OK;


    if(rb_is_full(buffer))
    {
        buffer->indexOfTail = (( buffer->indexOfTail + 1) & buffer->sizeOfBuffer);
        status = RB_FULL;
    }

    buffer->buffer[buffer->indexOfHead] = data;
    buffer->indexOfHead = ((buffer->indexOfHead + 1) ) & buffer->sizeOfBuffer;

    return status;
}


/**
 * @brief Pops data from the ring buffer.
 * 
 * This function reads data from the ring buffer at the current read position 
 * (tail) and updates the tail index. If the buffer is empty, it returns an 
 * error status indicating that no data is available to pop.
 * 
 * @param buffer Pointer to the ring buffer structure.
 * @param data Pointer to the variable where the popped data will be stored.
 * @return rb_status Returns:
 *         - RB_OK if the data is successfully read and stored in the `data` variable,
 *         - RB_EMPTY if the buffer is empty and no data is available to pop.
 */
rb_status rb_pop (ty_ringBuffer* buffer, char* data)
{
    if(rb_is_empty(buffer)) 
    {
        return RB_EMPTY;
    }
    *data = buffer->buffer[buffer->indexOfTail];
    buffer->indexOfTail = (buffer->indexOfTail + 1) & buffer->sizeOfBuffer;
    return RB_OK;
}

/**
 * @brief Checks if the ring buffer is empty.
 * 
 * This function checks whether the ring buffer has any data in it by comparing
 * the head and tail indices. If they are equal, the buffer is empty.
 * 
 * @param buffer Pointer to the ring buffer structure.
 * @return bool Returns true if the buffer is empty, false otherwise.
 */
static bool rb_is_empty(ty_ringBuffer* buffer)
{
    return buffer->indexOfHead == buffer->indexOfTail;
}

/**
 * @brief Checks if the ring buffer is full.
 * 
 * This function checks whether the ring buffer has reached its maximum capacity
 * by comparing the next head index with the current tail index. If they are equal, 
 * the buffer is full.
 * 
 * @param buffer Pointer to the ring buffer structure.
 * @return bool Returns true if the buffer is full, false otherwise.
 */
static bool rb_is_full(ty_ringBuffer* buffer)
{
    return ((buffer->indexOfHead + 1) & buffer->sizeOfBuffer) == buffer->indexOfTail;
}



