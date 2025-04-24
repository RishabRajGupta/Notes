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

void towerOfHanoi(int n, char s, char h, char d){
    if(n == 1){
        cout << "Disk : " << n << " from " << s << " to " << d << endl;
        return;
    }
    towerOfHanoi(n-1, s, d, h);
    cout << "Disk : " << n << " from " << s << " to " << d << endl;
    towerOfHanoi(n-1, h, s, d);
}

int main() {

    towerOfHanoi(3, 'S', 'H', 'D');
        
}