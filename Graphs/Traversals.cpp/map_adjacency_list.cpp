#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;
class Graph{
    int v;
    unordered_map<int,list<int>> neighbors;
    public:
    Graph(int v){
        this->v = v;
    }
    void createEdge(int u,int v){
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }
    void print(){
        for(int i=0;i<v;i++){
            cout<<i<<" : ";
            for(auto neighbor:neighbors[i]){
                cout<<neighbor<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g(5);
    g.createEdge(0,1);
    g.createEdge(1,2);
    g.createEdge(1,3);
    g.createEdge(2,3);
    g.createEdge(2,4);

    g.print();
}