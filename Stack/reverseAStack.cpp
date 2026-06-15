#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    stack<int> rev;
    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.empty()){
        cout<<s.top()<<" ";
        rev.push(s.top());
        s.pop();
    }
    cout<<endl;
    while(!rev.empty()){
        cout<<rev.top()<<" ";
        rev.pop();
    }
}