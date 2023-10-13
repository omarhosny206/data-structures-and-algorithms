#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &data)
{
    for (int i = 0; i < data.size(); ++i)
    {
        int minIndex = i;

        for (int j = i + 1; j < data.size(); ++j)
        {
            if (data[minIndex] > data[j])
            {
                minIndex = j;
            }
        }

        swap(data[i], data[minIndex]);
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
    selectionSort(data);
    Print(data);
}