#include<iostream>
using namespace std;
#include<list>
#include<iterator>
void print(list<int> ll){
    list<int>::iterator itr;
    for(itr=ll.begin();itr!=ll.end();itr++){
        cout << (*itr) << ' ';
    }
    cout<<endl;
}
int main(){
    list<int> ll;
    ll.push_back(1);
    ll.push_back(2);
    print(ll);
}