#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int booksum(vector<int> &arr, int students){
    
    int start = 0;
    int end = 0;
    for(int i : arr){
        if(i > start){
            start = i;
        }
        end += i;
    }
    
    
    
    int ans = end;

    while(start <= end){
        int mid = start + (end - start)/2;
        
        //check for mid value
        int count = 1;
        int pagesum = 0;
        for(int i : arr){
            pagesum += i;
            if(pagesum > mid){
                count++;
                pagesum = i;
            }
        }

        //update ans, start and end
        if(count <= students){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}

int main(){

    vector<int> arr = {19, 9, 30, 22, 7};
    cout << booksum(arr, 1) << endl;
    cout << booksum(arr, 2) << endl;
    cout << booksum(arr, 3) << endl;
    cout << booksum(arr, 4) << endl;
    cout << booksum(arr, 5) << endl;
}