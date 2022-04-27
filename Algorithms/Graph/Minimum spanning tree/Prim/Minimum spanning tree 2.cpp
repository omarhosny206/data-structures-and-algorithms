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

    void minimumSpanningTree(int source)
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
                cout << "Visited." << endl << endl;
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

                if (!visited[destination] && edgeDistance < distance[destination])
                {
                    connections += "(" + to_string(source) + " --(" + to_string(edgeDistance) + ")--> " + to_string(destination) + ") ";
                    distance[destination] = edgeDistance;
                    parent[destination] = source;
                    vertices.push({distance[destination], destination});
                }
            }

            cout << endl;
            printConnections(connections);
            cout << endl
                 << endl;
        }
    }

    void Print(int source)
    {
        for (int i = 0; i < graph.size(); ++i)
            if (i != source)
                cout << parent[i] << " --(" << distance[i] << ")--> " << i << endl;
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
    vector<vector<pair<int, int>>> data = {{{1, 3}, {2, 1}}, {{0, 3}, {2, 2}, {3, 4}}, {{0, 1}, {1, 2}, {3, 5}}, {{1, 4}, {2, 5}}};
    Graph *graph = new Graph(data);
    int source = 0;
    graph->minimumSpanningTree(source);
    graph->Print(source);
}