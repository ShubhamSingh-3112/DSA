#include<bits/stdc++.h>
using namespace std;
class Soldier{
    public:
    int idx;
    int count;
    Soldier(int idx,int count){
        this->idx = idx;
        this->count = count;
    }
    bool operator < (const Soldier &obj) const{
        if(this->count==obj.count){
            return this->idx > obj.idx;
        }
        return this->count > obj.count;
    }
};
void weakest_soldier(vector<vector<int>> &matrix,int k){
    int count;
    vector<Soldier> soldiers;
    for(int i=0;i<matrix.size();i++){
        count = 0;
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[i][j]==1){
                count+=1;
            }
        }
        soldiers.push_back(Soldier(i,count));
    }
    priority_queue<Soldier> p(soldiers.begin(),soldiers.end());
    for(int i=0;i<k;i++){
        cout<<p.top().idx<<endl;
        p.pop();
    }
}
int main(){
    vector<vector<int>> grid = {
    {1, 0, 0, 0},
    {1, 1, 1, 1},
    {1, 0, 0, 0},
    {1, 0, 0, 0}
};
    weakest_soldier(grid,2);
}