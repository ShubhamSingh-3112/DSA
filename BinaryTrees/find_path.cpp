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


bool find_path(Node* root,int n,vector<int> &path){
    if(root==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }
    
    bool find_left = find_path(root->left,n,path);
    if(find_left){
        return true;
    }

    bool find_right = find_path(root->right,n,path);

    if(find_right){
        return true;
    }

    // if(find_left||find_right){
    //     return true;
    // }

    // if not found in both left and right subtree return false and pop current node from path as there is no chance of finding n from this node.
    path.pop_back();
    return false;
}


int main()
{
    vector<int> nodes = {
    1, 2, 4, -1, -1, 5, -1, -1,
    3, -1, 6, -1, -1
    };
    Node * root = buildTree(nodes);
    vector<int> path;
    find_path(root,6,path);
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
}