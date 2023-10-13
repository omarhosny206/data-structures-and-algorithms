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

    int shortestPath(int source, int destination)
    {
        distance[source] = 0;

        for (int i = 0; i < numVertices - 2; ++i)
        {
            bool isUpdated = false;

            for (vector<int> &edge : graph)
            {
                int source = edge[0];
                int destination = edge[1];
                int edgeDistance = edge[2];

                if (distance[source] != INT_MAX && distance[source] + edgeDistance < distance[destination])
                {
                    distance[destination] = distance[source] + edgeDistance;
                    parent[destination] = source;
                    isUpdated = true;
                }
            }

            if (!isUpdated)
                break;
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
    int numVertices = 5;
    vector<vector<int>> data = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    Graph *graph = new Graph(data, numVertices);
    int source = 0;
    int destination = 3;
    int result = graph->shortestPath(source, destination);
    graph->Print(source);
    cout << "Shortest Path Between (" << source << ") and (" << destination << ") is " << result << endl;
}