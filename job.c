#include <stdio.h>
#include <stdbool.h>

struct Job
{
    int id;
    int deadline;
    int profit;
};

struct Schedule
{
    bool available;
    int id;
};

void insertion_sort(struct Job *arr, int number)
{

    for (int step = 1; step < number; step++)
    {
        struct Job key = arr[step];
        int j = step - 1;
        while (key.profit > arr[j].profit && j >= 0)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int number, max_deadline = 0;
    printf("Enter the number of jobs : ");
    scanf("%d", &number);

    struct Job array_jobs[number];

    for (int i = 0; i < number; i++)
    {
        int temp_id, temp_deadline, temp_profit;

        printf("Enter the id of job #%d : ", i + 1);
        scanf("%d", &temp_id);

        printf("Enter the deadline of job #%d : ", i + 1);
        scanf("%d", &temp_deadline);

        printf("Enter the profit of job #%d : ", i + 1);
        scanf("%d", &temp_profit);

        array_jobs[i].id = temp_id;
        array_jobs[i].deadline = temp_deadline;
        array_jobs[i].profit = temp_profit;

        if (temp_deadline > max_deadline)
            max_deadline = temp_deadline;
    }

    insertion_sort(array_jobs, number);

    struct Schedule schedule[max_deadline];

    for (int i = 0; i < max_deadline; i++)
    {
        schedule[i].id = -1;
        schedule[i].available = 1;
    }

    for (int i = 0; i < number; i++)
    {
        int k = array_jobs[i].deadline;

        if (schedule[k - 1].available == 0)
        {
            while ((k - 1) >= 0 && schedule[k - 1].available == 0)
            {
                k--;
            }
            if (k > 0)
            {
                schedule[k - 1].available = 0;
                schedule[k - 1].id = array_jobs[i].id;
            }
        }
        else
        {
            schedule[k - 1].available = 0;
            schedule[k - 1].id = array_jobs[i].id;
        }
    }

    char str1[] = "Deadline";
    char str2[] = "Job Id";
    char str3[] = "No Job";
    char str4[] = "";

    printf("\n%10s | %10s", str1, str2);
    printf("\n-----------------------------");

    for (int i = 0; i < max_deadline; i++)
    {
        if (schedule[i].available == 1)
            printf("\n%10d | %13s ", i + 1, str3);
        else
            printf("\n%10d | %6s Job%d ", i + 1, str4, schedule[i].id);
    }
    return 0;
}
