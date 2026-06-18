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

bool kth_ancestor(Node*root,int n,int &k){
    if(root==NULL){
        return false;
    }
    if(root->data==n){
        return true;
    }
    bool left = kth_ancestor(root->left,n,k);
    bool right = kth_ancestor(root->right,n,k);

    if(left||right){
        k--;
        if(k==0){
            cout<<root->data<<endl;
        }
        return true;
    }
    return false;
}

int main()
{
    vector<int> nodes = {
    1, 2, 4, -1, -1, 5, -1, -1,
    3, -1, 6, -1, -1
    };
    Node * root = buildTree(nodes);
    int k = 1;
    kth_ancestor(root,6,k);
}