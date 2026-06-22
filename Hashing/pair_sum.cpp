#include<bits/stdc++.h>
using namespace std;
int main(){
        vector<int> nums = {1,2,7,11,15,5,9};
        int target = 14;
        unordered_map<int,int> m; // num, i
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int find = target - nums[i];
            if(m.count(find)==1){
                result.push_back(m[find]);
                result.push_back(i);
            }
            m[nums[i]] = i;
        }

        for(int i=0;i<result.size();i++){
            cout<<result[i]<<" ";
        }

}