#include<iostream>
#include<string>
using namespace std;
bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        int count[26] = {0};
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            int idx = t[i]-'a';
            if(count[idx]==0){
                return false;
            }
            count[idx]--;
        }
        return true;
    }
int main(){
    cout << isAnagram("anagram","nagrama");
}