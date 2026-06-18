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

int find_height(Node * root){
    if(root==NULL){
        return 0;
    }
    int leftHeight = find_height(root->left);
    int rightHeight = find_height(root->right);
    return 1 + max(leftHeight,rightHeight);
}

int diameter1(Node * root){
    if(root==NULL){
        return 0;
    }
    int curr = 1  + find_height(root->left) + find_height(root->right);
    int leftDiam = diameter1(root->left);
    int rightDiam = diameter1(root->right);
    return max(max(curr,leftDiam),rightDiam);
}

pair<int,int> diameter2(Node * root){
    if(root==NULL){
        int height = 0;
        int diam = 0;
        return make_pair(diam,height);
    }
    pair<int,int> leftPair = diameter2(root->left);
    pair<int,int> rightPair = diameter2(root->right);

    int curDiam = leftPair.second + rightPair.second + 1;
    int height = 1 + max(leftPair.second,rightPair.second);

    int finalDiam = max(max(curDiam,leftPair.first),rightPair.first);
    return make_pair(finalDiam,height);
}

int main()
{
    vector<int> nodes = {
    1, 2, 4, -1, -1, 5, -1, -1,
    3, -1, 6, -1, -1
    };
    Node * root = buildTree(nodes);
    cout<<diameter1(root);
    cout<<endl;
    cout<<diameter2(root).first;
}