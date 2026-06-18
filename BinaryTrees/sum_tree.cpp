#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
    int data;
    Node * left;
    Node * right;
    Node(int data){
        this->data = data;
    }
};

static int idx = -1;
Node* buildTree(vector<int>nodes){
    idx++;
    if(nodes[idx]==-1){
        return NULL;
    }
    Node * currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}



int sum_tree(Node * root){
    if(root==NULL){
        return 0;
    }
    int oldVal = root->data;

    int leftOld = sum_tree(root->left);
    int rightOld = sum_tree(root->right);

    root->data = leftOld + rightOld;
    // if(root->left!=NULL){
    //     root->data+=root->left->data;
    // }
    // if(root->right!=NULL){
    //     root->data+=root->right->data;
    // }
    return oldVal+leftOld+rightOld;
}

int main()
{
    vector<int> nodes = {
    1, 2, 4, -1, -1, 5, -1, -1,
    3, -1, 6, -1, -1
    };
    Node * root = buildTree(nodes);
    sum_tree(root);
    cout<<root->left->data;
}