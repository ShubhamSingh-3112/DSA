#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1 = "cara";
    string s2 = "race";
    if(s1.size()!=s2.size()){
        return -1;
    }

    unordered_map<char,int> count;
    for(auto character:s1){
        if(count.count(character)==0){
            count[character]=1;
        }
        else{
            count[character]+=1;
        }
    }
    for(auto character:s2){
        if(count.count(character)==0){
            cout<<"Not anagram"<<endl;
            return -1;
        }
        else{
            count[character]-=1;
            if(count[character]==0){
                count.erase(character);
            }
        }
    }
    if(count.size()==0){
        cout<<"Anagram"<<endl;
    }
    else{
        cout<<"Not anagram"<<endl;
    }
    
    
}