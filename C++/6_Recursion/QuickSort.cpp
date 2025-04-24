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

int partition(int* arr, int s, int e){

    int pivot = arr[s];
    
    //count elements less than pivot
    int count = 0;
    for(int i = 1; i <= e; i++){
        count = (arr[i] <= pivot) ? count+1 : count;
    }

    int pos = s+count;

    //swap pivot from the element at pos position
    swap(arr[s],arr[pos]);

    //handle left and right parts
    while(s < pos && e > pos){
        while(arr[s] < arr[pos]){
            s++;
        }
        while(arr[e] > arr[pos]){
            e--;
        }
        if(arr[s] > arr[pos] && arr[e] < arr[pos]){
            swap(arr[s++], arr[e--]);
        }
    }

    return pos;
    
}

void quicksort(int* arr, int s, int e){

    //base case
    if(s >= e){
        return;
    }

    //partition
    int p = partition(arr, s, e);

    //left part sort
    quicksort(arr, s, p-1);

    //right part sort
    quicksort(arr, p+1, e);

}

int main(){

    int arr[] = {8, 5, 9, 6, 2, 10};
    int n = 5;

    quicksort(arr, 0, n-1);

    for(int i : arr){
        cout << i << " ";
    }   cout << endl;

    
}