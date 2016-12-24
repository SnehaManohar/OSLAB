#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
 int i,j,mat[5][6],blocks,filesize;
 cout<<"\nEnter file size :";
 cin>>filesize;
 blocks=filesize*1024/512;
 cout<<"\nNo of blocks needed = "<<blocks;
 for(i=0;i<6;i++){
    for(j=0;j<6;j++){
        mat[i][j]=rand()%2;
    }
 }
 cout<<"\nMemory initially is \n";
 for(i=0;i<6;i++){
    for(j=0;j<6;j++){
        cout<<mat[i][j]<<" ";
    }
    cout<<endl;
 }
 int arr[150]={0};
 int p=0,k=0;
 for(i=0;i<6;i++){
    for(j=0;j<6;j++,p++){
        arr[p]=mat[i][j];
    }
 }
for(i=0;i<p;i++){
cout<<arr[i]<<"\n";
} for(i=0;i<p;i++){
    if(arr[i]==1){
        k++;
        if(k==blocks){

            break;
        }
    }
    else{
        k=0;
    }
 }

cout<<"Start addr :"<<i-blocks+1;
int q=i-blocks+1;

for(j=q;j<q+blocks;j++){
    arr[j]=0;
}
int n[6][6];
int temp=0;
for(i=0;i<6;i++){
    for(j=0;j<6;j++,temp++){
        n[i][j]=arr[temp];
    }
}

cout<<"\n\nNew matrix\n";
for(i=0;i<6;i++){
    for(j=0;j<6;j++){
        cout<<n[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}




