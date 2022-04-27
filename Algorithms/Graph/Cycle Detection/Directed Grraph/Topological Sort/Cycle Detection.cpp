#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    vector<vector<int>> graph;
    queue<int> nodes;
    vector<int> indegree;
    int counter;

public:
    Graph(vector<vector<int>> &data)
    {
        this->graph = data;
        this->indegree = vector<int>(graph.size());
        this->counter = 0;
    }

    void fillDegree()
    {
        for (int i = 0; i < graph.size(); ++i)
            for (int &destination : graph[i])
                indegree[destination]++;
    }

    void topologicalSort()
    {
        fillDegree();

        for (int i = 0; i < graph.size(); ++i)
            if (indegree[i] == 0)
                nodes.push(i);

        while (!nodes.empty())
        {
            int source = nodes.front();
            nodes.pop();
            counter++;

            for (int &destination : graph[source])
            {
                indegree[destination]--;
                if (indegree[destination] == 0)
                    nodes.push(destination);
            }
        }
    }

    bool hasCycle()
    {
        return counter != graph.size();
    }
};

int main()
{
    vector<vector<int>> data = {{1, 2}, {}, {3}, {4}, {2}};
    vector<bool> visited(data.size());

    Graph graph(data);
    graph.topologicalSort();
    cout << graph.hasCycle() << endl;
}