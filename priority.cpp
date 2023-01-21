#include <bits/stdc++.h>
#define pb push_back
using namespace std;

// please watch https://www.youtube.com/watch?v=rsDGfFxSgiY for reference
struct process
{
    int pid;
    int arrival;
    int burst;
    int priority;
};

// comparator function for sorting tasks in order of arrival
bool compTasks(process a, process b)
{
    if (a.arrival == b.arrival)
    {
        return a.priority < b.priority;
    }
    return a.arrival < b.arrival;
}

void priority(process arr[], int n)
{
    vector<int> gantt;
    vector<process> tasks;
    tasks.assign(arr, arr + n);

    int CT[n];
    int curtime = 0;
    sort(arr, arr + n, compTasks);
    int completed = 0;
    int max = 0;
    while (completed != n)
    {
        if (curtime < arr[0].arrival)
        {
            curtime++;
        }

        int i;
        if (arr[max].burst == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i].burst > 0 && arr[i].arrival <= curtime)
                {

                    max = i;
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            if (arr[i].arrival <= curtime && arr[i].burst != 0)
            {
                if (arr[i].priority >= arr[max].priority)
                {
                    max = i;
                }
            }
        }
        gantt.pb(arr[max].pid);
        curtime++;
        arr[max].burst--;
        if (arr[max].burst == 0)
        {
            completed++;
            CT[arr[max].pid] = curtime;
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
    cout << "Priority scheduling algorithm, with pre-emption, higher number = higher priority !" << endl;
    cout << "Enter number of processes : ";
    cin >> n;
    process arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].pid = i;
        cout << "Enter priority, arrrival time and burst time of process with PID " << i + 1 << endl;
        cin >> arr[i].priority >> arr[i].arrival >> arr[i].burst;
    }
    priority(arr, n);
    return 0;
}