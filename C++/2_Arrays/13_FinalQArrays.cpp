#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void printArray(vector<int> &arr){

    cout << "[ ";
    for(int i : arr){
        cout << i << " ";
    }
    cout << "]" << endl;
}

vector<int> mergeSortedArrray(vector<int> &arr, vector<int> &vrr, int n, int m){
    
    vector<int> merged;
    
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        int small = (arr[i]<=vrr[j])?arr[i++]:vrr[j++];
        merged.push_back(small);
    }

    //remaining elements
    while (i<n){
        merged.push_back(arr[i++]);
    }

    while(j<m){
        merged.push_back(vrr[j++]);
    }
    
    return merged;
}

void sortZeroes(vector<int> &arr){

    int i = 0;          //remains at 0
    for(int j = 0; j < arr.size(); j++){
        if(arr[j] != 0){
            //swap
            swap(arr[i++], arr[j]);
        }
    }
}

void Rotate(vector<int> &arr, int k){

    vector<int> temp(arr.size());

    for(int i = 0; i < arr.size(); i++){
        int index = (i+k)%(arr.size());
        temp[index] = arr[i];
    }

    arr = temp;
}

bool sorted(vector<int> &arr){
    vector<int> temp = arr;
    sort(temp.begin(), temp.end());

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] != temp[i]){
            return false;
        }
    }

    return true;
}

bool check(vector<int> &arr){
    int x = arr.size();

    while(x--){
        if(arr[0] >= arr[arr.size()-1]){
            Rotate(arr,1);
        }
        else{
            return true;
        }
    }
    return false;
}


bool check2(vector<int> &arr){
    int count = 0;

    for(int i = 1; i < arr.size(); i++){
        if(arr[i-1] > arr[i]){
            count++;
        }
    }

    if(arr[arr.size()-1] > arr[0]){
        count++;
    }

    return count == 1;
}

vector<int> arraySum(vector<int> &arr, vector<int> &vrr){

    int a = 0, b = 0;
    for(int i = 0; i < arr.size(); i++){
        a = (a*10) + arr[i];
    }
    for(int i = 0; i < vrr.size(); i++){
        b = (b*10) + vrr[i];
    }

    int x = a+b;

    vector<int> newarr;
    while(x > 0){
        newarr.push_back(x % 10);
        x /= 10;
    }
    reverse(newarr.begin(), newarr.end());
    
    return newarr;
}

int main(){

    //1.Merged Sorted Arrays
    vector<int> arr = {1,2,5,6,0,0,0};
    vector<int> vrr = {0,2,3,4,7,8,9};
    vector<int> merged = mergeSortedArrray(arr,vrr,4,7);
    printArray(merged);

    //2.Sort 0s
    vector<int> arr2 = {1,0,0,3,4,0,9};
    sortZeroes(arr2);
    printArray(arr2);
    
    //3.Rotate Array by 'k' Steps
    vector<int> arr3 = {1,2,3,4,5};
    Rotate(arr3,2);
    printArray(arr3);

    //4.Sorted & Rotated Check
    vector<int> arr4 = {4,5,1,2,3};
    vector<int> arr4copy = {4,5,1,2,3};
    cout << check(arr4) << endl;        //Method-1
    cout << check2(arr4copy) << endl;   //Method-2

    //5.Sum of Two Arrays
    vector<int> arr5 = {1,2,3};
    vector<int> vrr5 = {8,7};
    vector<int> sumarr = arraySum(arr5,vrr5);
    printArray(sumarr);

}