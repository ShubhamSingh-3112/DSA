#include<iostream>
using namespace std;
void subsets(string str,string subset){
    if(str.size()==0){
        cout << subset << " ";
        return;
    }
    char ch = str[0];
    subsets(str.substr(1,str.size()-1),subset+ch);
    subsets(str.substr(1,str.size()-1),subset);
}
int main(){
    string str = "abc";
    string subset = "";
    subsets(str,subset);
}