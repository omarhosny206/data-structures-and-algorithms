#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int numVertices;
    vector<vector<int>> graph;
    vector<int> distance;
    vector<int> parent;

public:
    Graph(vector<vector<int>> &data, int numVertices)
    {
        this->numVertices = numVertices;
        this->graph = data;
        this->distance = vector<int>(numVertices, INT_MAX);
        this->parent = vector<int>(numVertices, -1);
    }

    bool hasNegativeCycle()
    {
        shortestPath(0, 0);

        for (vector<int> &edge : graph)
        {
            int source = edge[0];
            int destination = edge[1];
            int edgeDistance = edge[2];

            if (distance[source] != INT_MAX && distance[source] + edgeDistance < distance[destination])
                return true;
        }

        return false;
    }

    int shortestPath(int source, int destination)
    {
        distance[source] = 0;

        for (int i = 0; i < numVertices - 2; ++i)
        {
            for (vector<int> &edge : graph)
            {
                int source = edge[0];
                int destination = edge[1];
                int edgeDistance = edge[2];

                if (distance[source] != INT_MAX && distance[source] + edgeDistance < distance[destination])
                {
                    distance[destination] = distance[source] + edgeDistance;
                    parent[destination] = source;
                }
            }
        }

        return distance[destination];
    }

    void Print(int source)
    {
        for (int i = 0; i < numVertices; ++i)
        {
            cout << source << " --(" << distance[i] << ")--> " << i << endl;
        }
    }
};

int main()
{
    int numVertices = 6;
    vector<vector<int>> data = {{0, 1, -1}, {0, 2, 4}, {1, 0, 4}, {1, 2, 4}, {1, 4, 7}, {1, 3, 2}, {2, 0, 4}, {2, 1, 4}, {2, 3, 3}, {2, 4, 5}, {3, 2, 3}, {3, 1, 2}, {3, 4, 4}, {3, 5, 6}, {4, 1, 7}, {4, 2, 5}, {4, 3, 4}, {4, 5, 7}, {5, 3, 6}, {5, 4, 7}};
    Graph *graph = new Graph(data, numVertices);
    cout << graph->hasNegativeCycle() << endl;
    graph->Print(0);
}