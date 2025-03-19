#include "..\inc\task.h"

int initList(linkedList_t *list)
{
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;

    return list->count;
}

int addNode(linkedList_t *list, void *data, dataType_t type)
{
    node_t *new = (node_t *)malloc(sizeof(node_t));
    new->next = NULL;
    if(!new) return 0;
    new->data = data;
    new->type = type;
    switch(new->type)
    {
        case INT_TYPE:
            new->printNode = print_int; 
            break;
        case FLOAT_TYPE:
            new->printNode = print_float;
            break;
        case CHAR_TYPE:
            new->printNode = print_char;
            break;
        case DOUBLE_TYPE:
            new->printNode = print_double;
            break;
        default:
            break;
    }
    if(list->head == NULL)
    {
        list->head = new;
        list->tail = new;
        list->count = 1;
    }
    else
    {
        list->tail->next = new;
        list->tail = new;
        list->count++;
    }

    return 1;
}

int deleteNode(linkedList_t *list, void *data)
{
    if(list->head == NULL)
    {
        printf("Linked List is empty\n");
        return 0;
    }

    if(list->head->data == data)
    {
        node_t *tmp = list->head;
        list->head = list->head->next;

        if(list->head == NULL)
        {
            list->tail == NULL;
        }

        free(tmp);
        list->count--;
        return 1;
    }

    node_t *prev = NULL;
    node_t *index = list->head;
    while(index != NULL && index->data != data)
    {
        prev = index;
        index = index->next;
    }

    if(index == NULL)
    {
        printf("Data not found\n");
        return 0;
    }
    
    prev->next = index->next;
    if(index == list->tail)
    {
        list->tail = prev;
    }

    free(index);
    list->count--;
    return 1;
}

int printAll(linkedList_t *list)
{
    if(list->head == NULL)
    {
        printf("\nLinked List is empty\n");
        return 0;
    }
    node_t *tmp = list->head;
    printf("\nLinked List: ");
    while(tmp != NULL)
    {   
        tmp->printNode(tmp->data);
        tmp = tmp->next;
    }
    return list->count;
}

int deleteList(linkedList_t *list)
{
    if(list->head == NULL)
    {
        printf("Linked List is already empty\n");
        return 0;
    }

    node_t *tmp = NULL;

    while(list->head != NULL)
    {
        tmp = list->head;
        list->head = tmp->next;
        free(tmp);
    }
    list->tail = NULL;
    list->count = 0;
    return 1;
}

void print_int(void* data)
{
    printf("%d - ",*(int*)data);
}

void print_float(void* data)
{
    printf("%f - ",*(float*)data);
}

void print_char(void* data)
{
    printf("%c - ",*(char*)data);
}

void print_double(void* data)
{
    printf("%lf - ",*(double*)data);
}