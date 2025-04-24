#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

//merge two sorted arrays
void merge(int *arr, int start, int mid, int end){
    vector<int> merged(end-start+1);
    int i = start; int j = mid+1; int k = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            merged[k++] = arr[i++];
        } else {
            merged[k++] = arr[j++];
        }
    }

    //merge remaining elements
    while(i <= mid){
        merged[k++] = arr[i++];
    }
    while(j <= end){
        merged[k++] = arr[j++];
    }

    //append these values back
    k = 0;
    while(start <= end){
        arr[start++] = merged[k++];
    }
}

void mergeSort(int *arr, int start, int end){
    if(start == end){
        return;
    }

    int mid = start + (end-start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, mid, end);
}

int main() {

    int arr[5] = {5, 4, 1, 2, 3};
    mergeSort(arr, 0, 5);
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    } cout << endl;
    
}














