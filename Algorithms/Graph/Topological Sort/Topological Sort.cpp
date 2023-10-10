#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> graph;
    vector<bool> visited;
    stack<int> nodes;

public:
    Graph(vector<vector<int>> &data, vector<bool> &visited)
    {
        this->graph = data;
        this->visited = visited;
    }

    void dfs(int source)
    {
        visited[source] = true;

        for (int &destination : graph[source])
            if (!visited[destination])
                dfs(destination);

        nodes.push(source);
    }

    void topologicalSort()
    {
        for (int i = 0; i < graph.size(); ++i)
            if (!visited[i])
                dfs(i);

        while (!nodes.empty())
        {
            cout << nodes.top() << endl;
            nodes.pop();
        }
    }
};

int main()
{
    vector<vector<int>> data = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
    vector<bool> visited(data.size());

    Graph graph(data, visited);

    graph.topologicalSort();
}