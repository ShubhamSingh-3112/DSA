#include<iostream>
using namespace std;
#include<queue>
char firstNonRepeat(string str){
    queue <char> q;
    int freq[26] = {0};
    for(int i=0;i<str.size();i++){
        freq[str[i]-'a']+=1;
        q.push(str[i]);
    }
    while(!q.empty() && freq[q.front()-'a']>1){
        q.pop();
    }
    if(q.empty()){
        return -1;
    }
    return q.front();
}
int main(){
    string str = "aabccxb";
    cout<<firstNonRepeat(str);
}
