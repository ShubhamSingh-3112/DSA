#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class stack{
    public:
    Node * head;
    Node * tail;
    stack(){
        head=NULL;
    }
    bool isEmpty(){
        if(head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int data){
        Node * newNode = new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Empty List\n";
            return -1;
        }
        if(head->next==NULL){
            Node*temp = head;
            int data = head->data;
            head = NULL;
            tail = NULL;
            delete temp;
            return data;
        }
        Node* temp = head;
        Node* prev = NULL;
        while(temp->next!=NULL){
            prev = temp;
            temp = temp->next;
        }
        int data = temp->data;
        prev->next = NULL;
        tail = prev;
        delete temp;
        return data;
    }
    int top(){
        if(isEmpty()){
            cout<<"Empty List\n";
            return -1;
        }
        return tail->data;
    }
};
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
}