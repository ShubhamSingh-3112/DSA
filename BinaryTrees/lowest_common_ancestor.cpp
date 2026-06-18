#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
    }
};

static int idx = -1;
Node *buildTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
    {
        return NULL;
    }
    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

bool find_path(Node *root, int n, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if (root->data == n)
    {
        return true;
    }

    bool find_left = find_path(root->left, n, path);
    bool find_right = find_path(root->right, n, path);

    if (find_left || find_right)
    {
        return true;
    }

    // if not found in both left and right subtree return false and pop current node from path as there is no chance of finding n from this node.
    path.pop_back();
    return false;
}

int LCA(vector<int> &path1, vector<int> &path2)
{
    int lca = path1[0];
    for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++)
    {
        if (path1[i] != path2[j])
        {
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}

Node* LCA2(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftLca = LCA2(root->left,n1,n2);
    Node* rightLca = LCA2(root->right,n1,n2);

    if(leftLca!=NULL && rightLca!=NULL){
        return root;
    }
    return leftLca==NULL ? rightLca : leftLca;
}

int main()
{
    vector<int> nodes = {
        1, 2, 4, -1, -1, 5, -1, -1,
        3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);
    vector<int> path1;
    vector<int> path2;
    find_path(root, 4, path1);
    for (int i = 0; i < path1.size(); i++)
    {
        cout << path1[i] << " ";
    }
    find_path(root, 5, path2);
    cout << endl;
    for (int i = 0; i < path2.size(); i++)
    {
        cout << path2[i] << " ";
    }
    cout << endl;
    cout << LCA(path1, path2) <<endl;

    cout << LCA2(root,4,5)->data;
}