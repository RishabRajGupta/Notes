#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vec;

    for(int i = 0; i < 5; i++){
        vec.push_back(i+1);
    }

    sort(vec.begin(),vec.end());                //sorting        
    
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
}