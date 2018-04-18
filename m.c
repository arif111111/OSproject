#include<stdio.h> 
 int main() 
{ 
 
  int c,a,n,t,r,f=0,time_quantum; 
  int wait_time=0,turnaround_time=0,at[20],bt[20],rt[20]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&n); 
  r=n; 
  for(c=0;c<n;c++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",c+1); 
    scanf("%d",&at[c]); 
    scanf("%d",&bt[c]); 
    rt[c]=bt[c]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(t=0,c=0;r!=0;) 
  { 
    if(rt[c]<=time_quantum && rt[c]>0) 
    { 
      t+=rt[c]; 
      rt[c]=0; 
      f=1; 
    } 
    else if(rt[c]>0) 
    { 
      rt[c]-=time_quantum; 
      t+=time_quantum; 
    } 
    if(rt[c]==0 && f==1) 
    { 
      r--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",c+1,t-at[c],t-at[c]-bt[c]); 
      wait_time+=t-at[c]-bt[c]; 
      turnaround_time+=t-at[c]; 
      f=0; 
} 
    if(c==n-1) 
      c=0; 
    else if(at[c+1]<=t) 
      c++; 
    else 
      c=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/n); 
  
  return 0; 
}
