#include<iostream>
using namespace std;
#include<queue>
struct comparator{
    // fixed format operator()(parameters){logic}
    bool operator()(pair<string,int> &p1,pair<string,int> &p2){
        return p1.first>p2.first;
    }
};
int main(){
    //priority_queue<pair<string,int>> pq;// default max pq on the basis of first property of pair
    priority_queue<pair<string,int>,vector<pair<string,int>>,comparator> pq;
    pq.push(make_pair("shubham",1));
    pq.push(make_pair("adhee",20));
    while(!pq.empty()){
        cout<<pq.top().first<<endl;
        pq.pop();
    }
}