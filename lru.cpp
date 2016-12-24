#include<iostream>
using namespace std;
int fr[20],pages[20];
int main(){
    int i,j,k=0,p,f,flag=0,miss=0;
    cout<<"\nEnter the number of pages :";
    cin>>p;
    cout<<"\nEnter the frame size :";
    cin>>f;
    cout<<"\nEnter the pages :";
    for(i=0;i<p;i++){
        cin>>pages[i];
    }
    for(j=0;j<f;j++){
        fr[j]=999;
    }

    cout<<"\nCache status is\n";
    for(j=0;j<f;j++){
        fr[j]=pages[j];
        for(i=0;i<f;i++)
            cout<<fr[i]<<" ";
        cout<<endl;
    }
    miss=f;
    for(i=f;i<p;i++){
        k=0;
        for(j=0;j<f;j++){
            if(fr[j]==pages[i]){
                continue;
            }
            else{
                k++;
            }
        }
        if(k==f){
            miss++;
            for(j=0;j<f;j++){
               if(fr[j]==pages[i-f]){
                 fr[j]=pages[i];
               }
            }
        }
            for(j=0;j<f;j++)
                cout<<fr[j]<<" ";
            cout<<endl;


        }
        cout<<"\nFaults : "<<miss;
return 0;
}


