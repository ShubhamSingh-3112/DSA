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

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (this->head == NULL)
        {
            this->head = this->tail = newNode;
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
        return;
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

    int pop_front()
    {
        if (head == NULL)
        {
            cout << "Empty List\n";
            return -1;
        }
        Node *temp = head;
        int data = temp->data;
        head = head->next;
        if (head == NULL)
        {
            tail = NULL;
        }
        temp->next = NULL;
        delete temp;
        return data;
    }
    int pop_back()
    {
        if (head == NULL)
        {
            cout << "Empty List\n";
            return -1;
        }
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        int data = temp->next->data;
        temp->next = NULL;
        delete tail;
        tail = temp;
        return data;
    }

    int search(int val)
    {
        Node *temp = head;
        int i = 0;
        while (temp != NULL)
        {
            if (temp->data == val)
            {
                return i;
            }
            i += 1;
            temp = temp->next;
        }
        return -1;
    }

    int recursiveSearch(Node* temp,int val,int i){
        if(temp==NULL){
            return -1;
        }
        if(temp->data == val){
            return i;
        }
        temp = temp->next;
        recursiveSearch(temp,val,i+=1);
    }
    int rsearch(int val){
        return recursiveSearch(head,val,0);
    }

    void deleteLL()
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            Node *deleteTemp = temp;
            temp = temp->next;
            this->head = temp;
            delete deleteTemp;
        }
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
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.insert(0, 1);
    ll.push_back(4);
    cout << ll.rsearch(6);
    // ll.print();
}