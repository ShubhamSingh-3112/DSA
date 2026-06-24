#include<iostream>
#include<vector>
#include<list>
#include<stack>
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
    void topSort(){
        stack<int> s;
        vector<bool> visited(6,false);
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfsCaller(i,visited,s);
            }
        }
        while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    }
    void dfsCaller(int src,vector<bool> &visited,stack<int> &s){
        visited[src] = true;
        for(auto neighbor:neighbors[src]){
            if(!visited[neighbor]){
                dfsCaller(neighbor,visited,s);
            }
        }
        s.push(src);
    }
};
int main(){
    Graph g(6);
    vector<pair<int,int>> edges = {
    {5,0},
    {5,2},
    {4,0},
    {4,1},
    {2,3},
    {3,1}
}; 
    for(auto edge:edges){
        g.createEdge(edge.first,edge.second);
    }
    
    g.topSort();
}