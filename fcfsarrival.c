#include<stdio.h>
int main(){
int n,i,j,bt[10],wt[10],tat[10],at[10],gt[10];
float avgwt=0.0,avgtat=0.0;

printf("Enter the number of processes :");
scanf("%d",&n);
printf("\nEnter the burst times :");
for(i=0;i<n;i++){
    printf("\nP[%d] :",i+1);
    scanf("%d",&bt[i]);
}
printf("\nEnter the arrival times : ");
for(i=0;i<n;i++){
    printf("\nP[%d] :",i+1);
    scanf("%d",&at[i]);
}

gt[0]=0;
for(i=0;i<n;i++){
    gt[i+1]=gt[i]+bt[i];
}
printf("\n\nProcess\tWait time\tTat\tBurst\n");
for(i=0;i<n;i++){
    tat[i]=gt[i+1]-at[i];
    wt[i]=gt[i]-at[i];
    avgwt+=wt[i];
    avgtat+=tat[i];
    printf("\nP[%d]\t%d\t%d\t%d",i+1,wt[i],tat[i],bt[i]);
}
avgwt/=i;
avgtat/=i;
printf("\nAvg wait time = %f",avgwt);
printf("\nAvg tat = %f ",avgtat);
return 0;
}



