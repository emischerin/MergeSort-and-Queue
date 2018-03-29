#include <stdio.h>
#include <stdlib.h>
#include "MergeSort.h"
#include "PrintFunctions.h"

int main()
{
    int testarray[] ={456,0,123,456,951,456,23,6,9,74};
    PrintArray(testarray,10);

    MergeSort(testarray,0,9);

    SeparateConsoleLine();

    PrintArray(testarray,10);

}
