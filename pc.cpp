#include<bits/stdc++.h>
#include<unistd.h>
#include<mutex> // mutex is used to lock and unlock sections of the code - critical section 
#include<thread>
using namespace std;

std::mutex x,y;	// locking elements 
int n,num_producer;

vector<int> buffer;	// shared resource 
int _front;
int _rear;

int produce()
{
    int item = rand()%100000; // produces an item 
    cout<<"Item Produced : "<<item<<endl;
    return item;
}
void append(int item)
{
    if((_rear+1)%n == _front)
    {
        cout<<"-----------Buffer Full-----------------"<<endl;
        return;
    }
    cout<<"Appending to Buffer"<<endl;
    y.lock();
    _rear = (_rear + 1)%n;
    buffer[_rear] = item;
    y.unlock();
}
void producer()
{

    int item = produce();
    cout<<"Producer - "<<this_thread::get_id()<<" : Locking Buffer"<<endl;  // gets the id of the thread . Assigned by OS
    x.lock();
    append(item);
    cout<<"Producer : Unlocking Buffer"<<endl;
    x.unlock();
}
void consume(int item)
{
    cout<<"Item Consumed : "<<item<<endl;
}
int take()
{
    if(_rear == _front)
    {
        cout<<"------------- Buffer Empty ----------"<<endl;
        return -1;
    }
    y.lock();
    _front = (_front+1)%n;
    int temp = buffer[_front];
    y.unlock();
    return temp;
}
void consumer()
{
    cout<<"Consumer - "<<std::this_thread::get_id()<<": Locking Buffer"<<endl;
    x.lock();
    int item = take();
    if(item != -1)
        cout<<"Consumer : Unlocking Buffer"<<endl;
    x.unlock();
    consume(item);
}

void start_producer() // start point for a producer thread
{
	while(true)
    {
    	producer();
    	sleep(1);
	}
} 

void start_consumer() // start point for a consumer thread
{
	while(true)
    {
    	consumer();
    	sleep(1);
	}
}

int main()
{
    cout<<"Enter buffer size"<<endl;
    cin>>n;
    cout<<"Enter the number of Producers\n";
    cin>>num_producer;

    //housekeeping
    buffer.resize(n);
    _front = -1;
    _rear = -1;

    thread producer_thread[num_producer];  //creating an array of producer threads
    thread consumer_thread; // a consumer thread

    // starting producers 
    for(int i=0;i<n;i++)
        producer_thread[i] = thread(start_producer); 

    //starting consumer
	consumer_thread = thread(start_consumer);

    //joining running threads 

    for(int i=0;i<num_producer;i++)
        producer_thread[i].join();  

    consumer_thread.join();

    //end
}
