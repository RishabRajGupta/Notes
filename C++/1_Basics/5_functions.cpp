//functions

#include<iostream>
#include <cmath>
using namespace std;

//function declaration
void printName(string name){
    for(int i = 0; i < 5; i++){
        cout << name << endl;
    }
}

//inline functions
inline int sum(int x, int y, int z = 5){
    return x + y;
    //same syntax as regular functions but faster excecution internally
}

//1.Sum Of Digits
void sumDigits(int n){
    int sum = 0;
    while(n>0){
        sum += n - 10*(n/10);
        n /= 10;
    }
    cout << "Sum of digits : " << sum << endl;
}

//2.Decimal -> Binary
void decBin(int n){
    int a = 1;
    while(n>0){
        a *= 10;
        a += n%2;
        n /= 2;
    }
    //reversing a
    int b = 0;
    while(a > 1){
        b *= 10;
        b += a - 10*(a/10);
        a /= 10;
    }
    cout << "Binary : " << b << endl;
}

//3.Binary -> Decimal
void binDec(int n){
    int a = 0;
    int power = 0;
    while(n > 0){
        a += (n - 10*(n/10))*pow(2,power);
        n /= 10;
        power++;
    }
    cout << "Decimal : " << a << endl;
}
//Funciton Call
//Pass By Value
void increment(int n){
    n++;
}
//Pass by Reference
void increment2(int &n){
    n++;
}

int main() {

    //funtion call
    printName("Rishab");
    sumDigits(123456789);
    decBin(238);
    binDec(11101110);

    int n = 5;
    increment(n);
    cout << n << endl;
    increment2(n);
    cout << n << endl;
}