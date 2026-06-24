#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
class Graph{
    int v;
    list<int> * neighbors;
    public:
    Graph(int v){
        this->v = v;
        neighbors = new list<int>[v];
    }
    void createEdge(int u,int v){
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    void bfs(int src,vector<bool> visited){
        queue<int> q;
        
        q.push(src);
        visited[src] = true;
        
        while(!q.empty()){
            int u = q.front();q.pop();
            cout<<u<<" ";
            for(auto neighbor:neighbors[u]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

    }

};
int main(){
    vector<pair<int,int>> edges = {
    {0,1},
    {0,2},
    {1,3},
    {2,4},
    {3,5},
    {4,5},
    {5,6},
};
    Graph g(7);
    vector<bool> visited(7,false);
    for(auto edge : edges){
        g.createEdge(edge.first, edge.second);
    }
    g.bfs(0,visited);

}