#include <bits/stdc++.h>

using namespace std;

void bestFit(int block[], int b, int process[], int p)
{

    int allocation[p];
    int min_index = 0, min;
    for (int i = 0; i < p; i++)
    {
        int min = 10000;
        for (int j = 0; j < b; j++)
        {
            if (block[j] - process[i] < min && block[j] - process[i] >= 0)
            {
                min_index = j;
                min = block[j] - process[i];
            }
        }
        allocation[i] = min_index;
        block[min_index] -= process[i];
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
            cout << "NA";
        }
    }
}

int main()
{
    int block[] = {100, 50, 30, 120, 35};
    int process[] = {40, 10, 30, 60};
    int b = sizeof(block) / sizeof(int);
    int p = sizeof(process) / sizeof(int);
    bestFit(block, b, process, p);
    return 0;
}