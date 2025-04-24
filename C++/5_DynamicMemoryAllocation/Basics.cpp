#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cstring>
using namespace std;

int update(int &n){
    n++;
}

int main(){

    //Reference variables
    int num = 5;
    int &num2 = num;        //ref var
    num++; num2++;
    cout << num << endl;

    num = 5;
    num2 = num;
    update(num2);           //pass by reference
    cout << num << endl;

    //Dynamic Memory Allocation
    int *i = new int(5);
    int *arr = new int[5];
    arr[0] = 2;

    delete i;
    delete [] arr;

    //2D array
    int n = 5;                      //rows
    int **vrr = new int*[n];        //array of pointers
    
    for(int i = 0; i < n; i++){
        vrr[i] = new int[3];        //columns
    }
    
    //use it same as regular 2d array
    int count = 11;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            vrr[i][j] = count++;
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 3; j++){
            cout << vrr[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < n; i++){
        delete [] vrr[i];           //delete array assigned to pointer
    }
    delete [] vrr;

    




}