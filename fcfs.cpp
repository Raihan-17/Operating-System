#include <bits/stdc++.h>
using namespace std;
int main()
{
    int at[15], bt[15], ct[15], wt[15], tat[15], rt[15], start[15];
    int n;
    printf("Enter the number of operations : ");
    scanf("%d", &n);
    printf("Enter Arrival Times of operations: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }
    printf("Enter Burst Times of operations: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    start[0] = 0;
    ct[0] = start[0] + bt[0];
    for (int i = 1; i < n; i++)
    {
        if (at[i] > ct[i - 1])
        {
            start[i] = at[i];
        }
        else{
       start[i] = ct[i - 1];
    }
     ct[i] = start[i] + bt[i];
    }
    float totalTAT = 0, totalWT = 0, totalRT = 0;
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - 0;
        wt[i] = tat[i] - bt[i];
        rt[i] = start[i] - 0;
        totalTAT += tat[i];
        totalWT += wt[i];
        totalRT += rt[i];
    }
    printf("\nPN\tBT\tST\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, bt[i], start[i], ct[i], tat[i], wt[i], rt[i]);
    }
    printf("\nAverage Turn Around Time : %.2f\n", totalTAT / n);
    printf("Average Waiting Time :%.2f\n", totalWT / n);
    printf("Average Response Time :%.2f\n", totalRT / n);
    return 0;
}
