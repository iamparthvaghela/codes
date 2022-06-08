#include <stdio.h>
#include <stdbool.h>

int arr[] = {23, 19, 15, 14, 12, 9, 6, 4, 3, 1};
// int arr[] = {1, 3, 4, 6, 23, 19, 15,14, 12, 9};
// int arr[] = {1, 2, 6, 5, 4, 3};

int n = sizeof(arr) / sizeof(int);

void swap(int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int bubbleSort(int *arr)
{
    bool swapped = false;
    int count = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        swapped = false;
        for (int j = 0; j <= i; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                swapped = true;
                swap(j, j + 1);
            }
        }
        if (!swapped)
            return count;
    }
    return count;
}
int main()
{
    int count = bubbleSort(arr);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nThe count is : %d", count);
}