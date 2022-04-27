#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> graph;
    vector<int> color;

public:
    Graph(vector<vector<int>> &data, vector<bool> &visited)
    {
        this->graph = data;
        this->color = vector<int>(graph.size(), -1);
    }

    bool DFS(int source, int previousColor)
    {
        if (color[source] != -1)
            return color[source] != previousColor;

        color[source] = !previousColor;

        for (int &destination : graph[source])
            if (!DFS(destination, color[source]))
                return false;

        return true;
    }

    bool isBaipartite()
    {
        for (int i = 0; i < graph.size(); ++i)
            if (color[i] == -1 && !DFS(i, 1))
                return false;

        return true;
    }
};

int main()
{
    vector<vector<int>> data = {{1}, {0, 3}, {3}, {1, 2}};
    vector<bool> visited(data.size());

    Graph graph(data, visited);

    cout << graph.isBaipartite() << endl;
}