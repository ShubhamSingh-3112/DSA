#include<iostream>
#include<vector>
using namespace std;
int maxActivities(vector<int>start,vector<int>end){
    int count = 1;
    cout<<"Activity A0\n";
    int currEnd = end[0];
    for(int i=1;i<start.size();i++){
        if(start[i]>=currEnd){
            currEnd=end[i];
            cout<<"Activity A"<<i<<endl;
            count+=1;
        }
    }
    return count;
}
int main(){
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};
    cout<<maxActivities(start,end);
}