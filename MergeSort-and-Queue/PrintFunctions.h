#include <stdio.h>
#include <stdlib.h>


void PrintArray(int a[], int arraysize)
{
    int i;

    for(i = 0; i < arraysize;i++)
        printf("%d, ",a[i]);
}

void SeparateConsoleLine(void)
{
    printf("\n\n");
}
