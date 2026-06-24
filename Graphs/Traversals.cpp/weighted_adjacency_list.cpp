#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph{
    int v;
    list <pair<int,int>> * neighbors; // points to array of neighbors // each array index has a list of neigbors for that index
    public:
    Graph(int v){
        this->v = v;
        neighbors = new list<pair<int,int>>[v];
    }
    void createEdge(int u,int v,int weight){
        neighbors[u].push_back(make_pair(u,weight));
        neighbors[v].push_back(make_pair(v,weight));
    }
    void print(){
        for(int i=0;i<v;i++){
            cout<<i<<" : ";
            for(auto neighbor:neighbors[i]){
                cout<<"("<<neighbor.first<<","<<neighbor.second<<")"<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g(5);
    g.createEdge(0,1,5);
    g.createEdge(1,2,1);
    g.createEdge(1,3,3);
    g.createEdge(2,3,1);
    g.createEdge(2,4,2);

    g.print();
}