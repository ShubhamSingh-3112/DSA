#include<iostream>
using namespace std;
void binary_string(int n,int lastPlace,string ans){
    if(n==0){
        cout << ans <<endl;
        return ;
    }
    if(lastPlace!=1){
        binary_string(n-1,0,ans+'0');
        binary_string(n-1,1,ans+'1');
    }
    else{
        binary_string(n-1,0,ans+'0');
    }
}
void binary_string2(int n,string ans){
    if(n==0){
        cout << ans <<endl;
        return ;
    }
    if(ans[ans.size()-1]!='1'){
        binary_string(n-1,0,ans+'0');
        binary_string(n-1,1,ans+'1');
    }
    else{
        binary_string(n-1,0,ans+'0');
    }
}
int main(){
    string ans = "";
    // binary_string(3,0,ans);
    binary_string2(3,ans);
}