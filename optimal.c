#include<stdio.h>
int n,f,i,page[20],fr[10];
void display(){
    for(i=0;i<f;i++)
        printf("%d ",fr[i]);
    printf("\n");
}

void request(){
printf("Enter the number of pages :");
scanf("%d",&n);
printf("\nEnter the size of page frame :");
scanf("%d",&f);
printf("\nEnter the pages : ");
for(i=0;i<n;i++){
    scanf("%d",&page[i]);
}
for(i=0;i<n;i++){
    fr[i]=-1;
}
}

void replace(){
    int j,nextp[10],flag=0,pf=0;
    int m,max,index;
    for(j=0;j<f;j++){
        fr[j]=page[j];
        pf++;
        flag=1;
        display();
    }
    for(j=f;j<n;j++){
        flag=0;
        for(i=0;i<f;i++){
            if(fr[i]==page[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            for(i=0;i<f;i++)
                nextp[i]=0;
            for(i=0;i<f;i++){
                for(m=j+1;m<n;m++){
                    if(fr[i]==page[m]){
                        nextp[i]=m-j;
                        break;
                    }
                }
            }
            max=nextp[0];
            index=0;
            for(i=0;i<f;i++){
                if(nextp[i]==0){
                    index=i;
                    break;
                }
                else{
                    if(max<nextp[i]){
                        max=nextp[i];
                        index=i;
                    }
                }
            }
            fr[index]=page[j];
            pf++;
            display();

        }
    }
    printf("\npage faults = %d ",pf);

}

int main(){
    request();
    printf("\nCache status is \n");
    replace();
    return 0;
}
