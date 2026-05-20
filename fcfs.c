#include <stdio.h>
// FCFS
int main() {
    int n;
    int i;
    int at[10],wt[10],bt[10],ct[10],tat[10];
    float avg_wt=0;
    float avg_tat=0;
    printf ("enter number of processes \n");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("enter arrival time and burst time of process p%d\n",i+1);
        scanf("%d %d",&at[i],&bt[i]);
    }
    int present_time=0;
    for(i=0;i<n;i++){
        if(present_time<at[i]){
            present_time=at[i];   
        }
        printf("process p%d start at %d\n", i+1,present_time);
        ct[i]=present_time+bt[i];
        printf("process p%d end at %d\n",i+1,ct[i]);
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avg_wt+=wt[i];
        avg_tat+=tat[i];
        present_time=ct[i];
    }
    printf("\n");
    printf("pid\tat\tbt\t ct\twt\ttat\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    avg_wt = avg_wt / n;
    avg_tat = avg_tat / n;
    printf("\n avg wt %f and avg tat %f\n", avg_wt, avg_tat);
    return 0;
}