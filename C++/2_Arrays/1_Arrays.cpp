#include <iostream>
#include <string>
using namespace std;

//array & function
void printarray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

//linear search
bool linearsearch(int arr[], int size, int find){
    for(int i = 0; i < size; i++){
        if(arr[i] == find){
            return true;
        }
    }
    return false;
}

int main(){
    int numbers[5] = {1, 2, 3, 4, 5};                   //array declaration with data
    string names[2];                                    //array declarration without data
    names[0] = "Rishab";                                //data insertion
    names[1] = "Raj Gupta";

    for(int i = 0; i < sizeof(names)/sizeof(names[0]); i++){                         //iteration in array
        cout << names[i] << " ";
    }
    cout << endl;

    cout << sizeof(names)/sizeof(names[0]) << endl;         //returns size of an array
    cout << addressof(names[0]) << endl;                    //returns actual memory address
    cout << &names[1] << endl;                              //returns actual address only when not overloaded

    //linear search
    int arr[5] = {1,2,3,4,5};
    int find;
    cout << "Enter a Number (1-5) : ";
    cin >> find;
    cout << linearsearch(arr,5,find) << endl;
    
    //2D Arrays
    int arr2[2][3]= {{1,2,3},{4,5,6}};
    
}