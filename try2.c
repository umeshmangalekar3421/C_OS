#include <stdio.h>
int main() {
  int n;
  int i;
  printf("enter number of processes \n");
  scanf("%d", &n);
  int at[n], wt[n], bt[n], ct[n], tat[n];
  for (i = 0; i < n; i++) {
    printf("enter arrival time and burst time of process p%d\n", i + 1);
    scanf("%d %d", &at[i], &bt[i]);
  }
  float avg_wt = 0;
  float avg_tat = 0;

  int present_time = 0;
  int completed[10] = {0};

  int completed_count = 0;
  while(completed_count<n){
    int shortest_idx=-1;
    int min_bt=1e6;
    for(i=0;i<n;i++){
        if(completed[i]==0 && at[i]<=present_time){
            if(bt[i]< min_bt ){
                min_bt=bt[i];
                shortest_idx=i;
                
            }
        }
    }
    if(shortest_idx!=-1){
        printf("process p%d start at %d\n",shortest_idx+1,present_time);
        present_time+=bt[shortest_idx];
        ct[shortest_idx]=present_time;
        tat[shortest_idx]=ct[shortest_idx]-at[shortest_idx];
        wt[shortest_idx]=tat[shortest_idx]-bt[shortest_idx];
        avg_tat+=tat[shortest_idx];
        avg_wt+=wt[shortest_idx];
        completed[shortest_idx]=1;
        completed_count++;
    } else{
        present_time++;
    }
  }
  avg_tat=avg_tat/n;
  avg_wt=avg_wt/n;
  printf("\n");
  printf("pid\tat\tbt\t ct\twt\ttat\n");
  for(i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
  }
  printf("\n avg wt %f and avg tat %f\n", avg_wt, avg_tat);
  return 0;            
}