#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int agCows(vector<int> &arr, int cows){
    sort(arr.begin(), arr.end());
    
    int start = 1;
    int end = arr[arr.size()-1]-arr[0];

    int ans;
    while(start <= end){
        int mid = start + (end-start)/2;
        
        int count = 1;
        int pos = arr[0];
        for(int i : arr){
            if(pos+mid <= i){
                count++;
                pos = i;
            }
        }

        if(count < cows){
            end = mid-1;
        }
        else{
            ans = mid;
            start = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,4,8,9};
    cout << agCows(arr,3) << endl;;
}