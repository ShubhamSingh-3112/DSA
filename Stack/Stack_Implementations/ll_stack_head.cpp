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
            return;
        }
        newNode->next = head;
        head = newNode;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Empty List\n";
            return -1;
        }
        Node*temp = head;
        head = head->next;
        int data = temp->data;
        temp->next = NULL;
        delete temp;
        return data;
    }
    int top(){
        if(isEmpty()){
            cout<<"Empty List\n";
            return -1;
        }
        return head->data;
    }
};
int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.isEmpty()){
        cout<<s.pop()<<endl;
    }
}