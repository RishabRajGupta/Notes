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

void solve(vector<int> arr, vector<int> output, int index, vector<vector<int> >& ans){

    //base case
    if(index >= arr.size()){
        ans.push_back(output);
        return;
    }

    //exclude
    solve(arr, output, index+1, ans);

    //include
    int el = arr[index];
    output.push_back(el);
    solve(arr, output, index+1, ans);

}

vector<vector<int> > powerset(vector<int> arr){
    
    vector<vector<int> > ans;
    vector<int> output;
    int index = 0;

    solve(arr, output, index, ans);

    return ans;
}

int main(){

    vector<int> arr;
    arr.push_back(1); arr.push_back(2); arr.push_back(3);

    vector<vector<int> > power = powerset(arr);

    for(int i = 0; i < power.size(); i++){
        for(int j = 0; j < power[i].size(); j++){
            cout << power[i][j] << " ";
        }
        cout << endl;
    }
}