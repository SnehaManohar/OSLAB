#include<omp.h>
#include<stdio.h>
#define n 15
int main(int argc,char *argv[])
{
int numthreads,i,t;
int a[100],b[100],c[100]={0},d[100]={0};
for(i=0;i<n;i++){
a[i]=i*3;
b[i]=i*2;
}
#pragma omp parallel shared(a,b,c,d,numthreads) private(t,i)
{
t=omp_get_thread_num();
if(t==0){
	numthreads=omp_get_num_threads();
	printf("%d is the number of threads\n",numthreads);
}
printf("thread %d is running..\n",t);
#pragma omp sections nowait
{
	#pragma omp section
	{
	printf("thread %d is running section1\n",t);
	for(i=0;i<n;i++){
	c[i]=a[i]-b[i];
	}
	for(i=0;i<n;i++)
	{
	printf("%d\t",c[i]);
	}
	}
	#pragma omp section
	{
	printf("thread %d is running section2\n",t);
	for(i=0;i<n;i++){
	d[i]=a[i]+b[i];
	}
	for(i=0;i<n;i++)
	{
	printf("%d\t",d[i]);
	}
	}
}
printf("thread %d stopped running\n",t);
}
}

