#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void spiralPrint(vector<vector<int>> &arr2, int row, int column){
    int startrow = 0;
    int startcol = 0;
    int endrow =  row-1;
    int endcol = column-1;
    int count = 0;
    int total = row*column;

    while(count < total){
        
        //start row
        for(int i = startcol; i <= endcol; i++){
            cout << arr2[startrow][i] << " ";
            count++;
        }
        startrow++;

        //end col
        for(int i = startrow; i <= endrow; i++){
            cout << arr2[i][endcol] << " ";
            count++;
        }
        endcol--;

        //end row
        for(int i = endcol; i >= startcol; i--){
            cout << arr2[endrow][i] << " ";
            count++;
        }
        endrow--;

        //start col
        for(int i = endrow; i >= startrow; i--){
            cout << arr2[i][startcol] << " ";
            count++;
        }
        startcol++;
    }
    cout << endl;
}


void rotateBy90(vector<vector<int>> &arr, int rows, int columns){
    
    vector<vector<int>> vrr(columns,vector<int>(rows,0));
    
    int vrow = 0;
    int vcol = 0;
    
    for(int i = 0; i < columns; i++){
        vcol = 0;
        for(int j = rows-1; j >= 0; j--){
            vrr[vrow][vcol++] = arr[j][i];
        }
        vrow++;
    }

    for(int i = 0; i < vrr.size(); i++){
        for(int j = 0; j < vrr[0].size(); j++){
            cout << vrr[i][j] << " ";
        }
        cout << endl;
    }
    
}

void binarySearch(vector<vector<int>> &arr, int target){
    
    int start = 0;
    int end = arr.size()*arr[0].size();
    int col = arr[0].size();
    bool found = false;

    while(start <= end){
        int mid = start + (end - start)/2;
        int element = arr[mid/col][mid%col];

        if(target == element){
            found = true;
            cout << "Found at : " << mid/col << " " << mid%col << endl;
            break;
        }
        else if(target < element){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    if(!found){
        cout << "Not found" << endl;
    }
}

//Staircase Search
void staricaseSearch(vector<vector<int>> &arr, int target){
    
    int i = 0;
    int j = arr[0].size();
    bool found = false;

    while(i < arr.size() && j >= 0){
        
        if(arr[i][j] == target){
            found = true;
            cout << "Found at : " << i << " " << j << endl;
            break;
        }
        else if(arr[i][j] > target){
            //shift left
            j--;
        }
        else{
            //shift down
            i++;
        }
    }

    if(!found){
        cout << "Not Found" << endl;
    }
}

int main(){
    
    //Initialising
    int arr1[2][2] = { {1,2},{3,4}};
    int arr[2][3];

    //input
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            arr[i][j] = i+j;
        }
    }

    //output
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    //linear search
    int key = 3;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i][j] == key){
                cout << "Found At : " << i << " " << j << endl;
                break;
            }
        }
    }

    //Row wise sum
    int sum = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            sum += arr[i][j];
        }
        cout << "Row Sum : " << sum << endl;
        sum = 0;
    }

    //Column wise sum
    sum = 0;
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < 2; i++){
            sum += arr[i][j];
        }
        cout << "Column Sum : " << sum << endl;
        sum = 0;
    }

    //Largest row sum
    int tempSum = 0;
    sum = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            tempSum += arr[i][j];
        }
        if(tempSum > sum){
            sum = tempSum;
        }
        tempSum = 0;
    }
    cout << "Largest Row Sum : " << sum << endl;

    //Print Like a Wave - column print
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < 2; i++){
            cout << arr[i][j] << " ";
        }
    }
    cout << endl;

    //Spiral Print
    vector<vector<int>> arr2(3);
    int count = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arr2[i].push_back(count++);
        }
    }
    cout << "Array : " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Spriral : ";
    spiralPrint(arr2,3,3);

    //Rotate a Matrix by 90 degree
    cout << "Rotated Array : " << endl;
    rotateBy90(arr2, 3, 3);
    
    //binary search
    binarySearch(arr2,4);
    
    //staircase search
    vector<vector<int>> arr3 = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30} };

    staricaseSearch(arr3, 6);

}