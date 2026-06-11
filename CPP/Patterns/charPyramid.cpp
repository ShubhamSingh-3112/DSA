#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n:";
    int character = 65;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<< (char) character++ <<" ";
        }
        cout<<endl;
    }
}