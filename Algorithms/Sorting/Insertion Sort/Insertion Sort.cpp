#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &data)
{
    for (int i = 1; i < data.size(); ++i)
    {
        int value = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > value)
        {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = value;
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
    insertionSort(data);
    Print(data);
}