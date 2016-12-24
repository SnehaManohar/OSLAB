#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int i,j,mat[5][6],blocks,filesize,q,n[50][50],temp = 0, arr[150], p=0, k=0;
	cout<<"\nEnter file size :";
	cin>>filesize;
	if(filesize%512==0)
        	blocks=filesize/512;
    	else if(filesize<=0)
        {
        	cout<<"Error in size of file\n";
        	return -1;
	}
    	else
        	blocks=filesize/512+1;
	cout<<"\nNo of blocks needed = "<<blocks;
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
	       		mat[i][j]=rand()%2;
	cout<<"\nMemory initially is \n";
	for(i=0;i<10;i++){
	   	for(j=0;j<10;j++)
	       		cout<<mat[i][j]<<" ";
	   	cout<<endl;
	}
	for(i=0;i<10;i++)
	   	for(j=0;j<10;j++,p++)
	       		arr[p]=mat[i][j];
	for(i=0;i<p;i++){
	   	if(arr[i]==1){
	       		k++;
	       		if(k==blocks)
	           		break;
	    	}	
		else
	        k=0;
	}
	cout<<"Start addr :"<<512*(i-blocks+1);
	q=i-blocks+1;
	cout<<"\n"<<q<<"\t"<<q+blocks;
	for(j=q;j<q+blocks;j++)
	    	arr[j]=0;
	for(i=0;i<10;i++)
	    	for(j=0;j<10;j++,temp++)
	        	n[i][j]=arr[temp];
	cout<<"\n\nNew matrix\n";
	for(i=0;i<10;i++){
	    	for(j=0;j<10;j++)
	        	cout<<n[i][j]<<" ";
	    	cout<<endl;
	}
	return 0;
}
