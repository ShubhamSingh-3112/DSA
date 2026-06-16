#include<iostream>
#include<algorithm>
using namespace std;
#include<vector>
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}
void maxChainPair(vector<pair<int,int>> pairs){
    sort(pairs.begin(),pairs.end(),compare);
    int count = 1;
    int currentEnd = pairs[0].second;
    cout<<pairs[0].first<<","<<pairs[0].second<<endl;
    for(int i=1;i<pairs.size();i++){
        if(pairs[i].first>currentEnd){
            cout<<pairs[i].first<<","<<pairs[i].second<<endl;
            count+=1;
            currentEnd = pairs[i].second;
        }
    }
    cout<<count;
}
int main(){
    int start[] = {5,39,5,27,50};
    int end[] = {24,60,28,40,90};
    vector<pair<int,int>> pairs(5,make_pair(0,0));
    for(int i=0;i<5;i++){
        pairs[i] = make_pair(start[i],end[i]);
    }
    maxChainPair(pairs);
}