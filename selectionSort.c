#include <stdio.h>
#include <stdbool.h>

int arr[] = {23, 19, 15, 14, 12, 9, 6, 4, 3, 1};
// int arr[] = {1, 3, 4, 6, 23, 19, 15,14, 12, 9}; 
// int arr[] = {1, 2, 6, 5, 4, 3};

int n = sizeof(arr) / sizeof(int);

int selectionSort(int *arr)
{
    int count = 0, max, temp;

    for (int i = n - 1; i >= 0; i--)
    {
        max = 0;
        for (int j = 0; j <= i; j++)
        {
            count++;
            if (arr[max] < arr[j])
            {
                max = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
    return count;
}
int main()
{
    int count = selectionSort(arr);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nThe count is : %d", count);
}