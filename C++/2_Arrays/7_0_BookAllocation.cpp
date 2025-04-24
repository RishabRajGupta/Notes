#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int check(vector<int> &arr, int mid, int students){
    int currsum = 0;
    int count = 1;
    for(int i = 0; i < arr.size(); i++){
        if(currsum+arr[i] <= mid){
            currsum += arr[i];
        }
        else{
            count++;
            if(count > students || arr[i] > mid){
                return -1;
            }
            currsum = arr[i];
        }
    }
    return 0;
}

int smallestmaxsum(vector<int> arr, int students){
    int start = 0;
    int end = 0;
    int ans = 0;
    for(int i : arr){
        end += i;
    }

    while(start <= end){
        int mid = start + (end - start)/2;
        int x = check(arr,mid,students);
        if(x == 0){
            ans = mid;
            end = mid-1;
        }
        else if(x == -1){
            start = mid+1;
        }
    }
    return ans;
}

int main() {

    vector<int> arr = {12, 34, 67, 90};
    cout << smallestmaxsum(arr, 2);
    
}