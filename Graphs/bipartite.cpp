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

    bool isBipartite(int src,vector<int> &color){
        queue<int> q;
        q.push(src);
        color[src] = 0;
        while(!q.empty()){
            int cur = q.front();q.pop();
            for(auto neighbor:neighbors[cur]){
                if(color[neighbor]==-1)// color = -1 means not visited
                {
                    color[neighbor] = !color[cur];
                    q.push(neighbor);
                }
                // else if visited and has same color as current -> return false
                else if(color[neighbor]!=-1 and color[neighbor]==color[cur])
                {
                    return false;
                }
            }
        }
        return true;
    }
    

};
int main(){
    vector<pair<int,int>> edges = {
    {0,1},
    {0,2},
    {1,3},
    {2,3},
    {0,3}
};
    Graph g(4);
    vector<int> color(4,-1);
    for(auto edge : edges){
        g.createEdge(edge.first, edge.second);
    }
    cout<<g.isBipartite(0,color);
}