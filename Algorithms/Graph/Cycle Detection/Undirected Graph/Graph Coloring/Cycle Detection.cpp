#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> graph;
    vector<int> visited;

public:
    Graph(vector<vector<int>> &data, vector<int> &visited)
    {
        this->graph = data;
        this->visited = visited;
    }

    bool DFS(int source, int parent)
    {
        if (visited[source] == 1)
            return true;

        visited[source] = 1;

        for (int &destination : graph[source])
            if (visited[destination] != 2 && destination != parent && DFS(destination, source))
                return true;

        visited[source] = 2;
        return false;
    }

    bool hasCycle()
    {
        for (int i = 0; i < graph.size(); ++i)
            if (!visited[i] && DFS(i, INT_MAX))
                return true;

        return false;
    }
};

int main()
{
    vector<vector<int>> data = {{1, 2}, {0}, {0, 3, 4}, {2, 4}, {3, 2}};
    vector<int> visited(data.size());

    Graph graph(data, visited);

    cout << graph.hasCycle() << endl;
}