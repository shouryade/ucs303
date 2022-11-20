#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct process
{
    int pid;
    int arrival = 0;
    int burst;
    int priority;
};

bool compTasks(process a, process b)
{
    return a.priority > b.priority;
}

void priorityNon(process arr[], int n)
{
    vector<int> gantt;
    sort(arr, arr + n, compTasks);

    int delay;
    float WTprocess[n];
    float TAT[n];
    float curtime = 0;
    for (int i = 0; i < n; i++)
    {
        if (curtime <= arr[i].arrival)
        {
            delay = (arr[i].arrival - curtime);
            curtime += (delay + arr[i].burst);
            WTprocess[i] = 0;
            gantt.pb(arr[i].pid);
        }
        else
        {
            WTprocess[i] = (curtime - arr[i].arrival);
            curtime += (arr[i].burst);
            gantt.pb(arr[i].pid);
        }
    }

    float avgTAT = 0;
    float avgWT = 0;
    for (int i = 0; i < n; i++)
    {
        avgWT += WTprocess[i];
        TAT[i] = (WTprocess[i] + arr[i].burst);
        avgTAT += TAT[i];
    }
    cout << ""
}

int main()
{
    int n;
    cout << "Enter number of processes : ";
    cin >> n;
    process arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the burst time and priority of process with PID " << i + 1 << endl;
        cin >> arr[i].burst >> arr[i].priority;
    }
    cout << endl;
    priorityNon(arr, n);

    return 0;
}