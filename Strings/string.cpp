#include<iostream>
#include<string>
using namespace std;
int main(){
    string s = "hello";
    for(char ch:s){
        cout<<ch<<endl;
    }
    string s2 = s.substr(0,2);
    cout<<s2;
}