#include<iostream>
using namespace std;
class student{
   int a,b;
   public:
   student(int a,int b){
    this->a=a;
    this->b=b;
   }
   student(student &some){
    this->a = some.a;
    this->b = some.b;
   }
   int operator + (student &c)
   {
        return a+c.a;
   }
};
int main()
{
    student m(1,2);
    student b(m);

    
}