#include <iostream>
#include <vector>
#include <queue>
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

void level_order(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *cur = q.front();
        q.pop();
        if (cur == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
        }
        else
        {
            cout << cur->data << " ";
            if (cur->left != NULL)
            {
                q.push(cur->left);
            }
            if (cur->right != NULL)
            {
                q.push(cur->right);
            }
        }
    }
}

int main()
{
    vector<int> nodes = {
        1, 2, 4, -1, -1, 5, -1, -1,
        3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);
    level_order(root);
}