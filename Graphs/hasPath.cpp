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

   
    

    bool hasPathDFS(int src,int dest,vector<bool> &visited){
        if(src==dest){
            return true;
        }
        visited[src] = true;
        for(auto neighbor:neighbors[src]){
            if(!visited[neighbor]){
                if(hasPathDFS(neighbor,dest,visited)){
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPathBFS(int src,int dest,vector<bool>&visited){
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int cur = q.front();q.pop();
            if(cur==dest){
                return true;
            }
            for(auto neighbor:neighbors[cur]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
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
    // cout<<g.hasPathDFS(0,6,visited)<<endl;
    cout<<g.hasPathBFS(0,6,visited)<<endl;
}  