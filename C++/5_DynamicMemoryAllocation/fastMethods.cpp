#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cstring>
using namespace std;

//object macro
#define PI 3.14

//function macro
#define SQUARE(x) ((x) * (x))
#define PRINT(x) cout << x << endl;

//multiline macro
#define PRINT_ARRAY(arr)                \
for(int i = 0; i < arr.size(); i++){    \
    cout << arr[i] << " ";              \
}                                       \
cout << endl;

//chain macro
#define num 10
#define num2 (num + 11.5)

//global variable
int x = 10;

void func(){
    x++;
}
void func2(){
    x *= 10;
}

//inline functions & default functions
inline int maxint(int a, int b = 10){       //b -> default parameter
    return (a > b)? a:b;
}

int main(){

    func();func2();
    float a = PI * SQUARE(5) + num2 + x;
    PRINT(a);

    vector<int> arr = {10, 14, 2, 24, 54};
    PRINT_ARRAY(arr);

    cout << maxint(5,10) << endl;
    cout << maxint(12) << endl;             //b not passed

    const int var = 5;                      //const variable

} 