#include <iostream>
using namespace std;
void print_decreasing(int n){
    if(n==0){
        return ;
    }
    cout << n << " ";
    print_decreasing(n-1);
}
int main(){
    int n;
    cout<<"Enter number:";cin>>n;
    print_decreasing(n);
}