#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(1);

    if(s.find(5)==s.end()){
        cout<<"True"<<endl;
    }
    s.erase(4);
    for(auto i:s){
        cout<<i<<endl;
    }
}