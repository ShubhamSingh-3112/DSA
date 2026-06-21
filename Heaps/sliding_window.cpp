#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void sliding_window(vector<int>& nums,int k,vector<int>&result){
    priority_queue<pair<int,int>> p;
    for(int i=0;i<k;i++){
        p.push(make_pair(nums[i],i));
    }
    cout<<p.top().first<<endl;
    result.push_back(p.top().first);
    for(int i=k;i<nums.size();i++){
        while(!p.empty() && p.top().second<=(i-k)){
            p.pop();
        }
        p.push(make_pair(nums[i],i));
        cout<<p.top().first<<endl;
        result.push_back(p.top().first);
    }
}
int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    vector<int>result;
    sliding_window(nums,3,result);
}