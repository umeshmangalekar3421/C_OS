#include <stdio.h>

// Preemptive SJF (Shortest Remaining Time First) - Fully Fixed
int main() {
    int at[10], bt[10], tat[10], wt[10], ct[10], rem_time[10], completed[10] = {0};
    int n, i;
    
    printf("enter number of processes \n");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rem_time[i] = bt[i]; 
    }
    
    float avg_wt = 0;
    float avg_tat = 0;
    int completed_count = 0;
    int present_time = 0;
    
    while (completed_count < n) {
        int shortest_idx = -1;
        int min_rem = 1e6;
        
        // Scan for the process with the shortest REMAINING time
        for (i = 0; i < n; i++) {
            // Fix 1: Changed '<' to '<=' to include processes arriving exactly at present_time
            if (completed[i] == 0 && at[i] <= present_time) {
                if (rem_time[i] < min_rem) {
                    min_rem = rem_time[i];
                    shortest_idx = i;
                }
            }
        }
        
        if (shortest_idx != -1) {
            int idx = shortest_idx;
            rem_time[idx]--; // Run the process for 1 unit of time
            present_time++;  // Advance the system clock by 1 unit
            
            // Fix 2 & 3: Checked the correct index (idx) and removed the double present_time++ 
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
            // If CPU is idle because no processes have arrived yet
            present_time++;
        }
    } // <-- End of while loop
    
   
    avg_tat = avg_tat / n;
    avg_wt = avg_wt / n;
    
    printf("\n");
    printf("p\tat\tbt\t ct\twt\ttat\n");
    printf("---------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
    }
    printf("---------------------------------------------\n");
    printf("\n avg wt %f and avg tat %f\n", avg_wt, avg_tat);
    
    return 0;
}