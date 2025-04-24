#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> &arr, int key){
    int start = 0;
    int end = arr.size();
    int mid = start + (end-start)/2;

    while(true){
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            end = mid-1;
        }
        else if(arr[mid] < key){
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
}

int main() {

    //Binary Search
    vector<int> arr = {1,2,3,4,5,6,7,8};

    cout << "Found at : " << binarySearch(arr, 4) << endl;


    //1.First & last occurence of an element
    vector<int> arr1 = {0,0,1,2,2,2,2,3,4,4,4,5,6,6};

    int key = 2;
    int start = 0;
    int end = arr1.size();
    int mid = start + (end-start)/2;
    bool first = false, last = false;
    while(!first || !last){
        if(arr1[mid] == key){
            if(arr1[mid-1] == key && !first){
                end = mid-1;
            }
            else if(arr1[mid-1] != key && !first){
                first = true;
                cout << "First : " << mid << endl;
                end = arr1.size();
            }
            else if(arr1[mid+1] == key && !last){
                start = mid+1;
            }
            else if(arr1[mid+1] != key && !last){
                last = true;
                cout << "Last : " << mid << endl;
            }
        }
        else if(arr1[mid] > key){
            end = mid-1;
        }
        else if(arr1[mid] < key){
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }

    //2.Total Number of Occurence
    //for same set above - Occurence = last-first+1

    //3.Peak Element in Mountain Array
    vector<int> arr3 = {0,1,3,3,4,3,2,0};

    start = 0;
    end = arr3.size();
    mid = start + (end-start)/2;

    int peak = INT_MIN;

    while(true){
        if(arr3[mid] > arr3[mid-1] && arr3[mid]>arr3[mid+1]){
            cout << "Peak : " << arr3[mid] << endl;
            cout << "index : " << mid << endl;
            break;
        }
        else if(arr3[mid] < arr3[mid-1]){
            end = mid-1;
        }
        else if(arr3[mid] < arr3[mid+1]){
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }

    // IMPORTANT!!
    //4.Find Pivot in Sorted Rotated Array
    vector<int> arr4 = {7,8,9,1,2,3,7};

    int s = 0;
    int e = arr4.size()-1;

    //using start value
    while(s < e){
        int m = s + (e-s)/2;
        if(arr4[m] >= arr4[0]){
            s = m+1;
        }
        else{
            e = m;
        }
    }
    cout << "Pivot : " << arr4[s] << endl;

    //using end value :
    //replace 0 with arr4.size()-1 in line 105

    //5.Search in Sorted Rotated Array
    
    vector<int> arr5 = {5,6,7,1,2,3,4};
    key = 3;
    s = 0;
    e = arr5.size()-1;

    //find pivot
    while(s < e){
        int m = s + (e-s)/2;
        if(arr5[m] >= arr5[0]){
            s = m+1;
        }
        else{
            e = m;
        }
    }
    int p = s;
    //compare for smaller array
    if(arr5[p] <= key && key <= arr5[arr5.size()-1]){
        //smaller sub array
        vector<int> arr5s(arr5.begin()+p,arr5.end());
        cout << "Found at : " << binarySearch(arr5s,key)+p << endl;
    }
    //for larger array
    else{
        //larger sub array
        vector<int> arr5l(arr5.begin(),arr5.begin()+p);
        cout << "Found at : " << binarySearch(arr5l,key) << endl;

    }

    //6.Square Root using Binary Search
    int num = 25;

    //Search Space
    vector<int> arr6;
    for(int i = 1; i < (int)(num/2); i++){
        arr6.push_back(i);
    }

    s = 0;
    e = arr6.size()-1;

    while(s < e){
        int m = s + (e-s)/2;
        int x = (int)num/arr6[m];
        if(x == arr6[m]){
            cout << arr6[m] << endl;
            break;
        }
        else if(x > arr6[m]){
            s = m+1;
        }
        else if(x < arr6[m]){
            e = m;
        }
    }

    //7.Square Root Precision

    num = 37;

    //Search Space
    vector<int> arr7;
    for(int i = 1; i < (int)(num/2); i++){
        arr7.push_back(i);
    }

    float ans;
    s = 0;
    e = arr7.size()-1;
    float precision = 1;

    //Find integer value first
    while(s < e){
        int m = s + (e-s)/2;
        int x = (int)num/arr7[m];
        if(x == arr7[m]){
            ans = arr7[m];
            break;
        }
        else if(x > arr7[m]){
            s = m+1;
        }
        else if(x < arr7[m]){
            e = m;
        }
    }

    //Find decimal values
    for(int i = 0; i < 3; i++){
        precision /= 10;
        for(float j = ans+precision; j*j < num; j+=precision){
            ans = j;
        }
    }
    cout << ans << endl;

}