#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct process
{
    int pid;
    int burst;
    int arrival;
};

bool compTasks(process a, process b)
{
    if (a.arrival == b.arrival)
        return a.pid < b.pid;

    return a.arrival < b.arrival;
}

void fcfs(process arr[], int n)
{
    vector<int> gantt;
    sort(arr, arr + n, compTasks);

    float WTprocess[n];
    int delay;
    float TAT[n];
    WTprocess[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        WTprocess[i] = WTprocess[i - 1] + arr[i - 1].burst;
        gantt.pb(arr[i - 1].pid);
    }
    float avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++)
    {
        avgWT += WTprocess[i];
        TAT[i] = (arr[i].burst + WTprocess[i]);
        avgTAT += TAT[i];
    }

    for (int i = 0; i < n; i++)
    {
        TAT[i] = (arr[i].burst + WTprocess[i]);
        avgWT += WTprocess[i];
        avgTAT += TAT[i];
    }

    avgTAT /= n;
    avgWT /= n;

    cout << "Average Waiting Time: " << avgWT << endl;
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
        cout << gantt[i] << "\t\t" << arr[i].burst << "\t\t" << TAT[i] + arr[i].arrival << "\t\t" << TAT[i] << "\t\t" << WTprocess[i] << endl;
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
    int n;
    cout << "Enter number of processes : ";
    cin >> n;
    process arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter PID, arrival time, burst time : ";
        cin >> arr[i].pid >> arr[i].arrival >> arr[i].burst;
    }

    fcfs(arr, n);

    return 0;
}