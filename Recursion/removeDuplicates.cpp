#include<iostream>
using namespace std;

void removeDuplicates(string str,string ans,int i,bool map[]){
    if(i==str.size()){
        cout << ans;
        return;
    }
    int mapIdx = str[i] - 'a';

    if(map[mapIdx]){
        removeDuplicates(str,ans,i+1,map);
    }
    else{
        map[mapIdx] = true;
        removeDuplicates(str,ans+str[i],i+1,map);
    }
}


void removeDuplicatesWithoutI(string str,string ans,bool map[]){
    if(str.size()<=0){
        cout<<ans;
        return;
    }

    char ch = str[str.size()-1];
    int mapIdx = ch - 'a';
    str = str.substr(0,str.size()-1);

    if(map[mapIdx]){
        removeDuplicatesWithoutI(str,ans,map);
    }
    else{
        map[mapIdx]=true;
        removeDuplicatesWithoutI(str,ch+ans,map);
    }
}
int main(){
    bool map[26] = {false};
    string ans = "";
    string str = "apnaacollege";
    // removeDuplicates(str,ans,0,map);
    removeDuplicatesWithoutI(str,ans,map);
}