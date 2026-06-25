#include<bits/stdc++.h>
class Info{
    public:
    int u;
    int cost;
    int stops;
    Info(int u,int cost,int stops){
        this->u = u;
        this-> cost = cost;
        this->stops = stops;
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> graph;
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }
        queue<Info> q;
        q.push(Info(src,0,-1));
        vector<int> dist(n,INT32_MAX);
        while(!q.empty()){
            Info curInfo = q.front();q.pop();
            int u = curInfo.u;
            int cost = curInfo.cost;
            int stops = curInfo.stops;
            for(auto edge:graph[u]){
                int v = edge.first;
                int weight = edge.second;
                if(dist[v]>cost+weight && stops+1<=k){
                    dist[v] = cost+weight;
                    q.push(Info(v,dist[v],stops+1));
                }
            }
        }
        if(dist[dst]==INT32_MAX){
            return -1;
        }
        else{
            return dist[dst];
        }
    }
};