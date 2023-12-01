#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int at[], int bt[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (at[j] > at[j + 1])
            {
                swap(&at[j], &at[j + 1]);
                swap(&bt[j], &bt[j + 1]);
            }
        }
    }
}

void count(int at[], int bt[], int ct[], int qt, int n)
{
    int remaningBT[n];
    for (int i = 0; i < n; i++)
    {
        remaningBT[i] = bt[i];
    }
    int time = 0;
    if (at[0] != 0)
    {
        time += at[0];
    }
    while (1)
    {
        int done = 1;
        for (int i = 0; i < n; i++)
        {
            if (remaningBT[i] > 0)
            {
                done = 0;
                if (remaningBT[i] > qt)
                {
                    time += qt;
                    remaningBT[i] -= qt;
                }
                else
                {
                    time += remaningBT[i];
                    ct[i] = time;
                    remaningBT[i] = 0;
                    ct[i] = time;
                }
            }
        }
        if (done == 1)
            break;
    }
}
void tat_and_wt(int at[], int bt[], int ct[], int tat[], int wt[], int n)
{
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }
}

void display(int at[], int bt[], int ct[], int tat[], int wt[], int n)
{
    printf("AT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n", at[i], bt[i], ct[i], tat[i], wt[i]);
    }
}

int main()
{
    int n, qt;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter Assume time Quantum: ");
    scanf("%d", &qt);
    int at[n], bt[n], ct[n], tat[n], wt[n];
    printf("\tAT\tBT\n");
    for (int i = 0; i < n; i++)
    {
        printf("p%d:", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }
    sort(at, bt, n);
    count(at, bt, ct, qt, n);
    tat_and_wt(at, bt, ct, tat, wt, n);
    display(at, bt, ct, tat, wt, n);

    return 0;
}
