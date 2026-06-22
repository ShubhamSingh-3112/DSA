#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void Union(vector<int> arr1,vector<int> arr2){
    unordered_set<int> s;
    for(int num:arr1){
        s.insert(num);
    }
    for(int num:arr2){
        s.insert(num);
    }
    cout<<"Union:";
    for(int num:s){
        cout<<num<<" ";
    }
    cout<<endl;
}
void intersection(vector<int> arr1,vector<int> arr2){
    unordered_set<int> s;
    unordered_set<int> ans;
    for(int num:arr1){
        s.insert(num);
    }
    for(int num:arr2){
        if(s.find(num)!=s.end()){
            ans.insert(num);
        }
    }
    cout<<"Intersection:";
    for(int num:ans){
        cout<<num<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr1 = {7,3,9};
    vector<int> arr2 = {6,3,9,2,9,4};
    Union(arr1,arr2);
    intersection(arr1,arr2);
}