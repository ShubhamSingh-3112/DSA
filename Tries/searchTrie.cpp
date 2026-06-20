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

    bool search(string word){
        Node* temp = root;
        for(auto character:word){
            if(temp->children.count(character)!=0){
                temp = temp->children[character];
            }
            else{
                return false;
            }
        }
        return temp->endOfString;
    }
};
int main(){
    vector<string> words = {"the","a","there","their","any","thee"};
    Trie trie;
    for(auto word:words){
        trie.insert(word);
    }
    cout<<trie.search("theer");
}