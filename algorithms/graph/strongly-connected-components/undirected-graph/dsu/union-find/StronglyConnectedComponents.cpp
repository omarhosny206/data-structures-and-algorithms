#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> graph;
    vector<int> parent;

public:
    Graph(vector<vector<int>> &data)
    {
        this->graph = data;
        this->parent = vector<int>(graph.size(), -1);
    }

    int stronglyConnectedComponents()
    {
        int result = graph.size();

        for (int i = 0; i < graph.size(); ++i)
        {
            int sourceParent = Find(i);
            for (int &destination : graph[i])
            {
                int destinationParent = Find(destination);

                if (sourceParent != destinationParent)
                {
                    Union(i, destination);
                    result--;
                }
            }
        }

        return result;
    }

    int Find(int source)
    {
        if (parent[source] == -1)
            return source;

        return Find(parent[source]);
    }

    void Union(int source, int destination)
    {
        parent[destination] = source;
        return;
    }
};

int main()
{
    vector<vector<int>> data = {{1, 2}, {0, 3}, {0, 3}, {1, 2}, {5}, {4}};

    Graph graph(data);

    cout << graph.stronglyConnectedComponents() << endl;
}