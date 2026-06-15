#include<iostream>
#include<vector>
using namespace std;
class stack{
    vector<int> s;
    public:
    bool isEmpty(){
        if(s.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int data){
        s.push_back(data);
    }
    int pop(){
        if(isEmpty()){
            cout<<"Empty Stack\n";
            return -1;
        }
        int data = s[s.size()-1];
        s.pop_back();
        return data;
    }
    int top(){
        if(isEmpty()){
            cout<<"Empty Stack\n";
            return -1;
        }
        return s[s.size()-1];
    }
};
int main(){
    stack s;
    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.isEmpty()){
        cout<<s.pop()<<endl;
    }
}