#include<iostream>
using namespace std;
int fr[20],pages[20];
int main(){
    int p,f,i,j,k=0,miss=0,flag=0;
    cout<<"\nEnter the number of pages :";
    cin>>p;
    cout<<"\nEnter the pages :";
    for(i=0;i<p;i++){
        cin>>pages[i];
    }
    cout<<"\nEnter the frame size :";
    cin>>f;
    for(j=0;j<f;j++){
        fr[j]=999;
    }
    cout<<"\nThe cache status is \n";
    i=0;
    while(i<p){
        flag=0;
        for(j=0;j<f;j++){
            if(fr[j]==pages[i]){
                flag=1;

            }
        }
        if(flag==1){
            i++;
        }
        else{
            miss++;
            fr[k]=pages[i];
            i++;
            k++;
            if(k==f){
                k=0;
            }
        }
        for(j=0;j<f;j++)
            cout<<fr[j]<<" ";
        cout<<endl;

    }

    cout<<"\nNo of page faults = "<<miss;

return 0;
}


