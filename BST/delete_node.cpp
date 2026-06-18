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

Node* insert(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}


Node* buildTree(vector<int> &nodes){
    Node* root = NULL;
    for(int i=0;i<nodes.size();i++){
        root = insert(root,nodes[i]);
    }
    return root;
}


void inorder(Node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}

Node* inorderSuccessor(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* deleteNode(Node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(val<root->data){
        root->left = deleteNode(root->left,val);
    }
    else if(val>root->data){
        root->right = deleteNode(root->right,val);
    }
    else{
        // case 1 leaf node
        if(root->right==NULL && root->left==NULL){
            delete root;
            return NULL;
        }
        // case 2 one child
        else if(root->left==NULL||root->right==NULL){
            return root->left==NULL? root->right : root->left;
        }
        // case 3 both child
        else{
            Node* IS = inorderSuccessor(root->right);
            root->data = IS->data;
            // delete IS from right always not from root
            root->right = deleteNode(root->right,IS->data);
            return root;
        }
        return root;
    }
}
int main(){
    vector<int> nodes = {8,5,3,1,4,6,10,11,14};
    Node* root = buildTree(nodes);
    inorder(root);cout<<endl;
    root = deleteNode(root,10);
    inorder(root);
}