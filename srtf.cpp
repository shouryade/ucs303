#include <bits/stdc++.h>
#define pb push_back
using namespace std;

// see https://www.gatevidyalay.com/sjf-scheduling-srtf-cpu-scheduling/ for questions

struct process
{
    int pid;
    int arrival;
    int burst;
};

// comparator function for sorting tasks in order of arrival
bool compTasks(process a, process b)
{
    if (a.arrival == b.arrival)
    {
        if (a.burst == b.burst)
            return a.pid < b.pid;
        return a.burst < b.burst;
    }
    return a.arrival < b.arrival;
}

void srtf(process arr[], int n)
{
    vector<int> gantt;
    vector<process> tasks;
    tasks.assign(arr, arr + n);

    int CT[n];
    int curtime = 0;
    sort(arr, arr + n, compTasks);
    int completed = 0;
    int min = 0;
    while (completed != n)
    {
        if (curtime < arr[0].arrival)
        {
            curtime++;
        }
        int i;
        if (arr[min].burst == 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i].burst > 0 && arr[i].arrival <= curtime)
                {

                    min = i;
                }
            }
        }

        for (i = 0; i < n; i++)
        {
            if (arr[i].arrival <= curtime && arr[i].burst != 0)
            {
                if (arr[min].burst > arr[i].burst)
                {
                    min = i;
                }
                else if (arr[min].burst == arr[i].burst) // least arrival time to be taken in case of same burst time
                {
                    if (arr[min].arrival == arr[i].arrival)
                    {
                        min = (arr[i].pid < arr[min].pid) ? i : min; // least pid to be taken if arrival is same
                    }
                    else
                    {
                        min = (arr[i].arrival < arr[min].arrival) ? i : min;
                    }
                }
            }
        }
        gantt.pb(arr[min].pid);
        curtime++;
        arr[min].burst--;
        if (arr[min].burst == 0)
        {
            completed++;
            CT[arr[min].pid] = curtime;
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
        cout << tasks[i].pid << "\t\t" << tasks[i].burst << "\t\t" << CT[i] << "\t\t" << CT[i] - tasks[i].arrival << "\t\t" << CT[i] - tasks[i].arrival - tasks[i].burst << endl;
        avgTAT += CT[i] - tasks[i].arrival;
        avgWT += CT[i] - tasks[i].arrival - tasks[i].burst;
    }
    cout << endl;
    cout << "Average Turnaround Time : " << avgTAT / n << endl;
    cout << "Average Waiting Time : " << avgWT / n << endl;
    cout << "Gantt Chart for the process is " << endl;
    for (auto x : gantt)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter number of processes : ";
    cin >> n;
    process arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].pid = i;
        cout << "Enter arrrival time and burst time of process with PID " << i << endl;
        cin >> arr[i].arrival >> arr[i].burst;
    }
    srtf(arr, n);
    return 0;
}