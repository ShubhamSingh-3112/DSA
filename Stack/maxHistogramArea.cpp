#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int maxHistoArea(vector<int> heights){
    stack<int> s;
    vector<int> leftSmaller(heights.size());
    vector<int> rightSmaller(heights.size());

    leftSmaller[0] = -1;
    s.push(0);
    for(int i = 1;i<heights.size();i++){
        while(!s.empty() && heights[s.top()]>=heights[i]){
            s.pop();
        }
        if(s.empty()){
            leftSmaller[i] = -1;
        }
        else{
            leftSmaller[i] = s.top();
        }
        s.push(i);
    }


    while(!s.empty()){
        s.pop();
    }


    int n = heights.size();
    rightSmaller[heights.size()-1] = n;
    s.push(n-1);
    for(int i=n-2;i>=0;i--){
        while(!s.empty() && heights[s.top()]>=heights[i]){
            s.pop();
        }
        if(s.empty()){
            rightSmaller[i] = n;
        }
        else{
            rightSmaller[i] = s.top();
        }
        s.push(i);
    }

    int maxarea = 0;
    for(int i=0;i<heights.size();i++){
        int area = heights[i] * (rightSmaller[i]-leftSmaller[i]-1);
        maxarea = max(area,maxarea);
    }
    return maxarea;
}
int main(){
    vector<int> heights = {2,1,5,6,2,3};
    cout<<maxHistoArea(heights);
}