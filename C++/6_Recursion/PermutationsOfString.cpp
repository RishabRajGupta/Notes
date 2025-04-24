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

void solve(string input, int index, vector<string> &ans){

    if(index >= input.length()){
        ans.push_back(input);
        return;
    }

    //swapping
    for(int i = index; i < input.length(); i++){
        swap(input[index], input[i]);
        solve(input, index+1, ans);
        swap(input[index], input[i]);
    }
}

vector<string> permutations(string input){
    vector<string> ans;
    int index = 0;

    solve(input, index, ans);

    return ans;
}

int main(){

    string input = "abc";
    vector<string> ans = permutations(input);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }   cout << endl;
}