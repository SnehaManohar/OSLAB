#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
int size1=0,n=0,f=0,i=0,j=0,b=0,s=0;
int mem[100],mat[100][100],size[100];
string filename[100];
cin>>n;
for(f=0;f<n;f++)
cin>>filename[f]>>size[f];
cout<<endl;
for(f=0;f<n;f++)
cout<<filename[f]<<size[f];
cout<<endl;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
mat[i][j]=rand()%2;
}
}
cout<<endl;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
cout<<mat[i][j]<<" ";
}
cout<<endl;
}
int m=0;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
mem[m]=mat[i][j];
m++;
}
}
cout<<endl;
m++;
f=0;
i=0;
int k=0;
while(f!=n){
size1=size[f];
while(i<m){
	if(mem[i]==0){
		size1-=1;

		if(size1==0){
		cout<<filename[f]<<"has been allocated from"<<i-size[f]+2<<endl;
		i+=1;
		break;
	}	
	}
	else{
	size1=size[f];
	}
i++;
}
f++;
}
return 0;
}
