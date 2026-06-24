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

   
    void dfs(int src,vector<bool> &visited){
        cout<<src<<" ";
        visited[src] = true;
        for(auto neighbor:neighbors[src]){
            if(!visited[neighbor]){
                dfs(neighbor,visited);
            }
        }
        return;
    } 

    void disconnected_components(vector<bool> &visited){
        for(int i=0;i<v;i++){
            if(!visited[i]){
                // dfs(i,visited);
                bfs(i,visited);
                cout<<endl;
            }
        }
    }

    void bfs(int src, vector<bool> &visited){
        queue<int> q;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int cur = q.front();q.pop();
            cout<<cur<<" ";
            for(auto neighbor:neighbors[cur]){
                if(!visited[neighbor]){
                    q.push(neighbor);
                    visited[neighbor]=true;
                }
            }
        }
    }
};
int main(){
    vector<pair<int,int>> edges = {
    {1,6},
    {6,4},
    {4,9},
    {4,3},
    {3,8},
    {3,7},
    {2,5},
    {2,0}
};
    Graph g(10);
    vector<bool> visited(10,false);
    for(auto edge : edges){
        g.createEdge(edge.first, edge.second);
    }
    g.disconnected_components(visited);
}