
#include<iostream>
using namespace std;
int main(){
    int i,j,p,r,alloc[20][20],req[20][20],avail[20],success[20],flag=0,c1=0,c2=0,track=0;
    cout<<"Processes :";
    cin>>p;
    cout<<"\nResources :";
    cin>>r;
    cout<<"\nEnter the available vector :";
    for(i=0;i<r;i++){
        cin>>avail[i];
    }
    for(i=0;i<p;i++){
        success[i]=0;
    }
    cout<<"\nEnter the allocated matrix\n";
    for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            cin>>alloc[i][j];
        }
    }
    cout<<"\nEnter the request matrix\n";
     for(i=0;i<p;i++){
        for(j=0;j<r;j++){
            cin>>req[i][j];
        }
    }

    while(c1!=p){
        c2=c1;
        for(i=0;i<p;i++){
            for(j=0;j<r;j++){
                if(req[i][j]<=avail[j]){
                    track++;
                }
            }
            if(track==r && success[i]==0){
                success[i]=1;
                for(j=0;j<r;j++)
                    avail[j]=avail[j]+alloc[i][j];
                c1++;
            }
            track=0;
        }
        if(c1==c2){
            cout<<"\nDeadlock present!";
            flag=1;
            break;
        }
    }
    if(flag){
        for(j=0;j<p;j++){
            if(success[j]!=1){
                cout<<" P"<<j;
            }

        }

    }
    else{
        cout<<"No deadlock!";
    }

return 0;
}
