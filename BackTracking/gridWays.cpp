#include<iostream>
using namespace std;
int gridWays(int row,int col,int n,int m,string str){
    if(row>=n||col>=m){
        return 0;
    }
    if(row==n-1 && col==m-1){
        cout<<str<<endl;
        return 1;
    }
    int rightWays = gridWays(row,col+1,n,m,str+'R');
    int downWays = gridWays(row+1,col,n,m,str+'D');
    return rightWays+downWays;
}

int main(){
    int n = 3;
    int m = 3;
    string str = "";
    cout<<gridWays(0,0,n,m,str);
}