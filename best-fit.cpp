#include <bits/stdc++.h>
using namespace std;

void bestFit(int memBlock[], int process[], int n, int m)
{
    int allocation[m];
    for (int i = 0; i < m; i++)
    {
        allocation[i] = -1;
        cout << allocation[i] << endl;
    }

    for (int i = 0; i < m; i++)
    {

        int besti = -1;
        for (int j = 0; j < n; j++)
        {
            if (memBlock[j] >= process[i])
            {
                if (besti == -1)
                    besti = j;
                else if (memBlock[besti] > memBlock[j])
                    besti = j;
            }
        }

        if (besti != -1)
        {

            allocation[i] = besti;

            memBlock[besti] -= process[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < m; i++)
    {
        cout << "   " << i + 1 << "\t\t" << process[i] << "\t\t";
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

    bestFit(memBlock, process, n, m);

    return 0;
}
