#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<pair<int, int>>> graph;
    vector<bool> visited;
    vector<int> distance;
    vector<int> parent;

public:
    Graph(vector<vector<pair<int, int>>> &data)
    {
        this->graph = data;
        this->visited = vector<bool>(graph.size());
        this->distance = vector<int>(graph.size(), INT_MAX);
        this->parent = vector<int>(graph.size(), -1);
    }

    int shortestPath(int source, int destination)
    {
        distance[source] = 0;

        for (int i = 0; i < graph.size() - 1; ++i)
        {
            int source = getMinUnprocessedVertex();
            cout << source << "(" << distance[source] << ") --> ";
            visited[source] = true;
            string connections = "";

            for (pair<int, int> &edge : graph[source])
            {
                int destination = edge.first;
                int edgeDistance = edge.second;

                if (!visited[destination])
                    cout << destination << "(" << edgeDistance << ")  ";

                if (!visited[destination] && distance[source] + edgeDistance < distance[destination])
                {
                    connections += "(" + to_string(source) + " --(" + to_string(distance[source] + edgeDistance) + ")--> " + to_string(destination) + ") ";
                    distance[destination] = distance[source] + edgeDistance;
                    parent[destination] = source;
                }
            }

            cout << endl;

            printConnections(connections);

            cout << endl
                 << endl;
        }

        return distance[destination];
    }

    int getMinUnprocessedVertex()
    {
        int result = INT_MAX;

        for (int i = 0; i < graph.size(); ++i)
            if (!visited[i] && result > distance[i])
                result = distance[i];

        return result;
    }

    void Print(int source)
    {
        for (int i = 0; i < graph.size(); ++i)
        {
            cout << source << "--(" << distance[i] << ")--> " << i << endl;
        }
    }

    void printConnections(string connections)
    {
        cout << "Connections: ";

        if (connections.length() == 0)
        {
            cout << "Nothing";
            return;
        }

        cout << connections;
    }
};

int main()
{
    vector<vector<pair<int, int>>> data = {{{1, 1}, {2, 4}}, {{0, 1}, {2, 4}, {4, 7}, {3, 2}}, {{0, 4}, {1, 4}, {3, 3}, {4, 5}}, {{1, 2}, {2, 3}, {4, 4}, {5, 6}}, {{1, 7}, {2, 5}, {3, 4}, {5, 7}}, {{3, 6}, {4, 7}}};
    Graph *graph = new Graph(data);
    int source = 0;
    int destination = 3;
    int result = graph->shortestPath(source, destination);
    graph->Print(source);
    cout << "Shortest Path Between (" << source << ") and (" << destination << ") is " << result << endl;
}