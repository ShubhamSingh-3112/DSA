#include<iostream>
using namespace std;
#include<vector>
int main()
{
    vector <int> v1 ;
    vector <int> v2 = {1,2,3,4,5};
    vector <int> v3(5,-1);//fill constructor to make vector of size 5 with values -1
    for(int i=0;i<v3.size();i++){
        cout<<v2[i]<< ' ' << v3[i];
        cout<<endl;
    }
    v2.pop_back();
}