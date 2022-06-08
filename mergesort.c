#include <stdio.h>

void Merge(int s, int m, int e, int *arr)
{
    int left_length = m - s + 1;
    int right_length = e - m;

    int Left_arr[left_length];
    int Right_arr[right_length];

    for(int i = 0; i < left_length; i++)
    {
        Left_arr[i] = arr[s + i];
    }

    for(int i = 0; i < right_length; i++)
    {
        Right_arr[i] = arr[m + 1 + i];
    }

    int left_ptr = 0, right_ptr = 0, main_ptr = s;      // this is very important main_ptr != 0****

    while(left_ptr < left_length && right_ptr < right_length)
    {
        if(Left_arr[left_ptr] < Right_arr[right_ptr])
        {
            arr[main_ptr] = Left_arr[left_ptr];
            left_ptr++;
        }
        else
        {
            arr[main_ptr] = Right_arr[right_ptr];
            right_ptr++;
        }
        main_ptr++;
    }

    while(left_ptr < left_length)
    {
        arr[main_ptr] = Left_arr[left_ptr];
        left_ptr++;   
        main_ptr++;
    }

    while(right_ptr < right_length)
    {
        arr[main_ptr] = Right_arr[right_ptr];
        right_ptr++;
        main_ptr++;
    }
}

void MergeSort(int s, int e, int *arr)
{
    if(s == e)
        return;
    int m = (s + e) / 2;
    MergeSort(s, m, arr);

    MergeSort(m + 1, e, arr);

    Merge(s, m, e, arr);
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

    MergeSort(0, last_index, arr);

    printf("\n\nAFTER SORTING");
    printArray(arr, last_index);
    return 0;
}