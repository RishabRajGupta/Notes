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

class car{
    
    private:
        string engine_no;
        int horsepower;
        int model = 10;                       
    
    public:
        void start(){
            //code to start the car...
            cout << "Car started" << endl; //user output
        }
        void stop(){
            //code to stop the car...
            cout << "Brakes Applied" << endl; //user output
        }

};

int main() {
    
    car Honda;
    Honda.start();
    Honda.stop();

}