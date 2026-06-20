#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Student{
    public:
    int marks;
    string name;
    Student(int marks,string name){
        this->marks = marks;
        this->name = name;
    }
    bool operator < (const Student &obj) const{
        return this->marks > obj.marks;
    }
};
int main(){
    priority_queue<Student> p;
    p.push(Student(100,"Shubham"));
    p.push(Student(10,"adhee"));
    while (!p.empty())
    {
        cout<<p.top().marks<<endl;
        p.pop();
    }
}