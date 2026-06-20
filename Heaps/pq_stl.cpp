#include<iostream>
using namespace std;
#include<queue>
int main(){
    priority_queue<int>pq; // maxheap
    // priority_queue<int,vector<int>,greater<int>>pq; // min heap
    pq.push(4);
    pq.push(2);
    pq.push(1);
    pq.push(3);
    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}