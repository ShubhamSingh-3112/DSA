#include <iostream>
#include <queue>
using namespace std;
class Edge
{
public:
    int v;
    int wt;

public:
    Edge(int v, int wt)
    {
        this->v = v;
        this->wt = wt;
    }
};

void bellman(int src, vector<int> &dist, vector<vector<Edge>> edgeList, int V)
{
    dist[src] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for (auto edge : edgeList[u])
            {
                if (dist[u] != INT32_MAX)
                {
                    if (dist[edge.v] > dist[u] + edge.wt)
                    {
                        dist[edge.v] = dist[u] + edge.wt;
                    }
                }
            }
        }
    }
}
int main()
{
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, -4},
        {2, 3, 2},
        {3, 4, 4},
        {4, 1, -1}};
    vector<vector<Edge>> edgeList(6);
    for (auto edge : edges)
    {
        edgeList[edge[0]].push_back(Edge(edge[1], edge[2]));
    }

    vector<int> dist(5, INT32_MAX);
    int src = 4;
    bellman(src, dist, edgeList, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << dist[i] << " ";
    }
}