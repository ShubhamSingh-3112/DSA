#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int> &val,vector<int> &wt,int w,int n){
    if(n<0 || w==0){ 
        return 0;
    }
    if (w>=wt[n-1]){
        int included = knapsack(val,wt,w-wt[n-1],n-1) + val[n-1];
        int excluded = knapsack(val,wt,w,n-1);
        return max(included,excluded);
    }
    else{
        return knapsack(val,wt,w,n-1);
    }
}


int main(){
    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int w = 7;
    int n = val.size();
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    cout<<knapsack(val,wt,w,val.size());
}