#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
    vector<int> arr = {1,6,3,4,2,5};

    for(int i = 1; i < arr.size(); i++){
        int temp = arr[i];
        
        int j = i-1;
        while(arr[j]>temp && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp; 
    }

    for(int i : arr){
        cout << i << " ";
    }
}