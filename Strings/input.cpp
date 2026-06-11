#include<iostream>
using namespace std;
#include<cstring>
int main()
{
    char arr[50];
    cout<<"Enter string:";cin.getline(arr,50,'\n');
    for(int i=0;i<strlen(arr);i++){
        if((int)arr[i]>=97){
            arr[i] = (char)(arr[i]-32);
        }
    }
    cout<<arr;
}
