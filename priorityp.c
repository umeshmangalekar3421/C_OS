#include <stdio.h>

// Preemptive Priority Scheduling
int main() {
    int at[10], bt[10], priority[10], ct[10], tat[10], wt[10], rem_time[10];
    int completed[10] = {0};
    int n, i;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time, and Priority for P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);
        rem_time[i] = bt[i]; // Step 1: Copy original burst time
    }

    int present_time = 0;
    int completed_count = 0;

    // Step 2: Main loop execution engine
    while (completed_count < n) {
        int highest_priority_idx = -1;
        int min_priority_value = 1e6; // Reset benchmark tracker each pass

        // Step 3: Scan for the highest priority process currently available
        for (i = 0; i < n; i++) {
            if (completed[i] == 0 && at[i] <= present_time) {
                if (priority[i] < min_priority_value) { // Lower integer = Higher priority
                    min_priority_value = priority[i];
                    highest_priority_idx = i;
                }
            }
        }

        // Step 4: If a process is available, execute for 1 time unit
        if (highest_priority_idx != -1) {
            int idx = highest_priority_idx;
            rem_time[idx]--;
            present_time++;

            // Step 5: Check if this process has finished its job
            if (rem_time[idx] == 0) {
                ct[idx] = present_time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                
                completed[idx] = 1;
                completed_count++;

                avg_tat += tat[idx];
                avg_wt += wt[idx];
            }
        } else {
            // Step 6: If CPU is idle, advance time forward
            present_time++;
        }
    }

    // Calculations outside the execution loop
    avg_tat = avg_tat / n;
    avg_wt = avg_wt / n;

    // Output Table Matrix
    printf("\nPID\tAT\tBT\tPri\tCT\tTAT\tWT\n");
    printf("-----------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
               i + 1, at[i], bt[i], priority[i], ct[i], tat[i], wt[i]);
    }
    printf("-----------------------------------------------------\n");
    printf("\nAverage Waiting Time    = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}