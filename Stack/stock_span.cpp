#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    vector<int> stock = {100,80,60,70,60,85,100};
    vector<int> span(stock.size());
    span[0]=1;
    s.push(0);
    for(int i=1;i<stock.size();i++){
        while(!s.empty()&&stock[s.top()]<=stock[i]){
            s.pop();
        }
        if(s.empty()){
            span[i] = i+1;
            s.push(i);
            continue;
        }
        else{
            span[i] = i-s.top();
            s.push(i);
        }
    }
    for(int i=0;i<span.size();i++){
        cout<<span[i]<<" ";
    }
}