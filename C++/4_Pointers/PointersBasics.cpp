#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cstring>
using namespace std;

int main(){

    string a = "Hello";
    string *ptr = &a;
    cout << "Address : " << ptr << endl;
    cout << "Value : " << *ptr << endl;
    cout << "Value size : " << sizeof(a) << endl;
    cout << "Pointer size : " << sizeof(ptr) << endl;

    //assigning a new value
    string b = "World"; 
    ptr = &b;
    cout << "Address : " << ptr << endl;
    cout << "Value : " << *ptr << endl;

    //updating via pointers
    int num = 5;
    int *p = &num;
    cout << "num : " << ++(*p) << endl;
    cout << "num : " << num << endl; 

    //null pointer
    int *p1 = nullptr;

    //copying to a new pointer
    int *q = p;
    cout << p << " - " << q << endl;
    cout << *p << " - " << *q << endl;

    //Arrays
    int arr[5] = {1,3,5};
    cout << arr << " - " << &arr[0] << endl;    //same
    cout << *arr << " " << *arr + 1 << " " << *(arr + 1) << endl;
    cout << 1[arr] << endl;
    
    //char arrays
    char ab[6] = "abcde";
    //size = 6 to store NULL at the end
    
    char *c = &ab[0];
    cout << ab << " - " << c << endl;

    char x = 'a';
    c = &x;
    cout << x << " - " << c << endl;
    
    //double pointers
    num = 5;
    int *ptr1 = &num;
    int **ptr2 = &ptr1;             //double pointer
    int ***ptr3 = &ptr2;            //triple pointer and so on..

    cout << num << " " << *ptr1 << " " << **ptr2 << " " << ***ptr3 << endl;
}