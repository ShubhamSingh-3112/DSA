#include<iostream>
using namespace std;
void staircase(int mat[][4],int n,int target){
    int row = n-1;
    int col = 0;
    while(row>=0 && col<4){
        int cell = mat[row][col];
        if(cell==target){
            cout<<row<<','<<col<<endl;
            break;
        }
        else if(cell<target){
            col+=1;
        }
        else if(cell>target){
            row-=1;
        }
    }
}
void staircase2(int mat[][4],int n,int target){
    int row = 0;
    int col = n-1;
    while(row<n && col>=0){
        int cell = mat[row][col];
        if(cell==target){
            cout<<row<<','<<col<<endl;
            break;
        }
        else if(cell<target){
            row+=1;
        }
        else if(cell>target){
            col-=1;
        }
    }
}
int main(){
    int mat[4][4] = {
    {10, 20, 30, 40},
    {15, 25, 35, 45},
    {27, 29, 37, 48},
    {32, 33, 39, 50}
};
    staircase2(mat,4,33);
}