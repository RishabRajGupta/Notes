#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void printarr(int arr[],int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
// void jbjkhb(std::vector<int> &arr2, std::vector<int> &occurence)
// {
//     for(int i = 0; i < arr2.size(); i++){
//         int count = 1;
//         for(int j = i+1; j < arr2.size(); j++){
//             if(arr2[j] == arr2[i]){
//                 count++;
//                 arr2.erase(arr2.begin()+j);
//             }
//         }
//         occurence.push_back(count);
//     }
// }

void swap(int arr[], int n, int m){
    int x = arr[n];
    arr[n] = arr[m];
    arr[m] = x;
}

int main(){

    //1.Swap Alternate
    int arr1[5] = {1,2,3,4,5};
    int length = sizeof(arr1)/sizeof(arr1[0]);
    
    if(length % 2 != 0){
        length--;
    }
    for(int i = 0; i < length; i += 2){
        swap(arr1, i, i+1);
    }
    printarr(arr1,5);

    //2.Unique Number of Occurences
    vector<int> arr2 = {1,2,2,1,3,1};
    vector<int> occurence;
    
    for(int i = 0; i < arr2.size(); i++){
        int count = 1;
        for(int j = i+1; j < arr2.size(); j++){
            if(arr2[j] == arr2[i]){
                count++;
                arr2.erase(arr2.begin()+j);
            }
        }
        occurence.push_back(count);
    }

    bool repeat = false;
    for(int i = 0; i < occurence.size(); i++){
        for(int j = i+1; j < occurence.size(); j++){
            if(occurence[i] == occurence[j]){
                repeat = true;
            }
        }
    }
    cout << repeat << endl;

    //3.Find Duplicate
    int arr3[7] = {1,2,3,3,4,5,6};
    
    int i = 0;
    int j = 1;
    int ans = 0;

    while(i < 7 || j < 7){
        if(i == 6){
            ans = ans ^ arr3[i];
        }
        else{
            ans = ans ^ arr3[i] ^ j;
        }
        i++; j++;
    }
    cout << ans << endl;

    //4.Find All Duplicates
    vector<int> arr4 = {1,2,3,4,3,2};
    vector<int> dup(7,0);
    //duplicate array used to count frequency of elements
    
    for(int i : arr4){
        dup[i]++;
    }

    for(int i = 0; i < 7; i++){
        if(dup[i] != 0 && dup[i] != 1){
            cout << i << " ";
        }
    }
    cout << endl;

    //5.Intersection of Two Arrays
    vector<int> arr5 = {1,2,5,6,7,9};
    vector<int> vrr = {1,2,3,5,6,8,9};

    int time = 0;
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            if(arr5[i] == vrr[j]){
                cout << arr5[i] << " ";
                arr5[j] = INT_MIN;
                break;
            }
            else if(arr5[i] < vrr[j]){
                break;
            }
        }
    }
    cout << endl;

    //More Optimised Solution
    vector<int> arr_5 = {1,2,5,6,7,9};
    vector<int> vrr2 = {1,2,3,5,6,8,9};

    int i1 = 0;
    int j1 = 0;
    while(i1 < 6 && j1 < 7){
        if(arr_5[i1] == vrr2[j1]){
            cout << arr_5[i1] << " ";
            i1++;
            j1++;
        }
        else if(arr_5[i1] < vrr2[j1]){
            i1++;
        }
        else{
            j1++;
        }
    }
    cout << endl;

    //6.Two Sum
    vector<int> arr6 = {1,2,3,4,5};
    int n = 5;

    int i2 = 0;
    int j2 = 1;
    while(i2 < 5 && j2 < 5){
        if(arr6[i2] + arr6[j2] == n){
            cout << arr6[i2] << " " << arr6[j2] << endl;
            i2++;
            j2 = i2+1;
        }
        else if(2*arr6[i2]>= n){
            break;
        }
        else if(j == 4){
            i2++;
            j2 = i2+1;
        }
        else{
            j2++;
        }
    }

    //7.Sort 0 and 1 - in one single traversal
    vector<int> arr7 = {0,1,0,0,1,0,1,1};
    int i3 = 0;
    int j3 = 7;
    while(i3 != j3){
        if(arr7[i3] == 0){
            i3++;
        }
        if(arr7[j3] == 1){
            j3--;
        }
        if(arr7[i3] == 1 && arr7[j3] == 0){
            //swap
            int nv = arr7[i3];
            arr7[i3] = arr7[j3];
            arr7[j3] = nv;
        }
    }
    for(int i : arr7){
        cout << i << " ";
    }
    cout << endl;
    
    //8.Sort 0, 1 and 2 - in one single traversal
    vector<int> arr8 = {1,0,1,1,0,2,2,0,1,0};
    
    int low = 0;
    int mid = 0;
    int high = arr8.size()-1;

    while(mid <= high){
        if(arr8[mid] == 0){
            swap(arr8[mid],arr8[low]);
            mid++;
            low++;
        }
        else if(arr8[mid] == 1){
            mid++;
        }
        else if(arr8[mid] == 2){
            swap(arr8[mid], arr8[high]);
            high--;
        }
    }

    for(int i : arr8){
        cout << i << " ";
    }
    cout << endl;
}
