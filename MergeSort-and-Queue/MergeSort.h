#include <stdlib.h>
#include "Queue.h"

void MergeSort(int a[],int low, int high)
{
    if (low >= high) return;

    int middle = (low + high)/2;

    MergeSort(a,low,middle);
    MergeSort(a,middle + 1, high);
    Merge(a,low,middle,high);

}

void Merge(int a[], int low,int middle, int high)
{
    int i;
    Queue* firsthalf = NULL;
    Queue* secondhalf = NULL;

    for (i = low;i <= middle;i++)
        Enqueue(&firsthalf,a[i]);

    for(i = middle + 1; i<= high;i++)
        Enqueue(&secondhalf,a[i]);

    int counter = low;

    while(!(QueueIsEmpty(firsthalf)|| QueueIsEmpty(secondhalf))){

        if (Peek(firsthalf) <= Peek(secondhalf))
            a[counter++] = Dequeue(firsthalf);

        else
            a[counter++] = Dequeue(secondhalf);

    }

    while(!QueueIsEmpty(firsthalf)) a[counter++] = Dequeue(firsthalf);
    while(!QueueIsEmpty(secondhalf)) a[counter++] = Dequeue(secondhalf);

}
