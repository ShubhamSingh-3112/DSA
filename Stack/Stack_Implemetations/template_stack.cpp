#include<iostream>
#include<vector>
using namespace std;
template<class T>
class stack{
    vector<T> s;
    public:
    bool isEmpty(){
        if(s.size()==0){
            return true;
        }
        else{
            return false;
        }
    }
    void push(T data){
        s.push_back(data);
    }
    T pop(){
        // if(isEmpty()){
        //     cout<<"Empty Stack\n";
        //     return -1;
        // }
        T data = s[s.size()-1];
        s.pop_back();
        return data;
    }
    T top(){
        // if(isEmpty()){
        //     cout<<"Empty Stack\n";
        //     return -1;
        // }
        return s[s.size()-1];
    }
};
int main(){
    stack<int> s;
    s.push(3);
    s.push(2);
    s.push(1);
    while(!s.isEmpty()){
        cout<<s.pop()<<endl;
    }
    stack<string> s2;
    s2.push("hello");
    s2.push("hi");
    s2.push("hh");
    while(!s2.isEmpty()){
        cout<<s2.pop()<<endl;
    }

    
}
