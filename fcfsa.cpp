#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter Number of Processes\n";
    cin>>n;

    int burst_time[n];
    int wait_time[n];
    int time_line[n]; // gantt chart
    int turn_around_time[n];
    int arrival_time[n+1];

    double sum_waiting_time = 0;
    double sum_turn_around_time = 0;

    cout<<"Enter Burst Time and Arrival Time of Processes\n";
    for(int i=0;i<n;i++)
    {
        cin>>burst_time[i];
        cin>>arrival_time[i];
    }
    // Calculating Waiting Time
    wait_time[0] = 0;
    time_line[0] = arrival_time[0];

    for(int i=1;i<n;i++)
    {
        time_line[i] = burst_time[i-1] + time_line[i-1];
        wait_time[i] = burst_time[i-1] + time_line[i-1] - arrival_time[i];
    }
    time_line[n] = time_line[n-1] + burst_time[n-1];
  
  //Calculating TAT
    for(int i=0;i<n;i++)
        turn_around_time[i] = burst_time[i] + time_line[i] - arrival_time[i];

    //Gantt Chart
    for(int i=0;i<=n;i++)
        cout<<time_line[i]<<"\t";
    // Computing Avg Wating time and TAT

    for(int i=0;i<n;i++)
    {
        sum_waiting_time += wait_time[i];
        sum_turn_around_time += turn_around_time[i];
    }
    cout<<"\nAverage Waiting Time = "<<sum_waiting_time/n<<endl;
    cout<<"Average Turn Around Time = "<<sum_turn_around_time/n<<endl;

}

