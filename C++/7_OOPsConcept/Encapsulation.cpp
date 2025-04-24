#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

//Encapsulation

class student{
    
    private:
        string name;
        int roll;
        int age = 10;                       //fully encapsulated - all members private
    
    public:
        void getAge(){
            cout << "Age : " << this->age << endl;
        }

};

int main() {
    
    //Encapsulation

    student A;
    A.getAge();
        
}