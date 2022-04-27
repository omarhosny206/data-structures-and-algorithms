#include <bits/stdc++.h>
using namespace std;

void Swap(vector<int> &data, int i, int j)
{
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
}

int Partition(vector<int> &data, int left, int right)
{
    int pivot = data[left];
    int i = left;
    int j = right - 1;

    while (i < j)
    {
        while (pivot >= data[i])
            i++;

        while (pivot < data[j])
            j--;

        if (i < j)
            Swap(data, i, j);
    }

    Swap(data, left, j);
    return j;
}

void quickSort(vector<int> &data, int left, int right)
{
    if (left < right)
    {
        int pivot = Partition(data, left, right);
        quickSort(data, left, pivot);
        quickSort(data, pivot + 1, right);
    }
}

void Print(vector<int> &data)
{
    for (int &element : data)
        cout << element << endl;
}

int main()
{
    vector<int> data = {12, 9, 24, 6, 74, 38, 15};
    quickSort(data, 0, data.size());
    Print(data);
}