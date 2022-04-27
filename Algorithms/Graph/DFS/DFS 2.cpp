#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> graph;
    vector<bool> visited;

public:
    Graph(vector<vector<int>> &data, vector<bool> &visited)
    {
        this->graph = data;
        this->visited = visited;
    }

    void DFS(int source)
    {
        visited[source] = true;
        cout << source << endl;

        for (int &destination : graph[source])
            if (!visited[destination])
                DFS(destination);
    }
};

int main()
{
    vector<vector<int>> data = {{1, 2}, {2}, {0, 3}, {3}};
    vector<bool> visited(data.size());

    Graph graph(data, visited);

    graph.DFS(2);
}