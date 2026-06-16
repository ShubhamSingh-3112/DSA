#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int>p2){
    return p1.second<p2.second;
}
int main(){
    vector<int> start = {0,1,3};
    vector<int> end = {9,2,4};
    vector<pair<int,int>> act(3,make_pair(0,0));
    for(int i=0;i<3;i++){
        act[i] = make_pair(start[i],end[i]);
        cout<<act[i].first<<","<<act[i].second<<endl;
    }
    
    sort(act.begin(),act.end(),compare);

    for(int i=0;i<3;i++){
        cout<<act[i].first<<","<<act[i].second<<endl;
    }

}