#include<iostream>
using namespace std;
int maxStored(int heights[],int n){
    int leftMax[7];
    leftMax[0] = heights[0];
    for(int i=1;i<n;i++){
        leftMax[i] = max(leftMax[i-1],heights[i-1]);
    }
    int rightMax[7];
    rightMax[n-1] = heights[n-1];
    for(int i = n-2;i>=0;i--){
        rightMax[i] = max(rightMax[i+1],heights[i+1]);
    }

    int waterStored = 0;
    for(int i = 0;i<n;i++){
        int currLevel = min(leftMax[i],rightMax[i]) - heights[i];
        if(currLevel>0){
            waterStored+=currLevel;
        }
    }
    return waterStored;
}
int main(){
    int heights[] = {4,2,0,6,3,2,5};
    int n = sizeof(heights)/sizeof(int);
    cout<<maxStored(heights,n);
}