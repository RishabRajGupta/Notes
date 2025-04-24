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

//Inheritance

class human{
    
    private:
        int start = 10000;

        int getStart(){
            return this->start;
        }

    protected:
        int end = 20000;

        int getEnd(){
            return this->end;
        }

    public:
        string name;
        int age;

        void printNameAge(){
            cout << name << " " << age << end;
        }
    
};

//public inheritance
class male: public human{          //single level inheritance
    public:
        string x = "male";
        int getEnd(){               //protected -> protected
            return end;
        }
};

//protected inheritance
class female: private human{
    public:
        string x = "female";
        int getEnd(){               //protected -> private
            return end;
        }
};

//multi inheritance
class son: public male, public female{
    public:
        string x = "son";
};

int main() {

    //Inheritance

    male B;
    cout << B.getEnd() << endl;
    
    son C;
    cout << C.x << " " << C.male::x << " " << C.female::x << endl;
        
}