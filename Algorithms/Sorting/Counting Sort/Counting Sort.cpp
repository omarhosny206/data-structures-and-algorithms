#include <bits/stdc++.h>
using namespace std;

void countFrequency(vector<int> &data, vector<int> &count)
{
    for (int &element : data)
        count[element]++;
}

void makeEnd(vector<int> &count)
{
    for (int i = 1; i < count.size(); ++i)
        count[i] += count[i - 1];
}

void makeStart(vector<int> &count)
{
    for (int i = count.size() - 1; i >= 1; --i)
        count[i] = count[i - 1];
}

vector<int> countingSort(vector<int> &data)
{
    vector<int> result(data.size());
    int range = *max_element(data.begin(), data.end());
    vector<int> count(range + 1);

    countFrequency(data, count);
    makeEnd(count);
    makeStart(count);

    count[*min_element(data.begin(), data.end())] = 0;

    for (int &element : data)
    {
        result[count[element]] = element;
        count[element]++;
    }

    return result;
}

void Print(vector<int> &data)
{
    for (int &element : data)
        cout << element << endl;
}

int main()
{
    vector<int> data = {5, 4, 8, 1, 1, 3, 4, 5, 1, 0};
    vector<int> result = countingSort(data);
    Print(result);
}