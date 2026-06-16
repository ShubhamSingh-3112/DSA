#include<iostream>
#include<queue>
using namespace std;
int main(){
    int n = 10;
    queue<int> original;
    for(int i=1;i<=n;i++){
        original.push(i);
    }
    queue<int> extra;
    for(int i=0;i<n/2;i++){
        extra.push(original.front());
        original.pop();
    }
    while(!extra.empty()){
        original.push(extra.front());
        int top = original.front();
        original.push(top);
        original.pop();
        extra.pop();
    }
    while(!original.empty()){
        cout<<original.front()<<" ";
        original.pop();
    }
}