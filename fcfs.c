#include<stdio.h>
int main(){
int n,i,j,bt[10],wt[10],tat[10];
float avgwt=0.0,avgtat=0.0;

printf("Enter the number of processes :");
scanf("%d",&n);
printf("\nEnter the burst times :");
for(i=0;i<n;i++){
    printf("\nP[%d] :",i+1);
    scanf("%d",&bt[i]);
}
wt[0]=0;
for(i=0;i<n;i++){
    wt[i]=0;
    for(j=0;j<i;j++){
        wt[i]+=bt[j];
    }
}
printf("\n\nProcess\tWait time\tTat\tBurst\n");
for(i=0;i<n;i++){
    tat[i]=wt[i]+bt[i];
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


