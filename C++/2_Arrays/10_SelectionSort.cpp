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

    for(int i = 0; i < arr.size(); i++){
        
        int min = i;
        for(int j = i+1; j<arr.size(); j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        
        swap(arr,i,min);
    }

    for(int i : arr){
        cout << i << " ";
    }
}