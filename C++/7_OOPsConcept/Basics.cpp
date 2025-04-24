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

class fighter{

    //properties
    private:            //private member
    char rank;
    
    protected:          //protected member
    int health;

    public :            //public member
    char *name;

    //constructor

    //default   - created by default
    fighter(){
        cout << "Object created!" << endl;
    }

    //parameterised
    fighter(char *name, int health, char rank = 'B'){
        this->name = name;
        this->health = health;
        this->rank = rank;
    }

    //copy constructor - created by default
    fighter(fighter& f){
        cout << "Copy Constructor called!" << endl;
        this->name = f.name;
        this->health = f.health;
        this->rank = f.rank;
    }
    //its important to pass by reference as -
    //pass by value calls this constructor again and forms an infinite loop


    //functions

    //getter
    char getRank() const {
        return rank;
    }
    int getHealth() const {
        return health;
    }

    //setter
    bool setRank(char rank){
        this->rank = rank;
        return true;
    }
    bool setHealth(int health){
        this->health = health;
        return true;
    }
    
    //other functions
    bool increaseHealth(int inc){
        this->health += inc;
        return true;
    }
    bool decreaseHealth(int dec){
        this->health -= dec;
        return true;
    }

    //static datatype and function
    static int time;
    static int returnTime(){
        return time;
    }

    //destructor
    ~fighter(){
        cout << "Object deleted - " << this->name << endl;
        delete[] name;
    }
};

int fighter::time = 60;

int main() {

    cout << endl;

    //static allocation
    fighter A;
    
    char name[10] = "King";
    A.name = name;
    A.setHealth(100);
    A.setRank('D');
    cout << A.name << " " << A.getHealth() << " " << A.getRank() << endl << endl;

    //dynamic allocation
    fighter *B = new fighter;
    
    char name2[10] = "Queen";
    (*B).name = name2;
    (*B).setHealth(80);
    (*B).setRank('C');
    cout << (*B).name << " " << (*B).getHealth() << " " << (*B).getRank() << endl;
    cout << B->name << " " << B->getHealth() << " " << B->getRank() << endl << endl;

    //using parameterised constructor
    char name3[10] = "Jack";
    fighter C(name3, 90);          //rank set by default
    cout << C.name << " " << C.getHealth() << " " << C.getRank() << endl;

    //copy constructor
    fighter Ccopy(C);
    cout << Ccopy.name << " " << Ccopy.getHealth() << " " << Ccopy.getRank() << endl << endl;

    //health, rank -> shallow copy
    //name -> deep copy

    Ccopy.name[0] = 'H';
    cout << C.name << " " << C.getHealth() << " " << C.getRank() << endl;
    cout << Ccopy.name << " " << Ccopy.getHealth() << " " << Ccopy.getRank() << endl << endl;

    //Assignment Operator
    fighter D;
    
    char name4[10] = "King";
    D.name = name4;
    D.setHealth(100);
    D.setRank('D');

    cout << D.name << " " << D.getHealth() << " " << D.getRank() << endl;
    
    fighter E;
    
    char name5[10] = "Ace";
    E.name = name5;
    E.setHealth(120);
    E.setRank('A');

    cout << E.name << " " << E.getHealth() << " " << E.getRank() << endl << endl;
    
    D = E;
    cout << E.name << " " << E.getHealth() << " " << E.getRank() << endl;
    cout << D.name << " " << D.getHealth() << " " << D.getRank() << endl  << endl;

    //static datatype and function
    cout << fighter::time << " " << fighter::returnTime() << endl;
    fighter::time = 120;
    cout << fighter::time << " " << fighter::returnTime() << endl << endl;

    //destructor
    delete B;
        
}