#include<iostream>
#include<vector>
using namespace std;
int lcs(string str1,string str2){
    if(str1.size()==0||str2.size()==0){
        return 0;
    }
    int n = str1.size();
    int m = str2.size();
    if(str1[n-1]==str2[m-1]){
        return 1 + lcs(str1.substr(0,n-1),str2.substr(0,m-1));
    }
    else{
        return max(lcs(str1.substr(0,n-1),str2),lcs(str1,str2.substr(0,m-1)));
        // one time reduce str1 and other time reduce str2 and keep the other one same
    }
}
int main(){
    cout<<lcs("abcdge","abedg");
}