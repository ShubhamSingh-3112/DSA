#include<iostream>
#include <vector>
using namespace std;
int findOccurence(vector<int> &v,int i,int target){
    if(i==-1){
        return -1;
    }
    if(v[i]==target){
        return i;
    }
    findOccurence(v,i-1,target);
}
int main(){
    vector <int> v = {1,2,3,3,3};
    cout<<findOccurence(v,v.size()-1,3);
}