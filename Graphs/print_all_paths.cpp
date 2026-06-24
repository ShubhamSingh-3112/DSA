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
        // neighbors[v].push_back(u);
    }

    void dfs(int src,int dest,vector<bool>&visited,string &path){
        if(src==dest){
            cout<<path<<dest<<endl;
            return;
        }
        path+=to_string(src);
        visited[src] = true;
        for(auto neighbor:neighbors[src]){
            if(!visited[neighbor]){
                dfs(neighbor,dest,visited,path);
            }
        }
        visited[src] = false;
        path = path.substr(0,path.size()-1);
    }
    
};
int main(){
    vector<pair<int,int>> edges = {
    {5,0},
    {5,2},
    {4,0},
    {4,1},
    {0,3},
    {2,3},
    {3,1}
};

    Graph g(6);
    vector<bool> visited(6,false);
    for(auto edge : edges){
        g.createEdge(edge.first, edge.second);
    }
    string path = "";
    g.dfs(5,1,visited,path);

}