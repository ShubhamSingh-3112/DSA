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
    }

    bool hasCycleMain(int src,vector<bool>&visited,vector<bool>&inPath){
        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(hasCycle(i,visited,inPath)){
                    return true;
                }
            }
        }
        return false;
    }
    bool hasCycle(int src,vector<bool> &visited,vector<bool>&inPath){
        visited[src] = true;
        inPath[src] = true;
        for(auto neighbor:neighbors[src]){
            if(!visited[neighbor]){
                if(hasCycle(neighbor,visited,inPath)){
                    return true;
                }
            }
            else if(visited[neighbor] && inPath[neighbor]==true){
                return true;
            }
        }
        inPath[src] = false;
        return false;
    }
   
};
int main(){
    vector<pair<int,int>> edges = {
    {0,2},
    {1,0},
    {2,3},
    // {3,0},
};
    Graph g(4);
    vector<bool> visited(4,false);
    vector<bool> inPath(4,false);
    for(auto edge : edges){
        g.createEdge(edge.first, edge.second);
    }
    cout<<g.hasCycleMain(0,visited,inPath);
}