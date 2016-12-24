#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct filestruct{
    	int blockNum;
    	struct filestruct* nextBlock;
};
struct filestruct* head= NULL;
int n=0;
void addBlock(int n){
    	struct filestruct* temp =(struct filestruct*)malloc(sizeof(struct filestruct));
    	temp->blockNum= n;
    	temp -> nextBlock= NULL;
    	if(head= NULL){
        	head= temp;
        	return;
    	}
    	else{
        	temp -> nextBlock= head;
        	head= temp;
    	}	
}
void printBlock(){
    	struct filestruct* temp = head;
    	while(temp!=NULL){
        	printf("\nBlock number is : %d",temp->blockNum);
        	temp=temp->nextBlock;
    	}
}
int main(){
    	char fname[30];
    	int size, num, memory[10][10],i,j,i1,j1,k,count=1,index;
    	float numBlocks;
    	printf("\nEnter the filename: ");
    	scanf("%s",fname);
    	//srand(time(NULL));
    	printf("\nEnter the size of the file is kB: ");
    	scanf("%d",&size);
    	if(size%512==0)
        	numBlocks=size/512;
    	else if(size<=0)
        {
        	printf("\nError in size of file\n");
        	return -1;
	}
    	else
        	numBlocks=size/512+1;
    	if((numBlocks-(int)numBlocks)==0.0) 
    		num= (int)numBlocks;
    	else 
    		num=(int)numBlocks+1;
    	for(i=0;i<10;i++) 
    		for(j=0;j<10;j++) 
    			memory[i][j]= rand()%2;
    	printf("\nInitial memory map: \n");
    	for(i=0;i<10;i++){
        	for(j=0;j<10;j++)
            		printf("%d\t",memory[i][j]);
        	printf("\n");
    	}
    	for(i=0;i<10;i++){
        	for(j=0;j<10;j++){
            		if(memory[i][j]==1){
                		index=i*5+j;
                		addBlock(index);
                		memory[i][j]=0;
                		count++;
            		}
            		if(count>num) break;
        	}
        	if(count>num) break;
    	}
    	printf("\nFinal memory map: \n");
    	for(i=0;i<10;i++){
        	for(j=0;j<10;j++)
            		printf("%d\t",memory[i][j]);
        	printf("\n");
    	}
}
