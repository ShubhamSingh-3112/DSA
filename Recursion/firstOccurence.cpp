#include<iostream>
#include <vector>
using namespace std;
int findOccurence(vector<int> &v,int i,int target){
    if(i>=v.size()){
        return -1;
    }
    if(v[i]==target){
        return i;
    }
    findOccurence(v,i+1,target);
}
int main(){
    vector <int> v = {1,2,3,4,5};
    cout<<findOccurence(v,0,3);
}