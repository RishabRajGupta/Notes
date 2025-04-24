//variable types, manipulators, input/output

#include <iostream>
#include <iomanip>                                  //contains manipulators
#include <string>

using namespace std;

int a = 10;                                         //global variable

int main(){

    //local variables
    static int num1 = 190;                          //static
    const int num2 = 200;                           //constants (not a variable)
    int num3 = 210;                                 //instance variable

    //input/output streams
    int x;
    cout << "Enter a number : ";
    cin >> x;
    cout << "You have entered " << x << "." << flush << endl;
    cerr << "Done" << endl;

    //string input
    string name, fullname;
    cout << "Enter first name : ";                  //one word inpout
    cin >> name;
    cout << "Enter full name : ";                   //full line input
    getline(cin >> ws, fullname);                   //ws is used to remove unnecessary whitespaces
    cout << "Name : " << name << " --- Full Name : " << fullname << endl;

    //important manipulators

    //1. setw, setfill, setprecision, 
    cout << setw(10) << setfill('*') << fixed << showbase << setprecision(4) << oct << 255 << endl;
    cout << setw(4) << "Rishab" << endl;            //setw only sets minimum width
    cout << hex << showbase << 255 << endl;
    cout << oct << showbase << 255 << endl;
    cout << uppercase << hex << 255 << endl;

    return 0;
}