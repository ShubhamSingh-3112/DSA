#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Edge{
    public:
    int u;
    int v;
    int wt;
    Edge(int u,int v,int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};
class Graph{
    public:
    vector<Edge> edges;
    vector<int> parent;
    vector<int> rank;
    int v;
    Graph(int v){
        this->v = v;
        for(int i=0;i<v;i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    void addEdge(int u,int v,int wt){
        edges.push_back(Edge(u,v,wt));
    }
    int find(int x){
        if(parent[x]==x){
            return x;

        }
        return parent[x] = find(parent[x]);
    }
    void Union(int a,int b){
        int parentA = parent[a];
        int parentB = parent[b];
        
        if(rank[parentA]==rank[parentB]){
            parent[parentB]=parentA;
            rank[parentA]++;
        }
        else if(rank[parentA]>rank[parentB]){
            parent[parentB] = parentA;
        }
        else{
            parent[parentA] = parentB;
        }
    }
    
    static bool compare(Edge&a,Edge&b){
        return a.wt < b.wt;
    }

    void kruskals(){
        sort(edges.begin(),edges.end(),compare);
        int cost = 0;
        int count = 0;
        for(int i=0;i<edges.size()&&count!=v-1;i++){
            Edge a = edges[i];
            int u = a.u;
            int v = a.v;
            int wt = a.wt;
            if(find(u)!=find(v)){
                Union(u,v);
                cost+=wt;
            }
        }
        cout<<cost<<endl;
    }
};
int main(){
    Graph g(4);
    g.addEdge(0,1,60);
    g.addEdge(0,2,15);
    g.addEdge(0,3,30);
    g.addEdge(1,3,40);
    g.addEdge(2,3,50);
    g.kruskals();
    return 0;
}