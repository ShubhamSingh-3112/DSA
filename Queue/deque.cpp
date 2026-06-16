#include<iostream>
using namespace std;
#include<deque>
class Queue{
    deque<int> deq;
    public:
    void push(int data){
        deq.push_back(data);
    }
    void pop(){
        if(!deq.empty()){
            deq.pop_front();
        }
    }
    int front(){
        return deq.front();
    }
    bool empty(){
        return deq.empty();
    }
};
class Stack{
    deque<int> deq;
    public:
    void push(int data){
        deq.push_back(data);
    }
    void pop(){
        if(!deq.empty()){
            deq.pop_back();
        }
    }
    int top(){
        return deq.back();
    }
    bool empty(){
        return deq.empty();
    }
};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

}