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
    return a.burst < b.burst;
}

void sjf(process arr[], int n)
{
    vector<int> gantt;
    float curtime = 0;
    sort(arr, arr + n, compTasks);
    float WTprocess[n];
    int delay;

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
            curtime += arr[i].burst;
            gantt.pb(arr[i].pid);
        }
    }

    float avgWT = 0, avgTAT = 0;
    float TAT[n];

    for (int i = 0; i < n; i++)
    {
        avgWT += WTprocess[i];
        TAT[i] = (arr[i].burst + WTprocess[i]);
        avgTAT += TAT[i];
    }

    avgTAT /= n;
    avgWT /= n;

    cout << "The average waiting time is : " << avgWT << "\n";
    cout << "The average TAT is " << avgTAT << "\n";

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
    cout << "\nThe gantt chart is :\n";
    for (auto x : gantt)
    {
        cout << x + 1 << " ";
    }
}

int main()
{
    int n;
    cout << "Enter numebr of tasks : ";
    cin >> n;
    process arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Burst time of process " << i + 1 << " : ";
        cin >> arr[i].burst;
        arr[i].pid = i;
    }
    sjf(arr, n);
    return 0;
}