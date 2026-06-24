#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<queue>
using namespace std;
class Graph{
    int v;
    list<int> * neighbors;
    vector<int> indeg;
    public:
    Graph(int v){
        this->v = v;
        neighbors = new list<int>[v];
        indeg = vector<int>(v,0);
    }
    void createEdge(int u,int v){
        neighbors[u].push_back(v);
        indeg[v]+=1;
    }
    void topSort(){
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur = q.front();q.pop();
            cout<<cur<<" ";
            for(auto neighbor:neighbors[cur]){
                indeg[neighbor]--;
                if(indeg[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        cout<<endl;
        // cycle detection
        for(int i=0;i<v;i++){
            if(indeg[i]!=0){
                cout<<"Cannot process all vertex as cycle exists";
                return;
            }
        }
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