#include<iostream>
using namespace std;
int main(){
    int * i = new int[5];
    i[0] = 5;
    cout<<(&i[0]);
}