#include<iostream>
using namespace std;
#include<vector>
class Heap{
    public:
    vector<int> vec;
    void push(int value){
        vec.push_back(value); // insert at end
        // fix the heap by swapping child and parent
        int childIdx = vec.size()-1;
        int parentIdx = (childIdx-1)/2;
        while(parentIdx>=0 && vec[childIdx]<vec[parentIdx]){
            swap(vec[childIdx],vec[parentIdx]);
            childIdx = parentIdx;
            parentIdx = (childIdx-1)/2;
        }
    }
    void iterativeHeapify(){
        if(vec.size()==1||vec.size()==0){
            return;
        }
        int parent = 0;
        while(true){
            int largest = parent;
            int left = 2*parent + 1;
            int right = 2*parent + 2;

            if(left<vec.size() && vec[left]<vec[largest]){
                largest = left;
            }
            if(right<vec.size() && vec[right]<vec[largest]){
                largest = right;
            }
            if(largest==parent){
                return;
            }
            swap(vec[parent],vec[largest]);
            parent = largest;
        }
    }

    void recursiveHeapify(int parent){
        if(parent>=vec.size()){
            return;
        }
        int largest = parent;
        int left = 2*parent + 1;
        int right = 2*parent + 2;

        if(left<vec.size() && vec[left]<vec[largest]){
            largest = left;
        }
        if(right<vec.size() && vec[right]<vec[largest]){
            largest = right;
        }
        if(largest==parent){
            return;
        }
        swap(vec[largest],vec[parent]);
        recursiveHeapify(largest);
    }
    void pop(){
        if(empty()){
            return;
        }
        swap(vec[0],vec[vec.size()-1]);
        vec.pop_back();
        // iterativeHeapify();
        recursiveHeapify(0);
    }
    int top(){
        return empty() ? -1:vec[0];
    }
    bool empty(){
        return vec.size()==0;
    }
};
int main(){
    Heap h;
    h.push(10);
    h.push(20);
    h.push(4);
    h.push(40);
    // h.pop();
    // h.pop();
    cout<<h.top();
}