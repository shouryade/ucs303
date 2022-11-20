#include <bits/stdc++.h>

using namespace std;

void worstFit(int block[], int b, int process[], int p)
{

    int allocation[p] = {-1};
    int max_index = 0, max;
    for (int i = 0; i < p; i++)
    {
        int max = -1;
        max_index = -1;
        for (int j = 0; j < b; j++)
        {
            if (block[j] - process[i] > max && block[j] - process[i] >= 0)
            {
                max_index = j;
                max = block[j] - process[i];
            }
        }

        if (max_index != -1)
        {
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
    int block[] = {100, 50, 30, 120, 35};
    int process[] = {40, 10, 30, 60};
    int b = sizeof(block) / sizeof(int);
    int p = sizeof(process) / sizeof(int);
    worstFit(block, b, process, p);
    return 0;
}