#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int minBananas(vector<int> &arr, int hours){
    int start = 0;
    int end = 0;
    for(int i : arr){
        if(end < i){
            end = i;
        }
    }

    int result;
    while(start <= end){
        int mid = start + (end-start)/2;

        int count = 0;
        for(int i : arr){
            int result = ceil((double)i/mid);
            count += result;
            if(count > hours){
                break;
            }
        }

        if(count > hours){
            start = mid+1;
        }
        else if(count <= hours){
            result = mid;
            end = mid-1;
        }
    }
    return result;
}

int main(){
    vector<int> arr = {3,6,11,7};
    cout << minBananas(arr,8) << endl;
}