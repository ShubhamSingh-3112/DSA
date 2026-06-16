#include<iostream>
using namespace std;
class Queue{
    int * arr;
    int currSize;
    int capacity;
    int f,r;
    public:
    Queue(int capacity){
        this->capacity = capacity;
        arr = new int(capacity);
        currSize = 0;
        f = 0;
        r = -1;
    }
    void push(int data){
        if(currSize==capacity){
            cout<<"Queue Full\n";
            return;
        }
        r = (r+1)%capacity;
        arr[r] = data;
        currSize+=1;
    }
    int pop(){
        if(empty()){
            cout<<"Queue Empty\n";
            return -1;
        }
        int data = arr[f];
        f = (f+1)% capacity;
        currSize--;
        return data;
    }
    bool empty(){
        return currSize==0;
    }
}
;
int main(){
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.push(5);
    while(!q.empty()){
        cout<<q.pop()<<endl;
    }
}