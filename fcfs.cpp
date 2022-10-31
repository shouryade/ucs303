#include <bits/stdc++.h>
#define pb push_back
using namespace std;
struct process
{
    int burst;
    int pid;
    int arrival;
};

bool compTasks(process a, process b) // compare tasks and sort
{
    if (a.arrival == b.arrival)
        return a.pid < b.pid;
    return a.arrival < b.arrival;
}

void fcfs(process arr[], int n)
{
    vector<int> gantt;
    sort(arr, arr + n, compTasks);

    float totalwt = 0;
    int currtime = 0;
    int delay; // for the ones where cpu is idle before they arrive https://www.gatevidyalay.com/first-come-first-serve-cpu-scheduling/
    int WTPerProcess[n];
    int TAT[n];

    for (int i = 0; i < n; i++)
    {
        if (currtime <= arr[i].arrival)
        {
            delay = (arr[i].arrival - currtime);
            currtime += (arr[i].burst + delay);
            WTPerProcess[i] = 0;
            gantt.pb(arr[i].pid);
        }
        else
        {
            WTPerProcess[i] = currtime - arr[i].arrival;
            currtime += arr[i].burst;
            gantt.pb(arr[i].pid);
        }
    }

    float avgTAT = 0;
    for (int i = 0; i < n; i++)
    {
        totalwt += WTPerProcess[i];
        TAT[i] = (WTPerProcess[i] + arr[i].burst);
        avgTAT += TAT[i];
    }

    totalwt = (totalwt / n);
    avgTAT = (avgTAT / n);
    cout << "Average Waiting Time: " << totalwt << endl;
    cout << "Average Turnaround Time: " << avgTAT << endl;
    cout << "PID"
         << "\t\t"
         << "BT"
         << "\t\t"
         << "CT"
         << "\t\t"
         << "TAT"
         << "\t\t"
         << "WT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << gantt[i] << "\t\t" << arr[i].burst << "\t\t" << TAT[i] + arr[i].arrival << "\t\t" << TAT[i] << "\t\t" << WTPerProcess[i] << endl;
    }
    cout << "\n";

    cout << "Gantt Chart for the process is " << endl;
    for (auto x : gantt)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    cout << "enter number of processes: ";
    int n;
    cin >> n;
    process arr[n];

    cout << "enter process id, arrival time , burst time: \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i].pid >> arr[i].arrival >> arr[i].burst;

    fcfs(arr, n);

    return 0;
}
