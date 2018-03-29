#include <stdlib.h>

typedef struct Data{
    int data;
    struct Data* next;
}Data;

typedef struct{
    struct Data* next;
    struct Data* tail;
}Queue;

void PrintQueue(Queue* ptr)
{
    Data* tmp = ptr->next;

    while(tmp){
        printf("%d, ",tmp->data);
        tmp = tmp->next;
    }
}

int QueueHasOneElement(Queue* ptr)
{
    return ptr->next->next == NULL;
}

int QueueIsEmpty(Queue* ptr)
{

    return ptr->next == NULL;
}

void Enqueue(Queue** ptr, int data)
{
    if(!(*ptr))
        EnqueueFirstElement(&*ptr,data);

    else
        EnqueueLastElement(*ptr,data);

}

void EnqueueLastElement(Queue* ptr, int data)
{
    Data* tmp = malloc(sizeof(Data));

    tmp->data = data;
    tmp->next = NULL;

    ptr->tail->next = tmp;

    ptr->tail = tmp;
}

void EnqueueFirstElement(Queue** ptr, int data)
{
    *ptr = malloc(sizeof(Queue));
    Data* tmp = malloc(sizeof(Data));

    tmp->data = data;
    tmp->next = NULL;

    (*ptr)->next = tmp;
    (*ptr)->tail = tmp;
}

int Dequeue(Queue* ptr)
{
    int dequeue = ptr->next->data;

    Data* tmp = ptr->next;

    ptr->next = tmp->next;

    free(tmp);

    return dequeue;
}

int Peek(Queue* ptr)
{
    int peek = ptr->next->data;

    return peek;
}
