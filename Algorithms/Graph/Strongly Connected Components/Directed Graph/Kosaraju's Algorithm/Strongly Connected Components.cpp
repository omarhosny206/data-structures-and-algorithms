#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> graph;
    vector<bool> visited;
    stack<int> nodes;

public:
    Graph(vector<vector<int>> &data)
    {
        this->graph = data;
        this->visited = vector<bool>(graph.size());
    }

    int stronglyConnectedComponents()
    {
        int result = 0;

        topologicalSort();
        graph = getTransposedGraph();
        visited = vector<bool>(graph.size());

        cout << "Strongly Connected Components: " << endl;

        while (!nodes.empty())
        {
            int source = nodes.top();
            nodes.pop();

            if (!visited[source])
            {
                result++;
                DFS(source);
                cout << endl;
            }
        }

        return result;
    }

    vector<vector<int>> getTransposedGraph()
    {
        vector<vector<int>> transposedGraph(graph.size());

        for (int i = 0; i < graph.size(); ++i)
            for (int &destination : graph[i])
                transposedGraph[destination].push_back(i);

        return transposedGraph;
    }

    void DFS(int source)
    {
        visited[source] = true;

        cout << source << " ";

        for (int &destination : graph[source])
            if (!visited[destination])
                DFS(destination);

        nodes.push(source);
    }

    void DFS2(int source)
    {
        visited[source] = true;

        for (int &destination : graph[source])
            if (!visited[destination])
                DFS2(destination);

        nodes.push(source);
    }

    void topologicalSort()
    {
        for (int i = 0; i < graph.size(); ++i)
            if (!visited[i])
                DFS2(i);
    }
};

int main()
{
    vector<vector<int>> data = {{1}, {2}, {0, 3}, {}};

    Graph graph(data);

    int result = graph.stronglyConnectedComponents();
    cout << "There are (" << result << ") Strongly Connected Components As Shown Above!" << endl;
}