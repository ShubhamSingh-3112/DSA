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
    bool hasPrefix(string prefix){
        Node* temp = root;
        for(auto character:prefix){
            if(temp->children.count(character)==0){
                return false;
            }
            temp = temp->children[character];
        }
        return true;
    }
};
int main(){
    vector<string> words = {"apple","app","mango","man","woman"};
    Trie trie;
    for(auto word:words){
        trie.insert(word);
    }
    string prefix = "app";
    cout<<trie.hasPrefix(prefix);
    cout<<endl;
    cout<<trie.hasPrefix("moon");
}