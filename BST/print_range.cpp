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

void print_range(Node* root,int start,int end){
    if(root==NULL){
        return;
    }
    if(start<=root->data && root->data<=end){
        print_range(root->left,start,end);
        cout<<root->data<<" ";
        print_range(root->right,start,end);
    }
    else if(root->data<start){
        print_range(root->right,start,end);
    }
    else if(root->data>end){
        print_range(root->left,start,end);
    }
}

int main(){
    vector<int> nodes = {8,5,3,1,4,6,10,11,14};
    Node* root = buildTree(nodes);
    inorder(root);
    cout<<endl;
    print_range(root,5,12);
}