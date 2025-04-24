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

//Function Overloading

class A{
    public:

        //no of parameters
        int func(int a){
            return a+a;
        }
        int func(int a, int b){
            return a+b;
        }

        //data type of parameters
        int func1(int a){
            return a+a;
        }
        char func1(char a){
            return a;
        }

        //order of parameters
        int func2(int a, float b){
            return a+b;
        }
        int func2(float a, int b){
            return a+b;
        }

        //with default parameters
        int func3(int a, int b = 10){
            return a+b;
        }
        double func3(double a){
            return a+a;
        }

};

//Operator Overloading

class Complex{
    public:
        double real;
        double img;

        Complex(double r = 0, double i = 0){
            this->real = r;
            this->img = i;
        }
        
        Complex operator+ (Complex &obj){
            return Complex(this->real + obj.real, this->img + obj.img);
        }
};

//Function Overriding

class parent{
    public:
        virtual void print(){
            cout << "Parent" << endl;
        }
};
class child: public parent{
    public:
        void print() override {
            cout << "Child" << endl;
        }
};

int main() {

    //Compile-time Polymorphism
    
    //function overloading
    A a;
    cout << a.func(10) << " " << a.func(10,20) << endl;
    cout << a.func1(10) << " " << a.func1('a') << endl;
    cout << a.func2(10.5, 20) << " " << a.func2(20, 10.5) << endl;
    cout << a.func3(10) << " " << a.func3(10, 20) << endl;

    //operator overloading
    Complex c1(5,7);
    Complex c2(2,3);
    Complex c3 = c1 + c2;
    cout << c3.real << " + " << c3.img << "i" << endl;

    //Run-time Polymorphism

    //funciton overriding
    child b;
    b.print();


}