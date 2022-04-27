#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> graph;
    vector<int> parent;
    vector<int> rank;

public:
    Graph(vector<vector<int>> &data, int numVertices)
    {
        this->graph = data;
        this->parent = vector<int>(numVertices + 1, -1);
        this->rank = vector<int>(numVertices + 1);
    }

    bool hasCycle()
    {
        for (int i = 0; i < graph.size(); ++i)
        {
            int source = graph[i][0];
            int destination = graph[i][1];
            int sourceParent = Find(source);
            int destinationParent = Find(destination);

            if (sourceParent == destinationParent)
            {
                cout << "Cycle: " << source << " <--> " << destination << endl;
                return true;
            }

            unionByRank(sourceParent, destinationParent);
        }

        return false;
    }

    int Find(int source)
    {
        if (parent[source] == -1)
            return source;

        return Find(parent[source]);
    }

    void unionByRank(int sourceParent, int destinationParent)
    {
        if (rank[sourceParent] > rank[destinationParent])
            parent[destinationParent] = sourceParent;

        else if (rank[sourceParent] < rank[destinationParent])
            parent[sourceParent] = destinationParent;

        else
        {
            rank[sourceParent]++;
            parent[destinationParent] = sourceParent;
        }
    }

    void Print()
    {
        for (int i = 0; i < parent.size(); ++i)
        {
            cout << "Parent of (" << i << ")"
                 << " is (" << parent[i] << ")" << endl;
        }
    }
};

int main()
{
    int numVertices = 4;
    vector<vector<int>> data = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    Graph *graph = new Graph(data, numVertices);
    cout << graph->hasCycle() << endl;
    graph->Print();
}