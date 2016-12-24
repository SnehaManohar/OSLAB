#include<iostream>
using namespace std;

int main(){
 int proc[10],mem[10],done[10],i,j,m,p;
 cout<<"\nEnter number of memory slots :";
 cin>>m;
 cout<<"\nEnter the number of processes :";
 cin>>p;
 cout<<"\nEnter the memory values :";
 for(i=0;i<m;i++){
    cin>>mem[i];
 }
 cout<<"\nEnter the process values :";
 for(i=0;i<p;i++){
    cin>>proc[i];
    done[i]=0;
 }

 int temp;
 for(int k=0;k<m;k++){
    for(int l=k;l<m-1;l++){
        if(mem[l+1]<mem[l]){
          temp=mem[l];
          mem[l]=mem[l+1];
          mem[l+1]=temp;
        }
    }
 }

 for(i=0;i<m;i++){
    cout<<mem[i]<<" ";
 }



 for(i=0;i<p;i++){
    for(j=0;j<m;j++){
        if(proc[i]<=mem[j] && done[i]==0){
            cout<<"P"<<i<<" allocated. "<<proc[i]<<"-->"<<mem[j]<<"\t";
            mem[j]-=proc[i];
            cout<<"Internal frag :"<<mem[j]<<endl;
            done[i]=1;
        }
    }
 }

 for(i=0;i<p;i++){
    if(done[i]!=1){
        cout<<"\n\nProcess "<<i<<" isnt allocated!";
    }
 }


return 0;
}



