#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &data, int target)
{
    for (int &element : data)
        if (element == target)
            return true;

    return false;
}

int main()
{
    vector<int> data = {14, 8, 2, 15, 6, 1, 25, 19};

    (linearSearch(data, 6) == true) ? cout << "True" << endl : cout << "False" << endl;
}