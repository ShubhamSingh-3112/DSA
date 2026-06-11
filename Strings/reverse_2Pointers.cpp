#include<iostream>
using namespace std;
#include<cstring>
int main(){
    char arr[50];
    cin.getline(arr,50,'\n');
    int st=0;
    int end = strlen(arr)-1;
    while(st<end){
        swap(arr[st++],arr[end--]);
    }
    cout << arr;
    
}