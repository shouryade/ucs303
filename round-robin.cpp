#include <bits/stdc++.h>
#define pb push_back
using namespace std;

// questions verified with https://www.gatevidyalay.com/round-robin-round-robin-scheduling-examples/ and GateSmashers

struct process
{
    int pid;
    int arrival;
    int burst;
};

bool compTasks(process a, process b)
{
    if (a.arrival == b.arrival)
        return a.pid < b.pid;
    return a.arrival < b.arrival;
}

void rr(process arr[], int n, int tq)
{

    vector<process> tasks;
    tasks.assign(arr, arr + n);

    int CT[n];
    int completed = 0;
    int curtime = 0;
    vector<int> gantt;
    queue<int> readyq;

    sort(arr, arr + n, compTasks);
    // add initial task so that array is not empty
    for (int i = 0; i < n; i++)
    {
        if (curtime < arr[0].arrival)
        {
            curtime += tq;
        }
        if (curtime >= arr[0].arrival)
        {
            // cout << "Added initial task with pid " << i + 1 << endl;
            readyq.push(arr[i].pid);
            break;
        }
    }
    int k = 0;
    int tPID;
    while (!readyq.empty())
    {
        tPID = readyq.front();
        if (arr[tPID].burst >= tq)
        {
            curtime += tq;
            arr[tPID].burst = arr[tPID].burst - tq;
            // cout << tPID + 1 << endl;
            readyq.pop();
            gantt.pb(tPID);
        }
        else
        {
            curtime += arr[tPID].burst;
            arr[tPID].burst = 0;
            // cout << tPID + 1 << endl;
            readyq.pop();
            gantt.pb(tPID);
        }
        for (int i = k + 1; i < n; i++)
        {
            if (curtime >= arr[i].arrival && arr[i].burst != 0)
            {
                // cout << "Added task with pid" << i + 1 << endl;
                readyq.push(arr[i].pid);
                k++;
            }
        }

        if (arr[tPID].burst != 0)
            readyq.push(tPID);

        else
        {
            CT[tPID] = curtime;
            // cout << "Task with PID" << tPID + 1 << " finished" << endl;
        }
    }
    cout << "PID"
         << "\t\t"
         << "BT"
         << "\t\t"
         << "CT"
         << "\t\t"
         << "TAT"
         << "\t\t"
         << "WT" << endl;
    float avgWT = 0;
    float avgTAT = 0;
    for (int i = 0; i < n; i++)
    {
        cout << tasks[i].pid + 1 << "\t\t" << tasks[i].burst << "\t\t" << CT[i] << "\t\t" << CT[i] - tasks[i].arrival << "\t\t" << CT[i] - tasks[i].arrival - tasks[i].burst << endl;
        avgTAT += CT[i] - tasks[i].arrival;
        avgWT += CT[i] - tasks[i].arrival - tasks[i].burst;
    }
    cout << endl;
    cout << "Average Turnaround Time : " << avgTAT / n << endl;
    cout << "Average Waiting Time : " << avgWT / n << endl;
    cout << "Gantt Chart for the process is " << endl;
    for (auto x : gantt)
    {
        cout << x + 1 << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    int tq;
    cout << "Enter number of processes : ";
    cin >> n;
    cout << "Enter time quantum : ";
    cin >> tq;
    process arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].pid = i;
        cout << "Enter arrival time and burst time of process with PID " << i + 1 << endl;
        cin >> arr[i].arrival >> arr[i].burst;
    }
    rr(arr, n, tq);
    return 0;
}