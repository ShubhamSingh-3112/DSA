#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

int partition(vector<int>& arr, int start, int end) {
    int i = start - 1;
    int pivot = arr[end];

    for(int j = start; j <= end - 1; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[end]);
    return i;
}

int randomizedPartition(vector<int>& arr, int start, int end) {
    int randomIndex = start + rand() % (end - start + 1);

    swap(arr[randomIndex], arr[end]);  // Move random pivot to end

    return partition(arr, start, end);
}

void quickSort(vector<int>& arr, int start, int end) {
    if(start >= end) {
        return;
    }

    int pivotIdx = randomizedPartition(arr, start, end);

    quickSort(arr, start, pivotIdx - 1);
    quickSort(arr, pivotIdx + 1, end);
}

int main() {
    srand(time(0)); // Seed random number generator

    vector<int> arr = {6, 3, 7, 5, 2, 4, 1};

    quickSort(arr, 0, arr.size() - 1);

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}