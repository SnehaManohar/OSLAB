#include<iostream>
using namespace std;

int main()
{
    cout << "ENTER NUMBER OF PROCESSES : ";
    int n;
    cin >> n;
    int currTime = 0;
    int arr[n];
    int b[n];
    cout << "ENTER BURST TIME FOR EACH : ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++) b[i] = arr[i];
    int timeSlice;
    cout << "ENTER TIME SLICE : ";
    cin >> timeSlice;
    int i = 0;
    int waitingTime[n];
    int alreadyRun[n];
    int turnAroundTime[n];
    for(int j = 0; j < n; j++)
        waitingTime[j] = alreadyRun[j] = 0;

    while(true)
    {
        int nonZero = 0;
        for(int j = 0; j < n; j++)
            nonZero += (arr[j] > 0);
        if(!nonZero)
            break;
        while(arr[i] == 0)

            i = (i + 1) % n;
        int t = min(timeSlice , arr[i]);
        waitingTime[i] = currTime - alreadyRun[i];
        arr[i] -= t;
        alreadyRun[i] += t;
        turnAroundTime[i] = waitingTime[i] + b[i];
        cout << "Process " << (i+1) << " - (" << currTime << " , " << (currTime + t) << ")" << endl;
        currTime += t;
        i = (i + 1) % n;
    }

    for(int i = 0; i < n; i++)
        cout << "WAITING TIME for " << (i+1) << " : " << waitingTime[i] << endl;
    for(int i = 0; i < n; i++)
        cout << "TA TIME for " << (i+1) << " : " << turnAroundTime[i] << endl;

    cout << "END" << endl;
    return 0;
}
