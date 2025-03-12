/**
 * @file RingBuffer.h
 * @brief Header file for the Ring Buffer implementation.
 * 
 * This file contains the definitions and function prototypes for the 
 * ring buffer (FIFO buffer).
 * 
 * Key functionalities include:
 * - Initializing the ring buffer with an external storage array.
 * - Adding (pushing) data to the buffer.
 * - Retrieving (popping) data from the buffer.
 * - Status checks such as buffer full or empty conditions.
 * 
 * The ring buffer is implemented as a circular queue using head and tail 
 * indices to keep track of data read and write positions.
 * 
 * @author e.yigit
 * @date 08.03.2025
 */
#ifndef _RING_BUFFER_H_
#define _RING_BUFFER_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>


/**
 * @brief Structure defining a ring buffer.
 * 
 * This structure implements a FIFO (First In, First Out) buffer, 
 * where data is stored in a circular manner. It maintains indices 
 * for reading (tail) and writing (head) operations.
 */
typedef struct 
{
    char* buffer;            /**< Pointer to the buffer storing data */
    size_t indexOfTail;      /**< Index for reading (tail position) */
    size_t indexOfHead;      /**< Index for writing (head position) */
    size_t sizeOfBuffer;     /**< Total size of the buffer */
}ty_ringBuffer;


/**
 * @brief Enumeration for ring buffer status codes.
 * 
 * This enumeration defines possible status values that indicate 
 * the state of the ring buffer during operations.
 */
typedef enum {
    RB_ERROR,  /**< An error occurred during the operation */
    RB_OK,     /**< Operation completed successfully */
    RB_EMPTY,  /**< The ring buffer is empty */
    RB_FULL    /**< The ring buffer is full */
}rb_status;


/**
 * @brief Initializes a ring buffer.
 * 
 * This function initializes a ring buffer by setting its internal parameters 
 * and linking it to an external buffer.
 * 
 * @param buffer Pointer to the ring buffer structure to initialize.
 * @param buf Pointer to the external buffer that will be used for storage.
 * @param sizeOfRingBuffer Size of the external buffer.
 * @return rb_status Returns RB_OK if initialization is successful, RB_ERROR otherwise.
 */
rb_status rb_init(ty_ringBuffer* buffer, char* buf, size_t sizeOfRingBuffer);


/**
 * @brief Pushes data into the ring buffer.
 * 
 * This function writes data to the ring buffer at the current write position (head).
 * If the buffer is full, it will not write and will return an error status.
 * 
 * @param buffer Pointer to the ring buffer structure.
 * @param data The data to write into the buffer.
 * @return rb_status Returns RB_OK if the data is successfully written, 
 *         RB_FULL if the buffer is full, or RB_ERROR if an error occurs.
 */
rb_status rb_push(ty_ringBuffer* buffer, char data);


/**
 * @brief Pops data from the ring buffer.
 * 
 * This function reads data from the ring buffer at the current read position (tail).
 * If the buffer is empty, it will not read and will return an error status.
 * 
 * @param buffer Pointer to the ring buffer structure.
 * @param data Pointer to the variable where the popped data will be stored.
 * @return rb_status Returns RB_OK if the data is successfully read, 
 *         RB_EMPTY if the buffer is empty, or RB_ERROR if an error occurs.
 */
rb_status rb_pop (ty_ringBuffer* buffer, char* data);


#endif //_RING_BUFFER_H_