#include<iostream>
using namespace std;
#include<map>
int main(){
    map<string,int> m;
    m["a"] = 100;
    m["b"] = 200;
    m["c"] = 300;

    for(auto item:m){
        cout<<item.first<<":"<<item.second<<endl;
    }

    cout<<m["b"]<<endl;

    cout<<m.count("a")<<endl;
    m.erase("a");
    cout<<m.count("a");
}