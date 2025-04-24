#include <iostream>
#include <limits.h>
using namespace std;

void printarray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int arr[], int i, int j){
    
}

int main(){
    
    int arr[10] = {2,4,3,5,6,7,3,7,8,-1};
    int size = sizeof(arr)/sizeof(arr[0]);

    //1.Minimum number in an array
    int min = INT_MAX;
    for(int i = 0; i < size; i++){
        if(min > arr[i]){
            min = arr[i];
        }
    }
    cout << "Minimum value : " << min << endl;

    cout << "Array : ";
    printarray(arr,10);

    //2.Reversing an Array

    for(int i = 0; i < size/2; i++){
        int a = arr[i];
        arr[i] = arr[size-i-1] + arr[i];
        arr[size-i-1] = arr[i] - arr[size-i-1];
        arr[i] = arr[i] - arr[size-i-1];

        //a = a+b
        //b = a-b = a+b-b = a
        //a = a-b = a+b-b = a+b-a = b
    }
    cout << "Reversed : ";
    printarray(arr,10);
    
    //3.Extreme print in an Array
    //print 1 element from left then 1 from right and so on

    int arr2[5] = {10, 20, 30, 40, 50};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    cout << "Array : ";
    printarray(arr2,5);
    cout << "Extreme : ";

    for(int i = 0; i <= size2/2; i++){
        if(i != size2-1-i){
            cout << arr2[i] << " " << arr2[size2-1-i] << " ";
        }
        else{
            cout << arr2[i] << " ";
        }
    }
    cout << endl;

    //4.Find Unique
    //In a certain array every element occurs twice 
    //Find the element which occurs once

    int arr3[] = {1,2,4,3,3,4,6,7,1,6,7};
    int unique = 0;
    for(int i = 0; i < 11; i++){
        unique ^= arr3[i];
    }
    cout << "Unique Element : " << unique << endl;

    //5.Print all pairs
    
    for(int i = 0, j = 0; j < 5; i++){
        cout << "(" << arr2[j] << "," << arr2[i] << ")" << endl;
        if(i == 4){
            j++;
            i = -1;
        }
    }

    //6.Sort 0's and 1's
    
    int zeroes = 0;
    int ones = 0;
    int arr4[12] = {1,0,1,1,1,0,0,0,0,1,0,1};

    for(int i = 0; i < 12; i++){
        if(arr4[i] == 0){
            zeroes++;
        }
        else if(arr4[i] == 1){
            ones++;
        }
    }
    cout << zeroes << " " << ones << endl;
    for(int i = 0; i < zeroes; i++){
        arr4[i] = 0;
    }
    for(int j = zeroes; j < 12; j++){
        arr4[j] = 1;
    }
    printarray(arr4,12);

    //7.Shift array element by one - Right Shift
    
    int arr5[5] = {1,2,3,4,5};
    int lastElement = arr5[4];
    
    for(int i = 4; i > 0; i--){
        arr5[i] = arr5[i-1];
    }
    arr5[0] = lastElement;
    printarray(arr5,5);
}