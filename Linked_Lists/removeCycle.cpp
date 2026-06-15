#include <iostream>
using namespace std;
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

public:
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
    
    bool checkCycle(){
        Node* slow = head;
        Node * fast = head;
        while(fast!=NULL and fast->next!=NULL){
            slow= slow->next;
            fast = fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }

    void removeCycle(){
        Node* slow = head;
        Node * fast = head;
        bool isCycle = false;
        while(fast!=NULL and fast->next!=NULL){
            slow= slow->next;
            fast = fast->next->next;
            if(slow==fast){
                isCycle = true;
                break;
            }
        }
        if(!isCycle){
            return;
        }
        slow = head;
        if(fast==slow){
            while(fast->next!=slow){
                fast=fast->next;
            }
            fast->next=NULL;
            return;
        }
        Node* prev = fast;
        while(fast!=slow){
            slow=slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL;
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

    
};
int main()
{
    List ll;
    ll.insert(1,0);
    ll.insert(2,1);
    ll.insert(3,2);
    ll.insert(4,3);
    ll.tail->next = ll.head;
    ll.removeCycle();
    ll.print();
}