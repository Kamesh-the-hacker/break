#include <stdio.h>

int main() {
    int n, i, j, bt[10], p[10], wt[10] = {0}, tat[10], pos;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst time and priority:\n");
    for(i = 0; i < n; i++) {
        scanf("%d %d", &bt[i], &p[i]);
    }

    // Sort by priority (lower value = higher priority)
    for(i = 0; i < n; i++) {
        pos = i;
        for(j = i + 1; j < n; j++) {
            if(p[j] < p[pos])
                pos = j;
        }
        // swap burst time
        int temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        // swap priority
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    // Waiting time
    for(i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    // Turnaround time
    for(i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    printf("\nBT\tPR\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\n", bt[i], p[i], wt[i], tat[i]);

    return 0;
}
