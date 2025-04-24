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
int merge(int *arr, int start, int mid, int end){
    vector<int> merged(end-start+1);
    int i = start; int j = mid+1; int k = 0; int inversions = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            merged[k++] = arr[i++];
        } else {
            merged[k++] = arr[j++];
            inversions += (mid+1 - i);
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

    return inversions;
}

int mergeSort(int *arr, int start, int end){
    if(start == end){
        return 0;
    }

    int inversions = 0;
    
    int mid = start + (end-start)/2;
    inversions += mergeSort(arr, start, mid);
    inversions += mergeSort(arr, mid+1, end);

    inversions += merge(arr, start, mid, end);

    return inversions;
}

int main() {

    int arr[5] = {1, 2, 4, 5, 3};
    int inversions = mergeSort(arr, 0, 4);
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    } cout << endl;
    cout << "Inversions : " << inversions << endl;
}
