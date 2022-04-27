#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<pair<int, int>>> graph;
    vector<bool> visited;
    vector<int> distance;
    vector<int> parent;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> vertices;

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
        vertices.push({distance[source], source});

        while (!vertices.empty())
        {
            PrintUnprocessedNodes();
            source = vertices.top().second;
            vertices.pop();
            cout << source << "(" << distance[source] << ") --> ";

            if (visited[source])
            {
                cout << "Visited." << endl
                     << endl;
                continue;
            }

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
                    vertices.push({distance[destination], destination});
                }
            }

            cout << endl;
            printConnections(connections);
            cout << endl
                 << endl;
        }

        return distance[destination];
    }

    void Print(int source)
    {
        for (int i = 0; i < graph.size(); ++i)
        {
            cout << source << " --(" << distance[i] << ")--> " << i << endl;
        }
    }

    void PrintUnprocessedNodes()
    {
        auto x = vertices;
        cout << endl;
        cout << "[" << endl;
        while (x.size() > 1)
        {
            auto y = x.top();
            x.pop();
            cout << y.second << ":" << y.first << "," << endl;
        }

        if (!x.empty())
            cout << x.top().second << ":" << x.top().first << endl;
        cout << "]" << endl;
        cout << endl;
        x.pop();
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
    vector<vector<pair<int, int>>> data = {{{1, 1}, {2, 4}}, {{2, 4}, {4, 7}}, {{4, 5}}, {{1, 2}, {2, 3}, {5, 6}}, {{3, 4}}, {{4, 7}}};
    Graph *graph = new Graph(data);
    int source = 0;
    int destination = 3;
    int result = graph->shortestPath(source, destination);
    graph->Print(source);
    cout << "Shortest Path Between (" << source << ") and (" << destination << ") is " << result << endl;
}