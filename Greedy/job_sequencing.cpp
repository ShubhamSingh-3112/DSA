#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second>p2.second;
}
void job_sequence(vector<pair<int,int>> jobs){
    sort(jobs.begin(),jobs.end(),compare);
    int safe = 2;
    int profit = jobs[0].second;
    for(int i=1;i<jobs.size();i++){
        if(jobs[i].first>safe){
            safe+=1;
            profit+=jobs[i].second;
        }
    }
    cout<<profit;
}
int main(){
    int deadLine[] = {4,1,1,1};
    int profit[] = {20,10,40,30};
    vector<pair<int,int>> jobs(4,make_pair(0,0));
    for(int i=0;i<4;i++){
        jobs[i]=make_pair(deadLine[i],profit[i]);
    }
    job_sequence(jobs);
}