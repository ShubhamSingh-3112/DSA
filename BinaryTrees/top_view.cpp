#include <iostream>
#include <vector>
#include<queue>
#include<map>
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

void top_view(Node * root){
    map<int,int> ans; // contains horizontal distance and node value
    queue<pair<Node*,int>> Q; // contains node and the horizontal distance

    Q.push(make_pair(root,0));

    while(!Q.empty()){
        pair<Node*,int> cur = Q.front();Q.pop();
        Node * currNode = cur.first;
        int hd = cur.second;

        if(ans.count(hd)==0){
            ans[hd] = currNode->data;
        }

        // ans[hd] = currNode->data; for bottom view

        if(currNode->left!=NULL){
            Q.push(make_pair(currNode->left,hd-1));
        }
        if(currNode->right!=NULL){
            Q.push(make_pair(currNode->right,hd+1));
        }
    }

    for(auto it:ans){
        cout << it.second << " ";
    }

    return;
}

int main()
{
    vector<int> nodes = {
    1, 2, 4, -1, -1, 5, -1, -1,
    3, -1, 6, -1, -1
    };
    Node * root = buildTree(nodes);
    top_view(root);
}