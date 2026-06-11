#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char arr[50];
    cin.getline(arr,50,'\n');
    bool flag = true;
    int st = 0;
    int end = strlen(arr)-1;
    while(st<end){
        if(arr[st++]!=arr[end--]){
            flag =false;
            break;
        }
    }
    if(flag){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not palindrome";
    }
}
