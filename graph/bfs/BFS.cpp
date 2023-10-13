#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> graph;
    vector<bool> visited;
    queue<int> nodes;

public:
    Graph(vector<vector<int>> &data, vector<bool> &visited)
    {
        this->graph = data;
        this->visited = visited;
    }

    void BFS(int source)
    {
        nodes.push(source);
        visited[source] = true;

        while (!nodes.empty())
        {
            int current = nodes.front();
            nodes.pop();

            cout << current << endl;

            for (int &destination : graph[current])
            {
                if (!visited[destination])
                {
                    visited[destination] = true;
                    nodes.push(destination);
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> data = {{1}, {0, 4, 5}, {3}, {2, 4}, {1, 3}, {1}};
    vector<bool> visited(data.size());

    Graph graph(data, visited);

    graph.BFS(3);
}