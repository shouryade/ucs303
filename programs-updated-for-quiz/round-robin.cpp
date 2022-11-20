#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct process
{
    int pid;
    int arrival = 0;
    int burst;
};

bool compTasks(process a, process b)
{
    if (a.arrival == b.arrival)
    {
        return a.pid < b.pid;
    }
    return a.arrival < b.arrival;
}

void rr(process arr[], int n, int tq)
{
    vector<int> gantt;
    vector<process> tasks;
    tasks.assign(arr, arr + n);
    queue<int> readyq;

    sort(arr, arr + n, compTasks);

    int curtime = 0;

    for (int i = 0; i < n; i++)
        readyq.push(arr[i].pid);
    cout << "All tasks have been inserted to ready queue!\n";

    int cPID;
    int CT[n];
    while (!readyq.empty())
    {
        cPID = readyq.front();
        if (arr[cPID].burst >= tq)
        {
            curtime += tq;
            arr[cPID].burst -= tq;
            readyq.pop();
            gantt.pb(cPID);
        }
        else
        {

            curtime += arr[cPID].burst;
            arr[cPID].burst = 0;

            gantt.pb(cPID);
        }
        if (arr[cPID].burst != 0)
        {
            readyq.push(cPID);
        }
        else
        {
            CT[cPID] = curtime;
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
        cout << tasks[i].pid + 1 << "\t\t" << tasks[i].burst << "\t\t" << CT[i] << "\t\t" << CT[i] - tasks[i].arrival << "\t\t" << CT[i] - tasks[i].arrival - tasks[i].burst << "\n";
        avgTAT += CT[i] - tasks[i].arrival;
        avgWT += CT[i] - tasks[i].arrival - tasks[i].burst;
    }

    cout << avgTAT / n << endl;
    cout << avgWT / n << endl;
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
    cout << "Enter number of tasks : ";
    cin >> n;
    process arr[n];
    cout << "Enter time quantum : ";
    cin >> tq;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Burst time of process with PID " << i + 1 << " : ";
        cin >> arr[i].burst;
        arr[i].pid = i;
    }
    cout << endl;
    rr(arr, n, tq);

    return 0;
}
