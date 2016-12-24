#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
//#define buffersize 1

pthread_t tidP[20],tidC;
sem_t full,empty,mutex;
int counter,m,k,buffersize;
int buffer[100];

void initialize()
{
	sem_init(&full,0,0);
	sem_init(&empty,0,buffersize);
	sem_init(&mutex,0,1);
	counter=0;
}

void mywrite(int item)
{
	buffer[counter++]=item;
}

int myread()
{
	return(buffer[--counter]);
}

void * producer (void * param)
{
	int i;
	srand(time(NULL));
	while(1)
	{
		m=rand()%100;
		sem_wait(&empty);
		sem_wait(&mutex);
		printf("\nproducer no:%d got the lock\n",i);
		mywrite(m);
		printf("\nProducer put %d",m);
		printf("\nproducer no:%d returns the lock\n",i);
		sem_post(&mutex);
		//printf("\nproducer %ld returns the lock\n",tidP[i]);
		sem_post(&full);
		sleep(7);
	}
}

void * consumer (void * param)
{
	int i;
	 
	while(1)	
	{
		sem_wait(&full);
		printf("\ncustomer no:%d got the lock\n",i);
		sem_wait(&mutex);
		//printf("\ncustomer no:%d got the lock\n",i);
		i=myread();
		printf("\nConsumer got %d",i);
		printf("\ncustomer no:%d returns the lock\n",i);
		sem_post(&mutex);
		sem_post(&empty);
		sleep(7);
	}
}

int main()
{
	printf("\nEnter the buffer size: ");
	scanf("%d",&buffersize);
	int n1,n2,i;
	initialize();
	printf("\nEnter the no of producers: ");
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
		pthread_create(&tidP[i],NULL,producer,NULL);
	pthread_create(&tidC,NULL,consumer,NULL);
	for(i=0;i<n1;i++)
		pthread_join(tidP[i],NULL);
	pthread_join(tidC,NULL);
	exit(0);
}
