#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
    public:
    int n;
    vector<int> parent;
    vector<int> rank;
    public:
    DisjointSet(int n){
        this->n = n;
        for(int i=0;i<n;i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x] = find(parent[x]); // path compression // reassigns the parent once found to the ultimate parent
    }
    void Union(int a,int b){
        int parentA = find(a);
        int parentB = find(b);
        if(rank[parentA]==rank[parentB]){
            parent[parentB] = parentA;
            rank[parentA]++;
        }
        else if(rank[parentA]>rank[parentB]){
            parent[parentB] = parentA;
        }
        else{
            parent[parentA] = parentB;
        }
    }
};
int main(){
    DisjointSet s(6);
    s.Union(0,2);
    cout<< s.find(2)<<endl;
    s.Union(1,3);
    s.Union(2,5);
    s.Union(0,3);
    s.Union(0,4);
    // s.find(3);
    for(int i=0;i<6;i++){
        cout<<i<<":"<<s.parent[i]<<" "<<s.rank[i]<<endl;
    }
}