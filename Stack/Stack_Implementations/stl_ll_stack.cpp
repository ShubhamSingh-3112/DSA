#include<iostream>
using namespace std;
#include<list>
class stack{
    public:
    list<int> l;
    bool isEmpty(){
        if(l.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int data){
        l.push_back(data);
    }
    int pop(){
        if(!isEmpty()){
            int data = *(l.end());
            l.pop_back();
            return data;
        }
    }
    int top(){
        if(!isEmpty()){
            return *(l.end());
        }
    }
};
int main(){
    stack s ;
    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.isEmpty()){
        cout<<s.pop()<<endl;
    }
}