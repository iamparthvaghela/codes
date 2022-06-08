#include <stdio.h>

struct item
{
    int id;
    float weight;
    float value;
    float ratio;
    float used;
};

int knapSack(struct item *arr, float total_weight, int last_index)
{
    int total_profit = 0;
    int i = last_index;
    while(total_weight > 0)
    {
        if(total_weight > arr[i].weight)
        {
            arr[i].used = arr[i].weight;
            total_weight -= arr[i].weight;
            total_profit += arr[i].value;
        }
        else
        {
            arr[i].used = total_weight;
            total_profit += total_weight * arr[i].ratio;
            break;
        }
        i--;
    }

    return total_profit;
}

void sortWithId(struct item *arr, int n)
{
    struct item temp;

    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j].id < arr[j - 1].id)
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
                break;
        }
    }
}

void insertionSort(struct item *arr, int n)
{
    struct item temp;

    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j].ratio < arr[j - 1].ratio)
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
            else
                break;
        }
    }
}

void printList(struct item *arr, int num_items)
{
    char str1[]= "ID";
    char str2[] = "Profit";
    char str3[] = "Weight";
    char str4[] = "Ratio";
    char str5[] = "Quantity";
    printf("\n%10s | %10s | %10s | %10s | %10s", str1, str2, str3, str4, str5);
    for (int i = 0; i < num_items; i++)
    {
        printf("\n%10d | %10f | %10f | %10f | %10f",  arr[i].id, arr[i].value, arr[i].weight, arr[i].ratio, arr[i].used);
    }
}

int main()
{
    float total_weight;
    int num_items;

    printf("Enter the total weight of the sack : ");
    scanf("%f", &total_weight);
    printf("Enter the number of items : ");
    scanf("%d", &num_items);

    struct item arr[num_items];

    for (int i = 0; i < num_items; i++)
    {
        float temp_weight, temp_value;
        printf("Enter the value of item #%d : ", i + 1);
        scanf("%f", &temp_value);
        arr[i].value = temp_value;

        printf("enter the weight of item #%d : ", i + 1);
        scanf("%f", &temp_weight);
        arr[i].weight = temp_weight;

        arr[i].ratio = arr[i].value / arr[i].weight;

        arr[i].id = i + 1;

        arr[i].used = 0;
    }

    insertionSort(arr, num_items);

    int profit = knapSack(arr, total_weight, num_items - 1);

    sortWithId(arr, num_items);

    printList(arr, num_items);

    printf("\n\nThe total profit is %d\n", profit);


    return 0;
}