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

int mstWeight(int src,vector<vector<Edge>> &edgeList,int V){
    vector<bool> inMst(V,false);
    int cost = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;// weight, node

    q.push(make_pair(0,src));

    while(!q.empty()){
        // minimum weight always on top
        int u = q.top().second;
        int wt = q.top().first;
        q.pop();
        if(inMst[u]){
            continue;
        }
        inMst[u] = true;
        cost+=wt;
        for(auto edge:edgeList[u]){
            if(!inMst[edge.v]){
                q.push(make_pair(edge.wt,edge.v));
            }
        }
    }
    return cost;
}

int main(){
    vector<vector<int>> edges = {
    {0,1,10},
    {0,2,15},
    {0,3,30},
    {1,3,40},
    {2,3,50}
};
    vector<vector<Edge>> edgeList(6);
    for(auto edge:edges){
        edgeList[edge[0]].push_back(Edge(edge[1],edge[2]));
        edgeList[edge[1]].push_back(Edge(edge[0],edge[2]));
    }
    cout<<mstWeight(1,edgeList,4);
}