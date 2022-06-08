#include <stdio.h>
#include <stdbool.h>

// int arr[] = {1, 3, 4, 6, 9, 12, 14, 15, 19, 23};
int arr[] = {23, 19, 15, 14, 12, 9, 6, 4, 3, 1};
// int arr[] = {1, 3, 4, 6, 23, 19, 15,14, 12, 9};
// int arr[] = {1, 2, 6, 5, 4, 3};

int n = sizeof(arr) / sizeof(int);

int insertionSort(int *arr)
{
    int count = 0, temp;

    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            count++;
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
                break;
        }
    }
    return count;
}
int main()
{
    int count = insertionSort(arr);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nThe count is : %d", count);
}