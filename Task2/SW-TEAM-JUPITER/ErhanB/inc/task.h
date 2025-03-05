#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum
{
    INT_TYPE,
    DOUBLE_TYPE,
    FLOAT_TYPE,
    CHAR_TYPE
} dataType_t;

typedef struct node
{
    void *data;
    dataType_t type;
    void(*printNode)(void *data);
    struct node_t *next;
} node_t;

typedef struct 
{
    node_t *head;
    node_t *tail;
    int count;
} linkedList_t;

int initList(linkedList_t *list);
int addNode(linkedList_t *list, void *data, dataType_t type);
int deleteNode(linkedList_t *list, void *data);
int printAll(linkedList_t *list);
int deleteList(linkedList_t *list);
void print_int(void* data);
void print_float(void* data);
void print_char(void* data);
void print_double(void* data);


