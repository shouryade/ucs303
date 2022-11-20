#include <bits/stdc++.h>

using namespace std;

void worstFit(int block[], int b, int process[], int p)
{

    int allocation[p];
    for (int i = 0; i < p; i++)
    {
        allocation[i] = -1;
    }

    int max_index;
    for (int i = 0; i < p; i++)
    {

        max_index = -1;
        for (int j = 0; j < b; j++)
        {

            if (block[j] - process[i] >= 0)
            {

                max_index = j;
                break;
            }
        }
        if (max_index != -1)
        {
            cout << process[i] << endl;
            cout << block[max_index] << endl;
            allocation[i] = max_index;
            block[max_index] -= process[i];
        }
    }
    cout << "PID\t\t"
         << "Size\t\t"
         << "Block No.\n";
    for (int i = 0; i < p; i++)
    {
        if (allocation[i] >= 0)
        {

            cout << i + 1 << "\t\t" << process[i] << "\t\t" << allocation[i] + 1 << "\n";
        }
        else
        {
            cout << i + 1 << "\t\t" << process[i] << "\t\t"
                 << "NA"
                 << "\n";
        }
    }
}

int main()
{
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int b = sizeof(block) / sizeof(int);
    int p = sizeof(process) / sizeof(int);
    worstFit(block, b, process, p);
    return 0;
}