#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int min_cost(vector<int>length){
    priority_queue<int,vector<int>,greater<int>> p(length.begin(),length.end());
    int cost = 0;
    while(p.size()>1){
        int min1 = p.top();p.pop();
        int min2 = p.top();p.pop();
        cost+=min1+min2;
        p.push(min1+min2);
    }
    return cost;
}
int main(){
    vector<int> length = {4,3,2,6};
    cout<<min_cost(length);
}