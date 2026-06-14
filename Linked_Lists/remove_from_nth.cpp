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
    
    int getSize(){
        if(head==NULL){
            return 0;
        }
        Node*temp = head;
        int size = 0;
        while(temp!=NULL){
            size+=1;
            temp=temp->next;
        }
        return size;
    }

    void deleteNth(int n){
        int size = getSize();
        Node* temp = head;
        for(int i=1;i<size-n;i++){
            temp = temp->next;
        }
        if(temp==head){
            head = head->next;
            temp->next = NULL;
            delete temp;
            return;
        }
        Node* toDel = temp->next;
        temp->next = temp->next->next;
        toDel->next = NULL;
        delete toDel;
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
    ll.deleteNth(4);
    cout<<endl;
    ll.print();
}