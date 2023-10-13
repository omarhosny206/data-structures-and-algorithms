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

        for (int &destination : graph[source])
            if (!visited[destination])
                DFS(destination);
    }

    int stronglyConnectedComponents()
    {
        int result = 0;

        for (int i = 0; i < graph.size(); ++i)
        {
            if (!visited[i])
            {
                result++;
                DFS(i);
            }
        }

        return result;
    }
};

int main()
{
    vector<vector<int>> data = {{1, 2}, {0, 3}, {0, 3}, {1, 2}, {5}, {4}};
    vector<bool> visited(data.size());

    Graph graph(data, visited);

    cout << graph.stronglyConnectedComponents() << endl;
}