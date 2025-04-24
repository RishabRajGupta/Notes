//variable basics, datatypes, output, operators

#include <iostream>                                 //iostream library

using namespace std;

int main(){                                         //main block of code
    cout << "Hello World" << endl;                  //printing funtion
    cout << "Hello" << endl << "World" << "\n";     //endl - newline funtion
    
    //variable declaration - data type + ( variable name )
    int num = 20;
    char ch = '@';
    string name = "hello";
    long long a = 56;
    cout << name << endl;
    
    //Operators
    //1.Arithmetic 
    cout << 23 + 5 << endl;
    cout << 23 - 5 << endl;
    cout << 23 * 5 << endl;
    cout << 23 / 5 << endl;                         // int/int = int 
    cout << 23 % 5 << endl;

    //2.Relational
    cout << (23 < 5) << endl;
    cout << (23 > 5) << endl;
    cout << (23 <= 5) << endl;
    cout << (23 >= 5) << endl;
    cout << (23 != 5) << endl;
    cout << (23 == 5) << endl;
    
    //3.Assignment(only '=' )
    int num2 = 12;

    //4.Logical
    cout << ((12 > 10) && (12 > 15)) << endl;       //AND
    cout << ((12 > 10) || (12 > 15)) << endl;       //OR
    cout << !(12 > 15) << endl;                     //NOT

    //5.Bitwise
    cout << (5 & 3) << endl;                        //Bitwise AND
    cout << (5 | 3) << endl;                        //Bitwise OR
    cout << (5 ^ 3) << endl;                        //Bitwise XOR
    cout << (~5) << endl;                           //Bitwise NOT
    cout << (5 << 1) << endl;                       //Left Shift by 1
    cout << (5 >> 1) << endl;                       //Right Shift by 1
    
    //Compound Assignment Operators
    int x = 3;
    x += 2;                                         //x = x + 2 = 3 + 2
    x /= 1;                                         //x = x / 2 = 3 / 2
    x &= 5;                                         //x = x & 5 = 3 & 5
    x ^= 3;                                         //x = x ^ 5 = 3 ^ 5
    
    return 0;
}