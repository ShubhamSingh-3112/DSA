#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<list>
using namespace std;
class Edge{
    public:
    int u;
    int v;
    int wt;
    public:
    Edge(int u,int v,int wt){
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
    bool operator<(const Edge& other) const{
        return wt > other.wt;
    }
};
class Graph{
    int v;
    list<Edge> * adj;
    bool undir;
    public:
    Graph(int v,bool undir){
        this->v = v;
        adj = new list<Edge>[v];
        this->undir = undir;
    }

    void addEdge(int u,int v,int wt){
        adj[u].push_back(Edge(u,v,wt));
        if(undir){
            adj[v].push_back(Edge(v,u,wt));
        }
    }

    int minSpanCost(int src){
        vector<bool> inMst(v);
        vector<Edge> result;
        priority_queue<pair<int,Edge>,vector<pair<int,Edge>>,greater<pair<int,Edge>>> pq;
        pq.push(make_pair(0,Edge(-1,src,-1)));
        int cost = 0;

        while(!pq.empty()){
            int u = pq.top().second.v;
            int wt = pq.top().first;
            Edge e = pq.top().second;
            pq.pop();
            if(!inMst[u]){
                cost+=wt;
                inMst[u] = true;
                result.push_back(e);
                for(auto edge:adj[u]){
                    pq.push(make_pair(edge.wt,Edge(u,edge.v,-1)));
                }
            }
        }
        for(int i=1;i<result.size();i++){
            cout<<result[i].u<<"-->"<<result[i].v<<endl;
        }
        return cost;
    }

    void dijkstra(int src){
        vector<int> dist(v,INT32_MAX);
        dist[src] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push(make_pair(0,src));

        while(!pq.empty()){
            int u = pq.top().second;
            int distToU = pq.top().first;
            pq.pop();
            if(distToU>dist[u]){
                continue;
            }
            for(auto edge:adj[u]){
                int v = edge.v;
                int wt = edge.wt;
                if(dist[v]>dist[u]+wt){
                    dist[v] = dist[u]+wt;
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
        for(int i=0;i<v;i++){
            cout<<dist[i]<<" ";
        }
    }
    void bellman(int src){
        vector<int> dist(v,INT32_MAX);
        dist[src]=0;
        for(int i=0;i<v-1;i++){
            for(int u=0;u<v;u++){
                if(dist[u]==INT32_MAX){
                    continue;
                }
                for(auto edge:adj[u]){
                    if(dist[edge.v]>dist[u]+edge.wt){
                        dist[edge.v] = dist[u]+edge.wt;
                        
                    }
                }
            }
        }
        for(int i=0;i<v;i++){
            cout<<dist[i]<<" ";
        }
    }
};
int main(){
//     vector<vector<int>> edges = {
//     {0,1,10},
//     {0,2,15},
//     {0,3,30},
//     {1,3,40},
//     {2,3,50}
// };
//     Graph g(4,true);
//     for(auto edge:edges){
//         g.addEdge(edge[0],edge[1],edge[2]);
//     }
//     cout<<g.minSpanCost(0);
    // vector<vector<int>> edges = {
    // {0, 1, 2},
    // {0, 2, 4},
    // {1, 2, 1},
    // {1, 3, 7},
    // {2, 4, 3},
    // {4, 3, 2},
    // {3, 5, 1},
    // {4, 5, 5}
    // };
    // Graph g(6,false);
    // for(auto edge:edges){
    //     g.addEdge(edge[0],edge[1],edge[2]);
    // }
    // g.dijkstra(1);
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, -4},
        {2, 3, 2},
        {3, 4, 4},
        {4, 1, -1}};
    Graph g(5,false);
    for(auto edge:edges){
        g.addEdge(edge[0],edge[1],edge[2]);
    }
    g.bellman(4);

}