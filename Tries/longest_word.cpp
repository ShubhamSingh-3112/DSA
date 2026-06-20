#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
class Node{
    public:
    unordered_map<char,Node*> children;
    bool endOfString;
    Node(){
        this->endOfString = false;
    }
};
class Trie{
    public:
    Node* root;
    Trie(){
        this->root = new Node();
    }
    void insert(string word){
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(!(temp->children.count(word[i]))){
                temp->children[word[i]] = new Node;
            }
            temp = temp->children[word[i]];
        }
        temp->endOfString = true;
    }

    void helper(Node*root,string &ans,string temp){
        for(auto child:root->children){
            if(child.second->endOfString==true){
                temp+=child.first;
                if(temp.size()>ans.size()||temp.size()==ans.size() && temp<ans){
                    ans = temp;
                }
                helper(child.second,ans,temp);
                temp=temp.substr(0,temp.size()-1);
            }
        }
    }

    string longest_word(){
        string ans = "";
        helper(root,ans,"");
        return ans;
    }
};
int main(){
    vector<string> words = {"a","banana","apple","apply","ap","appl","app"};
    Trie trie;
    for(auto word:words){
        trie.insert(word);
    }
    cout << trie.longest_word();
}