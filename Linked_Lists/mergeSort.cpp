#include <iostream>
using namespace std;
#include<list>
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        // cout<<"~Node:"<<data<<endl;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};
class List
{
    

public:
    Node *head;
    Node *tail;
    List()
    {
        this->head = NULL;
        this->tail = NULL;
    }
    ~List()
    {
        // cout<<"~List"<<endl;
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

    void insert(int val, int pos)
    {
        Node *newNode = new Node(val);
        if (pos == 0)
        {
            newNode->next = this->head;
            this->head = newNode;
            return;
        }
        Node *temp = this->head;
        for (int i = 0; temp != NULL && i < pos - 1; i++)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Invalid Position\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL)
        {
            this->tail = newNode;
        }
        return;
    }


    void print()
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << ' ';
            temp = temp->next;
        }
        cout << endl;
    }

    Node* splitAtMid(Node * head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        while(fast!=NULL && fast->next!=NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        return slow;
    }

    
    Node* mergeSort(Node*head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        Node* rightHead = splitAtMid(head);
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);
        return merge(left,right);
    }
    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (this->head == NULL)
        {
            this->head = this->tail = newNode;
            return;
        }
        this->tail->next = newNode;
        this->tail = newNode;
        return;
    }

    Node* merge(Node* head,Node* rightHead){
        List* newList = new List();
        Node* left = head;
        Node * right = rightHead;
        while(left!=NULL and right!=NULL){
            if(left->data<=right->data){
                newList->push_back(left->data);
                left=left->next;
            }
            else{
                newList->push_back(right->data);
                right = right->next;
            }
        }
        while(left!=NULL){
            newList->push_back(left->data);
            left=left->next;
        }
        while(right!=NULL){
            newList->push_back(right->data);
            right = right->next;
        }
        return newList->head;
    }
};
int main()
{
    List ll;
    ll.insert(1,0);
    ll.insert(2,1);
    ll.insert(3,2);
    ll.insert(4,3);
    // ll.insert(5,4);
    ll.head = ll.mergeSort(ll.head);
    ll.print();
}