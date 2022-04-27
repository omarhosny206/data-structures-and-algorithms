#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> graph;
    vector<int> parent;
    vector<int> rank;
    vector<int> distance;

public:
    Graph(vector<vector<int>> &data, int numVertices)
    {
        this->graph = data;
        this->parent = vector<int>(numVertices, -1);
        this->rank = vector<int>(numVertices);
        this->distance = vector<int>(numVertices, INT_MAX);
    }

    void minimumSpanningTree()
    {
        sort(graph.begin(), graph.end(), Compare);

        for (int i = 0; i < graph.size(); ++i)
        {
            int source = graph[i][0];
            int destination = graph[i][1];
            int edgeDistance = graph[i][2];

            cout << source << ":" << destination << endl;

            int sourceParent = Find(source);
            int destinationParent = Find(destination);
            cout << sourceParent << ":" << destinationParent << endl
                 << endl;

            if (sourceParent == destinationParent)
            {
                cout << "Skip" << endl
                     << endl;
                continue;
            }

            unionByRank(sourceParent, destinationParent);
        }
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
        cout << "Not Implemented Yet!" << endl;
    }

    static bool Compare(vector<int> &first, vector<int> &second)
    {

        return first[2] < second[2] || (first[2] == second[2] && first[0] < second[0]) || (first[2] == second[2] && first[0] == second[0] && first[1] < second[1]);
    }
};

int main()
{
    int numVertices = 6;
    vector<vector<int>> data = {{2, 3, 2}, {0, 1, 1}, {3, 5, 4}, {1, 2, 3}, {1, 3, 1}, {2, 4, 1}, {1, 4, 3}, {4, 5, 3}, {0, 2, 2}, {3, 4, 2}};
    Graph *graph = new Graph(data, numVertices);
    graph->minimumSpanningTree();
    graph->Print();
}

/*
Like TechDose Video
*/