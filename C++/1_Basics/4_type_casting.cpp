//Type Casting

#include <iostream>
using namespace std;

int main(){

    //Type Casting
    //1.implicit conversion
    int a = 10;
    float b = 12.5;
    cout << a+b << endl;                //a(int -> float)

    char ch = 'A';                      //ascii(A) = 65
    int c = ch + 4;                     //ch (ascii -> int) = 65
    char ch2 = ch + 4;                  //a (int -> aascii) = 4
    cout << c << " " << ch2 << endl;

    //2.explicit conversion
    int result = a + (int)b;            //b (float -> int)
    cout << result << endl;

    float d = 65.85;
    cout << (char)d << endl;            //d (float -> int -> char)
}