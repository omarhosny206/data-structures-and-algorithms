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

    bool BFS(int source)
    {
        queue<int> nodes;
        nodes.push(source);
        color[source] = 0;

        while (!nodes.empty())
        {
            int current = nodes.front();
            nodes.pop();

            for (int &destination : graph[current])
            {
                if (color[destination] == -1)
                {
                    color[destination] = !color[current];
                    nodes.push(destination);
                }

                else if (color[destination] == color[current])
                    return false;
            }
        }

        return true;
    }

    bool isBaipartite()
    {
        for (int i = 0; i < graph.size(); ++i)
            if (color[i] == -1 && !BFS(i))
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