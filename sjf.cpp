#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct process
{
    int pid;
    int arrival = 0; // constraint given for sjf with arrival time=0
    int burst;
};

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

void sjfnon(process arr[], int n)
{
    vector<int> gantt;
    sort(arr, arr + n, compTasks);

    float totalwt = 0;
    int currtime = 0;
    int WTPerProcess[n];
    int delay;
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

    cout << "enter process id, burst time (arrival time is same, ie 0): \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i].pid >> arr[i].burst;

    sjfnon(arr, n);

    return 0;
}
