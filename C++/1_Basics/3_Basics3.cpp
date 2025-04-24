//conditional statements, loops

#include <iostream>
using namespace std;

int main(){
    int x = 10;
    
    //if-else-if
    if(x % 2 == 0){
        cout << "Even Number!" << endl;
    }
    else if (x % 2 == 1){
        cout << "Odd Number!" << endl;
    }
    else{
        cout << "Invalid Data!";
    }

    switch(x % 2){
        case 0 : 
                cout << "Even!" << endl;
                cout << "Switch terminated" << endl;
                break;
        case 1 :
                cout << "Odd!" << endl;
                cout << "Switch terminated" << endl;
                break;
        default :
                cout << "No Cases Operated!" << endl;
                break;

    }

    //for loop
    for(int i = 1; i <= 100; i++){                  //printing all even numbers between 1 & 100
        if(i % 2 == 0){
            cout << i << " ";
        }
        else{
            continue;
        }
    }
    cout << " FOR" << endl;

    //while loop
    int a = 1;
    while(a <= 100){
        if(a % 2 == 0){
            cout << a << " ";
        }
        a++;
    }
    cout << " WHILE" << endl;

    //do-while loop
    int b = 1;
    do{
        if(b % 2 == 0){
            cout << b << " ";
        }
        b++;
    }while(b <= 100);
    cout << "DO-WHILE" << endl;
}