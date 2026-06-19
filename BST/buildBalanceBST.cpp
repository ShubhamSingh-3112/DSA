#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};




Node* buildBalanceTree(vector<int> &nodes,int start,int end){
    if(start>end){
        return NULL;
    }
    int mid = start + (end-start)/2;
    Node * cur = new Node(nodes[mid]);
    cur->left = buildBalanceTree(nodes,start,mid-1);
    cur->right = buildBalanceTree(nodes,mid+1,end);
    return cur;
}

Node* getInorderSequence(Node* root,vector<int> &nodes){
    if(root==NULL){
        return NULL;
    }
    getInorderSequence(root->left,nodes);
    nodes.push_back(root->data);
    getInorderSequence(root->right,nodes);
}


Node* buildBalanceFROMBst(Node* root){
    vector<int> nodes;
    getInorderSequence(root,nodes);
    for(int i=0;i<nodes.size();i++){
        cout<<nodes[i]<<" ";
    }
    return buildBalanceTree(nodes,0,nodes.size()-1);
}

void inorder(Node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}
void preorder(Node * root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<' ';
    preorder(root->left);
    preorder(root->right);
}
int main(){
    vector<int> nodes = {3,4,5,6,7,8,9};
    Node* root = buildBalanceTree(nodes,0,nodes.size()-1);
    inorder(root);
    cout<<endl;
    preorder(root);
}