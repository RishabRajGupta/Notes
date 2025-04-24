#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void swap(vector<int> &arr, int i, int j){
    int x = arr[i];
    arr[i] = arr[j];
    arr[j] = x;
}

int main(){
    vector<int> arr = {1,6,3,4,2,5};
    
    for(int i = 1; i < arr.size(); i++){
        for(int j = 0; j < arr.size()-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr,j,j+1);
            }
        }
    }

    for(int i : arr){
        cout << i << " ";
    }
}