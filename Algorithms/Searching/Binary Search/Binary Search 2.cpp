#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &data, int left, int right, int target)
{
    if (left > right)
        return false;

    int middle = left + (right - left) / 2;

    if (data[middle] == target)
        return true;

    if (data[middle] < target)
        return binarySearch(data, middle + 1, right, target);

    return binarySearch(data, left, middle - 1, target);
}

int main()
{
    vector<int> data = {1, 2, 6, 8, 14, 15, 19, 25};

    (binarySearch(data, 0, data.size() - 1, 6) == true) ? cout << "True" << endl : cout << "False" << endl;
}