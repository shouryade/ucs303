#include <bits/stdc++.h>
#define pb push_back
#define max 3
using namespace std;

struct process
{
    int pid;
    bool status = false;
    int alloc[max] = {0};
    int need[max] = {0};
};

bool useBankers(process arr[], int avail[max], int n)
{

    int safeSeq[n];
    int completed = 0;

    while (completed != n)
    {
        bool processFound = false;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].status == false)
            {

                int j;
                for (j = 0; j < max; j++)
                {
                    if (arr[i].need[j] > avail[j])
                    {
                        break;
                    }
                }
                if (j == max)
                {
                    for (int k = 0; k < max; k++)
                    {
                        avail[k] += arr[i].alloc[k];
                    }
                    processFound = true;
                    safeSeq[completed] = arr[i].pid;
                    arr[i].status = true;
                    completed++;
                }
            }
        }

        if (processFound == false)
        {
            cout << "The system is not in a safe state!\n ";
            return false;
        }
    }
    cout << "System is in safe state.\nThe corresponding Safe Sequence is : ";
    for (auto x : safeSeq)
        cout << x << "->";
    cout << "END\n";
    return true;
}

int main()
{
    int avail[max];
    int n;
    cout << "Enter number of processes : ";
    cin >> n;
    cout << "Currently there are " << max << " types of resources in the system."
         << "\n";
    for (int i = 0; i < max; i++)
    {
        cout << "Please enter the avaiable instances for resource R" << i + 1 << ": ";
        cin >> avail[i];
    }
    cout << "\n";

    process arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i].pid = i + 1;
        cout << "For process P" << i + 1 << ":\n";
        for (int j = 0; j < max; j++)
        {
            cout << "Enter the allocated instances of resource R" << j + 1 << ": ";
            cin >> arr[i].alloc[j];
        }
        for (int j = 0; j < max; j++)
        {
            cout << "Enter the maximum needed instances of resource R" << j + 1 << ": ";
            cin >> arr[i].need[j];
            arr[i].need[j] -= arr[i].alloc[j];
        }
        cout << "\n";
    }

    useBankers(arr, avail, n);

    return 0;
}