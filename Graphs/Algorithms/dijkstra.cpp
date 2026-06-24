#include<iostream>
#include<queue>
using namespace std;
class Edge{
    public:
    int v;
    int wt;
    public:
    Edge(int v,int wt){
        this->v = v;
        this->wt = wt;
    }
};
bool compare(int a,int b){
    return a > b;
}
void dijkstra(int src,vector<int> &dist,vector<vector<Edge>> edgeList){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;// dist , vertex 
    dist[src] = 0;
    pq.push(make_pair(dist[src],src));
    while(!pq.empty()){
        int u = pq.top().second;
        int distToU = pq.top().first;
        pq.pop();
        for(auto edge:edgeList[u]){
            int v = edge.v;
            int wt = edge.wt;
            if(dist[v]>dist[u] + wt){
                dist[v] = dist[u] + wt;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}
int main(){
    vector<vector<int>> edges = {
    {0, 1, 2},
    {0, 2, 4},
    {1, 2, 1},
    {1, 3, 7},
    {2, 4, 3},
    {4, 3, 2},
    {3, 5, 1},
    {4, 5, 5}
    };
    vector<vector<Edge>> edgeList(6);
    for(auto edge:edges){
        edgeList[edge[0]].push_back(Edge(edge[1],edge[2]));
    }
    vector<int> dist(6,INT32_MAX);
    int src = 0;
    dijkstra(src,dist,edgeList);
    for(int i=0;i<6;i++){
        cout<<dist[i]<<" ";
    }
}