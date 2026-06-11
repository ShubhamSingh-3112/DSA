#include<iostream>
using namespace std;
#include<cstring>
int main(){
    char arr[50];
    cout<<"Enter string:";cin.getline(arr,50,'\n');
    int j=0;
    for(int i=strlen(arr)-1;i>=j;i--){
        swap(arr[j],arr[i]);
        j++;
    }
    cout<<arr;
}