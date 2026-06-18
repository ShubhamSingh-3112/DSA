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

bool isIdentical(Node* r1,Node* r2){
    if(r1==NULL && r2==NULL){
        return true;
    }
    else if (r1==NULL||r2==NULL){
        return false;
    }

    if(r1->data!=r2->data){
        return false;
    }

    return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
}

bool isSubtree(Node * root,Node * subRoot){
    if(root==NULL && subRoot==NULL){
        return true;
    }
    else if(root==NULL||subRoot==NULL){
        return false;
    }

    if(root->data==subRoot->data){
        if(isIdentical(root,subRoot)){
            return true;
        }
    }

    int leftCheck = isSubtree(root->left,subRoot);
    if(!leftCheck){
        return isSubtree(root->right,subRoot);
    }
    return true;
}


int main()
{
    vector<int> nodes = {
    1, 2, 4, -1, -1, 5, -1, -1,
    3, -1, 6, -1, -1
    };
    vector<int> subNodes = {
        2, 4, -1, -1, 5, -1, -1,
    };
    Node * subRoot = buildTree(subNodes);
    idx=-1;
    Node * root = buildTree(nodes);
    cout << isSubtree(root,subRoot);

}