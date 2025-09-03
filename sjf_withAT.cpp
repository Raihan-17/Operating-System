#include <bits/stdc++.h>
using namespace std;

int main()
{
    int at[15], bt[15], ct[15], wt[15], tat[15], rt[15], st[15];
    bool done[15] = {false};
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
    
    int complete = 0;
    int currentTime = 0;
    
    while(complete < n){
        int p = -1;
        int min_bt = INT_MAX;
        
        // Find the process with shortest burst time that has arrived and not completed
        for(int i = 0; i < n; i++){
            if(at[i] <= currentTime && !done[i]){
                if(bt[i] < min_bt){
                    min_bt = bt[i];
                    p = i;
                }
            }
        }
        
        if(p == -1){
            currentTime++; // No process available, increment time
        }
        else {
            st[p] = currentTime;
            ct[p] = st[p] + bt[p];
            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];
            rt[p] = st[p] - at[p];
            currentTime = ct[p];
            done[p] = true;
            complete++;
        }
    }

    float totalTAT = 0, totalWT = 0, totalRT = 0;
    for (int i = 0; i < n; i++)
    {
        totalTAT += tat[i];
        totalWT += wt[i];
        totalRT += rt[i];
    }
    
    printf("\nPN\tAT\tBT\tST\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], st[i], ct[i], tat[i], wt[i], rt[i]);
    }
    
    printf("\nAverage Turn Around Time : %.2f\n", totalTAT / n);
    printf("Average Waiting Time : %.2f\n", totalWT / n);
    printf("Average Response Time : %.2f\n", totalRT / n);
    
    return 0;
}