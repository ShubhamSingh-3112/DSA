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

class Info{
    public:
    bool isBST;
    int min;
    int max;
    int size;
    int sum;
    Info(bool isBST,int min,int max,int size,int sum){
        this->isBST = isBST;
        this->min = min;
        this->max = max;
        this->size = size;
        this->sum = sum;
    }
};

static int maxSize = 0;
static int maxSum = 0;
Info* find_largest(Node* root){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        return new Info(true,root->data,root->data,1,root->data);
    }

    // if(root==NULL){
    // return new Info(true,INT32_MAX,INT32_MIN,0)}

    Info* leftInfo = find_largest(root->left);
    Info* rightInfo = find_largest(root->right);

    bool isBst = false;
    int minimum = min(root->data,min(leftInfo->min,rightInfo->min));
    int maximum = max(root->data,max(leftInfo->max,rightInfo->max));
    int size = 1 + leftInfo->size + rightInfo->size;
    int curSum = root->data + leftInfo->sum + rightInfo->sum;
    if(leftInfo->isBST && rightInfo->isBST
        && root->data > leftInfo->max && root->data < rightInfo->min
    ){
        isBst = true;
        maxSize = max(maxSize,size);
        maxSum = max(maxSum,curSum);
        return new Info(isBst,minimum,maximum,size,curSum);
    }
    return new Info(false,minimum,maximum,size,curSum);
}


void inorder(Node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}


int main(){
    Node* root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(60);

    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right->left = new Node(45);
    root->right->right = new Node(70);

    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);
    inorder(root);
    Info* info = find_largest(root);
    cout<<endl;
    cout<<maxSize;
    cout<<endl<<maxSum;
}