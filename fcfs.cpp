#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter Number of Processes\n";
    cin>>n;
    int burst_time[n];
    int wait_time[n];
    int turn_around_time[n];
    double sum_waiting_time = 0;
    double sum_turn_around_time = 0;
    cout<<"Enter Burst Time of Processes\n";
    for(int i=0;i<n;i++)
        cin>>burst_time[i];

    // Calculating Waiting Time
    wait_time[0] = 0;
    for(int i=1;i<n;i++)
        wait_time[i] = burst_time[i-1] + wait_time[i-1];

    //Calculating TAT
    for(int i=0;i<n;i++)
        turn_around_time[i] = burst_time[i] + wait_time[i];

    //Gantt Chart
	cout<<"\nGantt Chart :";
        for(int i=0;i<n;i++)
               cout<<"P["<<i+1<<"]\t";
   	cout<<"\n\t\t";
	 for(int i=0;i<n;i++)
        cout<<wait_time[i]<<"\t";
    cout<<turn_around_time[n-1]<<endl;
   
 // Computing Avg Wating time and TAT
    for(int i=0;i<n;i++)
    {
        sum_waiting_time += wait_time[i];
        sum_turn_around_time += turn_around_time[i];
    }
    cout<<"Average Waiting Time = "<<sum_waiting_time/n<<endl;
    cout<<"Average Turn Around Time = "<<sum_turn_around_time/n<<endl;

}

