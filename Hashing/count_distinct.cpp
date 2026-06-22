#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int main(){
    vector<int> nums = {4,3,2,5,6,7,3,4,2,1};
    unordered_set<int> s;
    for(int num:nums){
        s.insert(num);
    }
    for(int num:s){
        cout<<num<<" ";
    }
    cout<<endl;
    cout<<s.size();
}