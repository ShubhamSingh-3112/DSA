#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class queue{
    Node* head;
    Node* tail;
    public:
    queue(){
        head = NULL;
        tail = NULL;
    }
    void enqueue(int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        return;
    }
    int dequeue(){
        if(head==NULL){
            cout<<"Empty queue\n";
            return -1;
        }
        int data = head->data;
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return data;
    }
    int front(){
        if(head!=NULL){
            return head->data;
        }
    }
};
int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    cout<<q.dequeue();
    cout<<q.dequeue();
}