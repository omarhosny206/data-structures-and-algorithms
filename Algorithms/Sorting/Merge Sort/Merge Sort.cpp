#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &data, int left, int right, int middle)
{
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
    vector<int> leftElements(leftSize);
    vector<int> rightElements(rightSize);

    for (int i = 0; i < leftElements.size(); ++i)
        leftElements[i] = data[left + i];

    for (int i = 0; i < rightElements.size(); ++i)
        rightElements[i] = data[middle + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < leftElements.size() && j < rightElements.size())
    {
        if (leftElements[i] <= rightElements[j])
            data[k++] = leftElements[i++];

        else
            data[k++] = rightElements[j++];
    }

    while (i < leftElements.size())
    {
        data[k++] = leftElements[i++];
    }

    while (j < rightElements.size())
    {
        data[k++] = rightElements[j++];
    }
}

void mergeSort(vector<int> &data, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;
        mergeSort(data, left, middle);
        mergeSort(data, middle + 1, right);
        Merge(data, left, right, middle);
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
    mergeSort(data, 0, data.size() - 1);
    Print(data);
}