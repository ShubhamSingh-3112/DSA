#include<iostream>
using namespace std;
#include<stack>
#include<string>
string reverse(stack<char>&s,string &str,string ans){
    for(int i=0;i<str.size();i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    return ans;
}
int main(){
    string str = "abcd";
    stack<char> s;
    string ans = reverse(s,str,"");
    cout<<ans;
}