
#include<iostream>
using namespace std;
int main(){

    int r,p,i,j,trace,c1=0,c2=0,flag=0;
    int avail[20],max[20][20],alloc[20][20],need[20][20],success[20];
    cout<<"Processes :";
    cin>>p;
    cout<<"\nResources :";
    cin>>r;
    for(i=0;i<p;i++)
        success[i]=0;


    cout<<"\nEnter available vector :";
    for(i=0;i<r;i++)
        cin>>avail[i];

    cout<<"\nEnter max allocation matrix\n";
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            cin>>max[i][j];
        }
    }

    cout<<"\nEnter allocated matrix\n";
     for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            cin>>alloc[i][j];
        }
    }

         for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    while(c1!=p){
        c2=c1;
        for(i=0;i<p;i++){
            for(j=0;j<r;j++){
                if(need[i][j]<=avail[j]){
                    trace++;
                }
            }
          if(trace==r && success[i]==0){
            cout<<i<<" ";
            success[i]=1;
            for(j=0;j<r;j++){
                avail[j]=avail[j]+alloc[i][j];
            }
            c1++;
          }
          trace=0;
        }
        if(c1==c2){
            cout<<"\nDEADLOCK";
            break;
        }
    }
return 0;
}
