#include <iostream>
using namespace std;
int findPair(int n){
    if(n==1||n==2){
        return n;
    }
    return findPair(n-1) + (n-1)*findPair(n-2);
}
int main(){
    cout << findPair(5);
}