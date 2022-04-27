#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int> &data, int left, int right, int target)
{
    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (data[middle] == target)
            return true;

        if (data[middle] < target)
            left = middle + 1;

        else
            right = middle - 1;
    }

    return false;
}

int main()
{
    vector<int> data = {1, 2, 6, 8, 14, 15, 19, 25};

    (binarySearch(data, 0, data.size() - 1, 6) == true) ? cout << "True" << endl : cout << "False" << endl;
}