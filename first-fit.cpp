#include <bits/stdc++.h>
using namespace std;

void firstFit(int memBlock[], int process[], int n, int m)
{
    int allocation[m];
    for (int i = 0; i < m; i++)
    {
        allocation[i] = -1;
        cout << allocation[i] << endl;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (memBlock[j] >= process[i])
            {
                allocation[i] = j;
                memBlock[j] -= process[i];
                break;
            }
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < m; i++)
    {
        cout << " " << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main()
{
    int n;
    int m;
    cout << "Enter number of blocks : " << endl;
    cin >> n;
    int memBlock[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter size of block " << i + 1 << " : ";
        cin >> memBlock[i];
    }
    cout << "\n";

    cout << "Enter number of processes : " << endl;
    cin >> m;
    int process[m];

    for (int i = 0; i < m; i++)
    {
        cout << "Enter size of process " << i + 1 << " : ";
        cin >> process[i];
    }
    cout << "\n";

    firstFit(memBlock, process, n, m);

    return 0;
}
