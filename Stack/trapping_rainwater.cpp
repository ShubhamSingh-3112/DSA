#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> heights = {4,2,0,6,3,2,5};
    int left = 0;
    int right = heights.size()-1;
    int leftMax = heights[left];
    int rightMax = heights[right];
    int water = 0;
    while(left<right){
        if(leftMax<rightMax){
            left+=1;
            leftMax = max(leftMax,heights[left]);
            water+=leftMax-heights[left];
        }
        else{
            right-=1;
            rightMax = max(heights[right],rightMax);
            water+=rightMax-heights[right];
        }
    }
    cout<<water;
}