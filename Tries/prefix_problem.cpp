#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
class Node{
    public:
    unordered_map<char,Node*> children;
    bool endOfString;
    int freq;
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
                temp->children[word[i]]->freq = 1;
            }
            else{
                temp->children[word[i]]->freq +=1;
            }
            temp = temp->children[word[i]];
        }
        temp->endOfString = true;
    }
    string getPrefix(string word){
        Node* temp = root;
        string prefix = "";
        for(auto character:word){
            prefix+=character;
            if(temp->children[character]->freq==1){
                break;
            }
            temp = temp->children[character];
        }
        return prefix;
    }
};
int main(){
    vector<string> words = {"the","a","there","their","any","thee"};
    Trie trie;
    vector<string> words2 = {"zebra","dove","duck","dog"};
    for(auto word:words2){
        trie.insert(word);
    }
    for(auto word:words2){
        cout<<trie.getPrefix(word)<<endl;
    }
}