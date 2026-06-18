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


Node* LCA(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftLca = LCA(root->left,n1,n2);
    Node* rightLca = LCA(root->right,n1,n2);

    if(leftLca!=NULL && rightLca!=NULL){
        return root;
    }
    return leftLca==NULL ? rightLca : leftLca;
}

int find_dist(Node* root,int n){
    if(root==NULL){
        return -1;
    }
    if(root->data==n){
        return 0;
    }
    int leftDist = find_dist(root->left,n);
    if(leftDist!=-1){
        return 1 + leftDist;
    }
    int rightDist = find_dist(root->right,n);
    if(rightDist!=-1){
        return 1 + rightDist;
    }
    return -1;
}


// to find minimum distance find lca then find the dist to lca for both nodes and return the sum

int min_dist(Node*root,int n1,int n2){
    Node * lca = LCA(root,n1,n2);

    int dist1 = find_dist(lca,n1);
    int dist2 = find_dist(lca,n2);
 
    return dist1 + dist2;
}

int main()
{
    vector<int> nodes = {
    1, 2, 4, -1, -1, 5, -1, -1,
    3, -1, 6, -1, -1
    };
    Node * root = buildTree(nodes);
    cout<<min_dist(root,1,2);
}