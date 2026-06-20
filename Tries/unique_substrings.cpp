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
    int countNodes(Node* root){
        int ans = 0;
        for(auto child:root->children){
            ans+=countNodes(child.second);
        }
        return ans+1; // return 0 + 1 if last node
    }
};

int unique_substrings(string s){
    Trie trie;
    for(int i=0;i<s.size();i++){
        trie.insert(s.substr(i));
    }

    return trie.countNodes(trie.root);
}

int main(){
    // vector<string> words = {"the","a","there","their","any","thee"};
    // Trie trie;
    // for(auto word:words){
    //     trie.insert(word);
    // }

    string s = "ababa";
    cout << unique_substrings(s);
}