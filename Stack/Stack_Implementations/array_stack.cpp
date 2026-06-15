#include<iostream>
using namespace std;
class stack{
    int topIdx;
    int array[1000];
    public:
    stack(){
        this->topIdx  = -1;
    }
    void push(int data){
        array[++topIdx] = data;
        return;
    }
    int pop(){
        if(topIdx==-1){
            cout<<"Stack Empty";
            return -1;
        }
        return array[topIdx--];
    }
    int top(){
        return array[topIdx];
    }
};
int main(){
    stack s;
    s.push(1);
    s.push(2);
    cout<<s.pop();
    s.pop();
    s.pop();
    cout<<s.top();
}