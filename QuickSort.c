#include <stdio.h>

void swap(int inx1, int inx2, int*arr)
{
    int temp = arr[inx1];
    arr[inx1] = arr[inx2];
    arr[inx2] = temp;
}

int Partition(int s, int e, int* arr)
{
    int pIndex = s;
    int pivot = arr[e];

    for(int i = s; i < e; i++)      // i shouldn't start with 0
    {
        if(arr[i] <= pivot)
        {
            swap(i, pIndex, arr);
            pIndex++;
        }
    }

    swap(pIndex, e, arr);

    return pIndex;
}

void QuickSort(int s, int e, int* arr)
{
    if(s >= e)
    {
        return;
    }

    int pIndex = Partition(s, e, arr);

    QuickSort(s, pIndex - 1, arr);

    QuickSort(pIndex + 1, e, arr);
}

void printArray(int *arr, int last_index)
{
    printf("\nThe array is :");

    for(int i = 0; i <= last_index; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    int last_index = sizeof(arr)/sizeof(int) - 1;

    printf("\nBEFORE SORTING");
    printArray(arr, last_index);

    QuickSort(0, last_index, arr);

    printf("\n\nAFTER SORTING");
    printArray(arr, last_index);
    return 0;
}