#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums = {1,3,2,5,1,3,1,5,1};
    unordered_map<int,int> count;
    for(auto num:nums){
        if(count.count(num)==0){
            count[num]=1;
        }
        else{
            count[num]+=1;
        }
    }
    for(auto item:count){
        if(item.second > nums.size()/3){
            cout<<item.first<<" ";
        }
    }
}