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

    bool hasCycle(int src,int parent,vector<bool>&visited){
        visited[src] = true;
        for(auto neighbor:neighbors[src]){
            if(!visited[neighbor]){
                if(hasCycle(neighbor,src,visited)){
                    return true;
                }
            }
            else if(visited[neighbor] && neighbor!=parent){
                return true;
            }
        }
        return false;
    }
   
};
int main(){
    vector<pair<int,int>> edges = {
    {0,1},
    {0,2},
    {1,3},
    {2,4},
    {3,4},
    {3,5},
    {4,5},
    {5,6},
};
    Graph g(7);
    vector<bool> visited(7,false);
    for(auto edge : edges){
        g.createEdge(edge.first, edge.second);
    }
    cout<<g.hasCycle(0,-1,visited);
}