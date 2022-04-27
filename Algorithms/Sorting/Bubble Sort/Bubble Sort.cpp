#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &data)
{
    for (int i = 0; i < data.size(); ++i)
    {
        for (int j = 0; j < data.size() - i; ++j)
        {
            if (data[j] > data[j + 1])
            {
                swap(data[j], data[j + 1]);
            }
        }
    }
}

void Print(vector<int> &data)
{
    for (int &element : data)
        cout << element << endl;
}

int main()
{
    vector<int> data = {14, 8, 2, 15, 6, 1, 25, 19};
    bubbleSort(data);
    Print(data);
}