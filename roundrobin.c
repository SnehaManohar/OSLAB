#include<stdio.h>

int main(){
 int i,j,n,time_quantum,time,rem_proc,flag=0;
 int wt=0,tat=0,at[10],bt[10],rt[10];
 printf("Enter the no of processes :");
 scanf("%d",&n);
 rem_proc=n;
 for(i=0;i<n;i++){
    printf("\nEnter the arrv time and burst time of proc %d ",i+1);
    scanf("%d%d",&at[i],&bt[i]);
    rt[i]=bt[i];
 }
 printf("\nEnter the time quantum :");
 scanf("%d",&time_quantum);
 printf("\n\nProcess\t|TurnAround time|Waiting time\n");
 for(i=0,time=0;rem_proc!=0;){
    if(rt[i]<=time && rt[i]>0){
        time+=rt[i];
        rt[i]=0;
        flag=1;
    }
    else if(rt[i]>0){
        rt[i]-=time_quantum;
        time+=time_quantum;
    }

    if(rt[i]==0 && flag==1){
        rem_proc--;
        printf("\n\tP[%d]\t|\t%d\t|\t%d\t\n",i+1,time-at[i],time-at[i]-bt[i]);
        wt+=time-at[i]-bt[i];
        tat+=time-at[i];
        flag=0;
    }

    if(i==n-1){
        i=0;
    }
    else if(at[i+1]<time){
        i++;
    }
    else{
        i=0;
    }
 }
 printf("\nAvg waiting time = %f",wt*1.0/n);
 printf("\nAvg TurnAround time = %f",tat*1.0/n);
}



